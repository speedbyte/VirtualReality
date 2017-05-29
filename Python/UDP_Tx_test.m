
%This is a script for testing UDP connection

u = udp('127.0.0.1',3333);
u.InputBufferSize = 1024;
fopen(u);
%fwrite(u,65:74)
%FakeCoords = [31,31,33;32,32,33;33,33,33;34,34,33;35,35,33;35,34,33;35,33,33;35,32,34;35,31,34;36,32,35;36,33,36;37,34,37;38,35,38]

while (1) 
 %Loc = fread(u,10)
FakeCoords = ['1;','1;','3']
fwrite(u,FakeCoords);

FakeCoords = ['2;','2;','3']
fwrite(u,FakeCoords);

FakeCoords = ['3;','3;','3']
fwrite(u,FakeCoords);

FakeCoords = ['4;','4;','3']
 fwrite(u,FakeCoords);

FakeCoords = ['5;','5;','4']
fwrite(u,FakeCoords);

FakeCoords = ['6;','6;','5']
fwrite(u,FakeCoords);

FakeCoords = ['5;','6;','6']
fwrite(u,FakeCoords);

FakeCoords = ['4;','7;','7']
fwrite(u,FakeCoords);

FakeCoords = ['3;','8;','8']
fwrite(u,FakeCoords);

FakeCoords = ['2;','9;','9']
fwrite(u,FakeCoords);

    
 




end
fclose(u)

