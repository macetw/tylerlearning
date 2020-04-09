#!/usr/bin/env python3

import exifread
import glob
from PIL import Image

targetdir = "sampleimages"

files = glob.glob(f'{targetdir}/*.jpg')

for filename in files:
  with open(filename, 'rb') as imagefile:
      tags = exifread.process_file(imagefile)
      angle = 0
      if "Image Orientation" in tags:
          if 6 in tags["Image Orientation"].values:
              angle = 270
          elif 3 in tags["Image Orientation"].values:
              angle = 180
          elif 8 in tags["Image Orientation"].values:
              angle = 90

          if not angle == 0:
              imagefile.close()
              im = Image.open(filename)
              outim = im.rotate(angle, expand=True)
              im.close()
              outim.save(filename)
