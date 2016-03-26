#!/usr/bin/python

from scipy.optimize import curve_fit
import os
import sys
import numpy as np
import matplotlib.pyplot as plt

def q(t, a, b, c):
    return a * t * t + b * t + c


path= './data/' + str(sys.argv[1]) + '/quad/'

for filename in os.listdir(path):

    with open(path+filename) as f:
        data = f.read()

    data = data.split('\n')

    data = [row for row in data if row != ""]
    x = [row.split(' ')[0] for row in data]
    y = [row.split(' ')[1] for row in data]

    porg,

    fig = plt.figure()

    ax1 = fig.add_subplot(111)


    title = filename.replace(".dat","")

    ax1.set_title(title)
    ax1.set_xlabel('Ejecuciones')
    ax1.set_ylabel('Tiempo')

    ax1.plot(x,y, c='r', label=title)


    savepath = path.replace("data","grphx")

    d = os.path.dirname(savepath+title+".png")
    if not os.path.exists(d):
        os.makedirs(d)

    plt.savefig(savepath+title+".png")
