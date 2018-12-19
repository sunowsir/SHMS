CC=gcc
CFLAGS=-g -Wall -o 

NOW_DIR=$(shell pwd)
FATHER_DIR=$(shell echo `cd ../ && pwd`)
BUILD_DIR=${NOW_DIR}/Build
HEAD_DIR=${NOW_DIR}/include
CODE_DIR=${NOW_DIR}/src
SHARE_HEAD_DIR=${FATHER_DIR}/Share/include/
SHARE_CODE_DIR=${FATHER_DIR}/Share/src/

SERVER_RELY = ${BUILD_DIR}/PackageFrame.o \
			${BUILD_DIR}/Write_Pi_Log.o \
			${BUILD_DIR}/sockFrame.o \
			${BUILD_DIR}/Get_conf.o \
			${BUILD_DIR}/StrtoInt.o \
			${BUILD_DIR}/ServerConnect.o \
			${BUILD_DIR}/dataTransmission.o \
			${BUILD_DIR}/sendWarningInfo.o \
			${BUILD_DIR}/heartBeat.o \
			${BUILD_DIR}/getScriptRunInfo.o \
			${BUILD_DIR}/runScriptAndSave.o \
			${BUILD_DIR}/mainServer.o 

Server : ${SERVER_RELY}
	${CC} ${CFLAGS} Server ${SERVER_RELY} -lpthread

${BUILD_DIR}/mainServer.o : ${NOW_DIR}/mainServer.c ${HEAD_DIR}/mainServer.h 
	${CC} -c ${CFLAGS} ${BUILD_DIR}/mainServer.o ${NOW_DIR}/mainServer.c

${BUILD_DIR}/sendWarningInfo.o : ${CODE_DIR}/sendWarningInfo.c ${HEAD_DIR}/sendWarningInfo.h 
	${CC} -c ${CFLAGS} ${BUILD_DIR}/sendWarningInfo.o ${CODE_DIR}/sendWarningInfo.c

${BUILD_DIR}/getScriptRunInfo.o : ${CODE_DIR}/getScriptRunInfo.c ${HEAD_DIR}/getScriptRunInfo.h 
	${CC} -c ${CFLAGS} ${BUILD_DIR}/getScriptRunInfo.o ${CODE_DIR}/getScriptRunInfo.c

${BUILD_DIR}/ServerConnect.o : ${CODE_DIR}/ServerConnect.c ${HEAD_DIR}/mainServer.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}/ServerConnect.o ${CODE_DIR}/ServerConnect.c -lpthread

${BUILD_DIR}/runScriptAndSave.o : ${CODE_DIR}/runScriptAndSave.c ${HEAD_DIR}/runScriptAndSave.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}/runScriptAndSave.o ${CODE_DIR}/runScriptAndSave.c -lpthread

${BUILD_DIR}/dataTransmission.o : ${CODE_DIR}/dataTransmission.c ${HEAD_DIR}/dataTransmission.h 
	${CC} -c ${CFLAGS} ${BUILD_DIR}/dataTransmission.o ${CODE_DIR}/dataTransmission.c 

${BUILD_DIR}/heartBeat.o : ${CODE_DIR}/heartBeat.c ${HEAD_DIR}/heartBeat.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}/heartBeat.o ${CODE_DIR}/heartBeat.c 

${BUILD_DIR}/Get_conf.o : ${SHARE_CODE_DIR}/Get_conf.c ${SHARE_HEAD_DIR}/Get_conf.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}/Get_conf.o ${SHARE_CODE_DIR}/Get_conf.c 

${BUILD_DIR}/StrtoInt.o : ${SHARE_CODE_DIR}/StrtoInt.c ${SHARE_HEAD_DIR}/StrtoInt.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}/StrtoInt.o ${SHARE_CODE_DIR}/StrtoInt.c 

${BUILD_DIR}/sockFrame.o : ${SHARE_CODE_DIR}/sockFrame.c ${SHARE_HEAD_DIR}/sockFrame.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}/sockFrame.o ${SHARE_CODE_DIR}/sockFrame.c 

${BUILD_DIR}/Write_Pi_Log.o : ${SHARE_CODE_DIR}/Write_Pi_Log.c ${SHARE_HEAD_DIR}/Write_Pi_Log.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}/Write_Pi_Log.o ${SHARE_CODE_DIR}/Write_Pi_Log.c

${BUILD_DIR}/PackageFrame.o : ${SHARE_CODE_DIR}/PackageFrame.c ${SHARE_HEAD_DIR}/PackageFrame.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}/PackageFrame.o ${SHARE_CODE_DIR}/PackageFrame.c

.PHONY: clean

clean : 
	rm -rf Server ${SERVER_RELY}


