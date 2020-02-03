#!/bin/sh
xwd > $1.xwd
convert $1.xwd $1.png
