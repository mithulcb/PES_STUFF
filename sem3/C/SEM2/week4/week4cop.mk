a.exe:week4c.o week4c1.o
gcc week4c.o week4c1.o
week4c.o:week4c.c week4c1.h
gcc -c week4c.c
week4c1.o:week4c1.c week4c1.h
gcc -c week4c1.c