#!/usr/bin/python

import os
import sys
import numpy as np
import matplotlib.pyplot as plt

pathA= './data/' + str(sys.argv[1]) + '/'
pathB= './data/' + str(sys.argv[2]) + '/'
pathC= './data/' + str(sys.argv[3]) + '/'


for filename in os.listdir(path):
    data
    with open(pathA+filename) as f:
        data1 = f.read()

    data1 = data1.split('\n')

    data = [row for row in data if row != ""]
    x1 = [row.split(' ')[0] for row in data]
    y1 = [row.split(' ')[1] for row in data]

    fig = plt.figure()

    ax1 = fig.add_subplot(111)


    title = filename.replace(".dat","")

    ax1.set_title(title)
    ax1.set_xlabel('Ejecuciones')
    ax1.set_ylabel('Tiempo')

    ax1.plot(x,y, c='r', label=title)


    savepath = "./grphx/todos/"

    d = os.path.dirname(savepath)
    if not os.path.exists(d):
        os.makedirs(d)

    plt.savefig(savepath+title+".png")
