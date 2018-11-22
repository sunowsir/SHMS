CC=gcc

CFLAGS=-g -Wall -o 

Master_RELY=PackageFrame.o Write_Pi_Log.o sockFrame.o Get_conf.o StrtoInt.o LinkList.o listenGetIP.o dataTransmission.o  masterConnect.o mainMaster.o 

.PHONY: clean

Master : ${Master_RELY}
	gcc ${CFLAGS} Master ${Master_RELY} -lpthread

mainMaster.o : ./mainMaster.c ./include/mainMaster.h 
	gcc -c ${CFLAGS} mainMaster.o mainMaster.c

masterConnect.o : ./include/masterConnect.c ./include/mainMaster.h
	gcc -c ${CFLAGS} masterConnect.o ./include/masterConnect.c -lpthread

listenGetIP.o : include/lisenGetIP.c include/lisenGetIP.h 
	gcc -c ${CFLAGS} listenGetIP.o ./include/lisenGetIP.c -lpthread

dataTransmission.o : ./include/dataTransmission.c ./include/dataTransmission.h 
	gcc -c ${CFLAGS} dataTransmission.o ./include/dataTransmission.c 

LinkList.o : ./include/LinkList.c ./include/LinkList.h
	gcc -c ${CFLAGS} LinkList.o ./include/LinkList.c 

Get_conf.o : ../includeShare/Get_conf.c ../includeShare/Get_conf.h
	gcc -c ${CFLAGS} Get_conf.o ../includeShare/Get_conf.c 

StrtoInt.o : ../includeShare/StrtoInt.c ../includeShare/StrtoInt.h
	gcc -c ${CFLAGS} StrtoInt.o ../includeShare/StrtoInt.c 

sockFrame.o : ../includeShare/sockFrame.c ../includeShare/sockFrame.h
	gcc -c ${CFLAGS} sockFrame.o ../includeShare/sockFrame.c 

Write_Pi_Log.o : ../includeShare/Write_Pi_Log.c ../includeShare/Write_Pi_Log.h
	gcc -c ${CFLAGS} Write_Pi_Log.o ../includeShare/Write_Pi_Log.c

PackageFrame.o : ../includeShare/PackageFrame.c ../includeShare/PackageFrame.h
	gcc -c ${CFLAGS} PackageFrame.o ../includeShare/PackageFrame.c

clean : 
	rm -rf Master ${Master_RELY}
