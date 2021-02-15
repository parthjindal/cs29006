# Imports
from PIL import ImageDraw, Image
from PIL import ImageFont


def plot_boxes(image=None, preds: list = None):
    image = Image.fromarray(image)
    d = ImageDraw.Draw(image)
    boxes = preds[0]
    pred_class = preds[1]
    fnt = ImageFont.truetype("Pillow/Tests/fonts/FreeMono.ttf", 25)

    for i, box in enumerate(boxes[:5]):
        d.rectangle(tuple(box), outline="black", width=2)
        d.text((box[0][0], box[0][1]), pred_class[i],
               font=fnt, stroke_width=1, fill="black")
    return image
