import socket
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import axes3d

UDP_IP = "127.0.0.1"
UDP_PORT = 3333
sock = socket.socket( socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))
sock.settimeout(5)
fig = plt.figure(1)


####################################################################################################
####################################################################################################
####               Here starts the Main process          ###########################################
####                                                     ###########################################
####################################################################################################

fig = plt.figure(1)
ax = fig.add_subplot(111, projection='3d')

while 1:
  arr_X = []
  arr_Y = []
  arr_Z = []
  for counter in range(0,10):
    data, addr = sock.recvfrom(1024)

    CoordsUnicode = bytes.decode(data)

    CoordsNum = CoordsUnicode.split(";")
    print("Loc sent this:", CoordsNum)
    arr_X.append(int(CoordsNum[0]))
    arr_Y.append(int(CoordsNum[1]))
    arr_Z.append(int(CoordsNum[2]))

  print("This is X coord--->", arr_X )
  print("This is Y coord--->", arr_Y)
  print("This is Z coord--->", arr_Z)



  ax.plot_wireframe(arr_X,arr_Y,arr_Z)
  plt.show()











