#!/usr/bin/python

import os
import sys

path= './bin/'

for filename in os.listdir(path):
    d = os.path.dirname(path+filename)
    execl(d)
