# Imports
from PIL import Image
import numpy as np


class CropImage(object):
    '''
        Performs either random cropping or center cropping.
    '''

    def __init__(self, shape, crop_type='center'):
        '''
            Arguments:
            shape: output shape of the crop (h, w)
            crop_type: center crop or random crop. Default: center
        '''
        self.h, self.w = shape[0], shape[1]
        self.crop_type = crop_type

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''
        img = Image.fromarray(image)
        w, h = img.size
        c = np.array([w/2, h/2])
        c += np.array([0, 0]) if self.crop_type == 'center' else np.array(
            [np.random.randint(-self.w/2, self.w/2), np.random.randint(-self.h/2, self.h/2)])
        l, r, t, b = c[0]-self.w/2, c[0] + \
            self.w/2, c[1]-self.h/2, c[1]+self.h/2
        l, r = np.clip([l, r], 0, w)
        t, b = np.clip([t, b], 0, h)
        img = img.crop((l, t, r, b))
        return(np.array(img))
