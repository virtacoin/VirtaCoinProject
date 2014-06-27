#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/virtacoin.png
ICON_DST=../../src/qt/res/icons/virtacoin.ico
convert ${ICON_SRC} -resize 16x16 virtacoin-16.png
convert ${ICON_SRC} -resize 32x32 virtacoin-32.png
convert ${ICON_SRC} -resize 48x48 virtacoin-48.png
convert virtacoin-16.png virtacoin-32.png virtacoin-48.png ${ICON_DST}

