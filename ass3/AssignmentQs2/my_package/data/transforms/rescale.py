# Imports
from PIL import Image
import numpy as np


class RescaleImage(object):
    '''
        Rescales the image to a given size.
    '''

    def __init__(self, output_size):
        '''
            Arguments:
            output_size (tuple or int): Desired output size. If tuple, output is
            matched to output_size. If int, smaller of image edges is matched
            to output_size keeping aspect ratio the same.
        '''
        self.output_size = output_size

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)

            Note: You do not need to resize the bounding boxes. ONLY RESIZE THE IMAGE.
        '''
        img = Image.fromarray(image)
        if isinstance(self.output_size, int):
            w, h = img.size
            new_size = (self.output_size, self.output_size*(h/w)) \
                if w < h else (self.output_size*(w/h), self.output_size)
            img = img.resize(new_size)
            return np.array(img)
        elif isinstance(self.output_size, tuple):
            img = img.resize(self.output_size)
            return np.array(img)
        elif isinstance(self.output_size,float):
            w,h = img.size
            w,h = int(w*self.output_size),int(h*self.output_size)
            img = img.resize((w,h))
            return np.array(img)