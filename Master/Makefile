CC=gcc

CFLAGS=-g -Wall -o 

BUILDDIR=./Build/

Master_RELY=${BUILDDIR}PackageFrame.o  ${BUILDDIR}Write_Pi_Log.o  ${BUILDDIR}sockFrame.o  ${BUILDDIR}Get_conf.o ${BUILDDIR}StrtoInt.o  ${BUILDDIR}LinkList.o  ${BUILDDIR}listenGetIP.o  ${BUILDDIR}dataTransmission.o  ${BUILDDIR}masterConnect.o  ${BUILDDIR}mainMaster.o 

.PHONY: clean

Master : ${Master_RELY}
	${CC} ${CFLAGS} Master ${Master_RELY} -lpthread

${BUILDDIR}mainMaster.o : ./mainMaster.c ./include/mainMaster.h 
	${CC} -c ${CFLAGS} ${BUILDDIR}mainMaster.o mainMaster.c

${BUILDDIR}masterConnect.o : ./include/masterConnect.c ./include/mainMaster.h
	${CC} -c ${CFLAGS} ${BUILDDIR}masterConnect.o ./include/masterConnect.c -lpthread

${BUILDDIR}listenGetIP.o : include/lisenGetIP.c include/lisenGetIP.h 
	${CC} -c ${CFLAGS} ${BUILDDIR}listenGetIP.o ./include/lisenGetIP.c -lpthread

${BUILDDIR}dataTransmission.o : ./include/dataTransmission.c ./include/dataTransmission.h 
	${CC} -c ${CFLAGS} ${BUILDDIR}dataTransmission.o ./include/dataTransmission.c 

${BUILDDIR}LinkList.o : ./include/LinkList.c ./include/LinkList.h
	${CC} -c ${CFLAGS} ${BUILDDIR}LinkList.o ./include/LinkList.c 

${BUILDDIR}Get_conf.o : ../includeShare/Get_conf.c ../includeShare/Get_conf.h
	${CC} -c ${CFLAGS} ${BUILDDIR}Get_conf.o ../includeShare/Get_conf.c 

${BUILDDIR}StrtoInt.o : ../includeShare/StrtoInt.c ../includeShare/StrtoInt.h
	${CC} -c ${CFLAGS} ${BUILDDIR}StrtoInt.o ../includeShare/StrtoInt.c 

${BUILDDIR}sockFrame.o : ../includeShare/sockFrame.c ../includeShare/sockFrame.h
	${CC} -c ${CFLAGS} ${BUILDDIR}sockFrame.o ../includeShare/sockFrame.c 

${BUILDDIR}Write_Pi_Log.o : ../includeShare/Write_Pi_Log.c ../includeShare/Write_Pi_Log.h
	${CC} -c ${CFLAGS} ${BUILDDIR}Write_Pi_Log.o ../includeShare/Write_Pi_Log.c

${BUILDDIR}PackageFrame.o : ../includeShare/PackageFrame.c ../includeShare/PackageFrame.h
	${CC} -c ${CFLAGS} ${BUILDDIR}PackageFrame.o ../includeShare/PackageFrame.c

clean : 
	rm -rf Master ${Master_RELY}
