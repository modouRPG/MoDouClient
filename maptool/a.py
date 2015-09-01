#!/bin/python
#coding:utf-8

import os

CONF_FILE='./m1.conf'
PIC='dest1.png'

line_num = 0
for line in file(CONF_FILE, 'r').readlines():
    line = line.strip()
    line_num = line_num + 1
    if len(line) == 0:
        continue

    if line[0] == '#':
        continue

    if line_num == 1:
        (width, height) = line.split('x', 2)
        cmd = 'convert -size %dx%d xc:none %s' % (int(width), int(height), PIC)
        os.system(cmd)
    else:
        (px, py, pic) = line.split(' ', 3)
        cmd = 'composite -geometry +%d+%d %s %s %s' % (int(px), int(py), pic, PIC, PIC)
        os.system(cmd)
