from PIL import Image, ImageFilter
import numpy as np

class BlurImage(object):
    '''
        Applies Gaussian Blur on the image.
    '''

    def __init__(self, radius):
        '''
            Arguments:
            radius (int): radius to blur
        '''
        self.radius = radius
        # Write your code here

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL Image)

            Returns:
            image (numpy array or PIL Image)
        '''
        img = Image.fromarray(image)
        img = img.filter(ImageFilter.BoxBlur(self.radius))
        return(np.array(img))