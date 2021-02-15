#Imports
from PIL import Image
import numpy as np

class FlipImage(object):
    '''
        Flips the image.
    '''

    def __init__(self, flip_type='horizontal'):
        '''
            Arguments:
            flip_type: 'horizontal' or 'vertical' Default: 'horizontal'
        '''
        self.flip_type = Image.FLIP_LEFT_RIGHT if flip_type == 'horizontal' else Image.FLIP_TOP_BOTTOM
        # Write your code here

        
    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''
        img = Image.fromarray(image)
        img = img.transpose(self.flip_type)
        return(np.array(img))
        # Write your code here

       