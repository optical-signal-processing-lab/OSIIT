import socket
from threading import Lock, Thread
from time import sleep

import matplotlib.pyplot as plt
import numpy as np

def myplot(figure,ax):
    global startwl,stopwl,data_new, referenceLevel, logScale
    global terminal, info_arrive, lock
    print("plot start")
    while not terminal:
        while info_arrive:
            ax.clear()
            ax.set_ylim(referenceLevel-9*logScale,referenceLevel+logScale)
            plt.subplots_adjust(left=0.1,right=0.9,top=0.9,bottom=0.1)
            ax.set_xlabel('wavelength/nm')
            ax.set_ylabel('power/dBm')
            x=np.linspace(startwl*1e9,stopwl*1e9,len(data_new))
            if len(x)!=1:
                interval=x[1]-x[0]
                maxPower=np.max(data_new)
                maxWL=np.argmax(data_new)
            else:
                interval=0
                maxPower=0
                maxWL=0
            line1=ax.plot(x,data_new,linewidth=0.8,color='black')
            ax.set_title("interval={:.4f}nm\nmaxPower={:.2f}dBm in {:.4f}nm".format(interval,maxPower,x[maxWL]))
            figure.canvas.draw()
            figure.canvas.flush_events()

            with lock:
                info_arrive=False
        sleep(0.5)
    print("plot exit")

def infoProc(info):
    global startwl,stopwl,data_new
    global referenceLevel, logScale
    parmlist=info.split(";")
    if len(parmlist) == 3:
        startwl=float(parmlist[0])
        stopwl=float(parmlist[1])
        data=parmlist[2].split(",")
        data_new=[float(i) for i in data]
    if len(parmlist) == 2:
        referenceLevel=float(parmlist[0])
        logScale=float(parmlist[1])

def recv(sock):
    global terminal, info_arrive
    while not terminal:
        data,address=sock.recvfrom(8192)
        info=data.decode('ASCII')

        if(info=='quit\0'):
            print("break")
            terminal=True
            break
        infoProc(info)
        with lock:
            info_arrive=True
    print("thread exit")

if __name__=='__main__':
    startwl=0
    stopwl=0
    data_new=[0]
    referenceLevel=-5
    logScale=10
    
    terminal=False
    info_arrive=False
    lock=Lock()

    plt.ion()
    figure,ax=plt.subplots(figsize=(8,6))

    sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    sock.bind(('127.0.0.1',8888))
    
    p = Thread(target=recv,args=(sock,))
    p.start()

    try:
        myplot(figure,ax)
    except KeyboardInterrupt:
        msg='quit\0'.encode('ASCII')
        sock.sendto(msg,('localhost',8888))
        
    p.join()
    sock.close()
