from my_package.model import ObjectDetectionModel
from my_package.data import Dataset
from my_package.analysis import plot_boxes
from my_package.data.transforms import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage
import numpy as np
import matplotlib.pyplot as plt


def experiment(annotation_file, detector, transforms, outputs):
    '''
        Function to perform the desired experiments

        Arguments:
        annotation_file: Path to annotation file
        detector: The object detector
        transforms: List of transformation classes
        outputs: path of the output folder to store the images
    '''

    # Create the instance of the dataset.
    dataset = Dataset(
        annotation_file, transforms)

    for i, data in enumerate(dataset):
        img = data["image"]
        preds = detector(img)
        img = img*255
        img = np.array(img.transpose(1, 2, 0), dtype=np.uint8)
        print(f"Annotating Image {i}")
        img = plot_boxes(img,preds)
        img.save(f"{outputs}/{i}.jpg")


def experiment2(annotation_file, detector, outputs, exp_name):

    def getdata(transforms):
        dataset = Dataset(
            annotation_file, transforms)
        return dataset

    transforms = [[], [FlipImage()], [BlurImage(1)], [RescaleImage(2.0)], [
        RescaleImage(0.5)], [RotateImage(-90)], [RotateImage(45)]]

    rows = 2
    columns = 4
    fig = plt.figure()
    axes = []
    for i, transform in enumerate(transforms):
        dataset = getdata(transform)
        img = dataset[3]["image"]
        preds = detector(img)
        img = img*255
        img = np.array(img.transpose(1, 2, 0), dtype=np.uint8)
        print(f"Annotating Image {exp_name} {i}")
        img = plot_boxes(img,preds)
        img.save(f"{outputs}/{exp_name}_{i}.jpg")
        axes.append(fig.add_subplot(rows, columns, i+1))
        axes[-1].set_title(f"Subplot {i+1}")
        plt.imshow(img)
    fig.tight_layout()
    plt.savefig(f"{outputs}/{exp_name}.jpg")


def main():
    detector = ObjectDetectionModel()
    experiment('./data/annotations.jsonl', detector,
               [], "outputs/exp_1")
    experiment2('./data/annotations.jsonl', detector, "outputs/exp_2", "Analysis")


if __name__ == '__main__':
    main()
