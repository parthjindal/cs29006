import json
from PIL import Image
import numpy as np


class Dataset(object):
    '''
        A class for the dataset that will return data items as per the given index
    '''

    def __init__(self, annotation_file: str, transforms: list = None):
        '''
            Arguments:
            annotation_file: path to the annotation file
            transforms: list of transforms (class instances)
                        For instance, [<class 'RandomCrop'>, <class 'Rotate'>]
        '''
        self.transforms = transforms
        with open(annotation_file, 'r') as file:
            self.annotations = [json.loads(x) for x in file]

    def __len__(self):
        '''
            return the number of data points in the dataset
        '''
        return(len(self.annotations))

    def __getitem__(self, idx: int) -> np.ndarray:
        '''
            return the dataset element for the index: "idx"
            Arguments:
                idx: index of the data element.

            Returns: A dictionary with:
                image: image (in the form of a numpy array) (shape: (3, H, W))
                gt_bboxes: N X 5 array where N is the number of bounding boxes, each 
                            consisting of [class, x1, y1, x2, y2]
                            x1 and x2 lie between 0 and width of the image,
                            y1 and y2 lie between 0 and height of the image.

            You need to do the following, 
            1. Extract the correct annotation using the idx provided.
            2. Read the image and convert it into a numpy array (wont be necessary
                with some libraries). The shape of the array would be (3, H, W).
            3. Scale the values in the array to be with [0, 1].
            4. Create a dictonary with both the image and annotations
            4. Perform the desired transformations.
            5. Return the transformed image and annotations as specified.
        '''
        img_ann = self.annotations[idx]
        img = Image.open(img_ann['img_fn'])
        gt_bboxes = [[x["category_id"]]+x["bbox"] for x in img_ann["bboxes"]]
        img = np.array(img)
        for transform in self.transforms:
            img = transform(img)
        img = img/255  # scale
        img = img.transpose(2, 0, 1)  # transpose(h,w,3) -> (3,h,w)
        return {
            "image": img,
            "gt_boxxes": gt_bboxes
        }
