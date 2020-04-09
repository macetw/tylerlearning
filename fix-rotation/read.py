#!/usr/bin/env python3

import exifread
import glob

targetdir = "sampleimages"
tagname = "Image Orientation"

files = glob.glob(f'{targetdir}/*.jpg')

for filename in files:
  with open(filename, 'rb') as imagefile:
      tags = exifread.process_file(imagefile)
      if tagname in tags:
          print("%s: (%s) %s" % (filename, tags[tagname].values[0], tags[tagname]))
      else:
          print("%s: no orientation tag" % filename)
