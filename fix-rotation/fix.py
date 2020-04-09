#!/usr/bin/env python3

import exifread
import glob

targetdir = "sampleimages"

files = glob.glob(f'{targetdir}/*.jpg')

for filename in files:
  with open(filename, 'rb') as imagefile:
      tags = exifread.process_file(imagefile)
      for tag in tags.keys():
          if tag == "Image Orientation":
          # if tag not in ('JPEGThumbnail', 'TIFFThumbnail', 'Filename', 'EXIF MakerNote', 'MakerNote SpecialMode'):
              print("%s: %s" % (filename, tags[tag]))
