CC=gcc
CFLAGS=-g -Wall -o 

NOW_DIR=$(shell pwd)/
FATHER_DIR=$(shell echo `cd ../ && pwd`)
BUILD_DIR=${NOW_DIR}/Build/
HEAD_DIR=${NOW_DIR}/include/
CODE_DIR=${NOW_DIR}/src/
SHARE_HEAD_DIR=${FATHER_DIR}/Share/include/
SHARE_CODE_DIR=${FATHER_DIR}/Share/src/

MASTER_RELY = \
			${BUILD_DIR}Write_Pi_Log.o \
			${BUILD_DIR}sockFrame.o \
			${BUILD_DIR}Get_conf.o \
			${BUILD_DIR}StrtoInt.o \
			${BUILD_DIR}LinkList.o \
			${BUILD_DIR}CreateConnect.o \
			${BUILD_DIR}dataTransmission.o \
			${BUILD_DIR}masterConnect.o \
			${BUILD_DIR}getWarningInfo.o \
			${BUILD_DIR}mainMaster.o 

Master : ${MASTER_RELY}
	${CC} ${CFLAGS} Master ${MASTER_RELY} -lpthread

${BUILD_DIR}mainMaster.o : ${NOW_DIR}mainMaster.c ${HEAD_DIR}mainMaster.h 
	${CC} -c ${CFLAGS} ${BUILD_DIR}mainMaster.o ${NOW_DIR}mainMaster.c

${BUILD_DIR}masterConnect.o : ${CODE_DIR}masterConnect.c ${HEAD_DIR}mainMaster.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}masterConnect.o ${CODE_DIR}masterConnect.c -lpthread

${BUILD_DIR}getWarningInfo.o : ${CODE_DIR}getWarningInfo.c ${HEAD_DIR}getWarningInfo.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}getWarningInfo.o ${CODE_DIR}getWarningInfo.c -lpthread

${BUILD_DIR}CreateConnect.o : ${CODE_DIR}CreateConnect.c ${HEAD_DIR}CreateConnect.h 
	${CC} -c ${CFLAGS} ${BUILD_DIR}CreateConnect.o ${CODE_DIR}CreateConnect.c -lpthread

${BUILD_DIR}dataTransmission.o : ${CODE_DIR}dataTransmission.c ${HEAD_DIR}dataTransmission.h 
	${CC} -c ${CFLAGS} ${BUILD_DIR}dataTransmission.o ${CODE_DIR}dataTransmission.c 

${BUILD_DIR}LinkList.o : ${CODE_DIR}LinkList.c ${HEAD_DIR}LinkList.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}LinkList.o ${CODE_DIR}LinkList.c 

${BUILD_DIR}Get_conf.o : ${SHARE_CODE_DIR}Get_conf.c ${SHARE_HEAD_DIR}Get_conf.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}Get_conf.o ${SHARE_CODE_DIR}Get_conf.c 

${BUILD_DIR}StrtoInt.o : ${SHARE_CODE_DIR}StrtoInt.c ${SHARE_HEAD_DIR}StrtoInt.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}StrtoInt.o ${SHARE_CODE_DIR}StrtoInt.c 

${BUILD_DIR}sockFrame.o : ${SHARE_CODE_DIR}sockFrame.c ${SHARE_HEAD_DIR}sockFrame.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}sockFrame.o ${SHARE_CODE_DIR}sockFrame.c 

${BUILD_DIR}Write_Pi_Log.o : ${SHARE_CODE_DIR}Write_Pi_Log.c ${SHARE_HEAD_DIR}Write_Pi_Log.h
	${CC} -c ${CFLAGS} ${BUILD_DIR}Write_Pi_Log.o ${SHARE_CODE_DIR}Write_Pi_Log.c

.PHONY: clean install uninstall

install : 
	mkdir /opt/SHMS-master/
	mkdir /etc/SHMS-master/
	mkdir /var/log/SHMS-master/
	touch /var/log/SHMS-master/SHMS-Master.log
	touch /etc/SHMS-master/master.pid
	cp ./Master /opt/SHMS-master/
	cp ./master.conf /etc/SHMS-master/
	cp ./SHMS-master.init /opt/SHMS-master/
	cp ./SHMS-Master.service /etc/systemd/system/
	chmod 755 /opt/SHMS-master/SHMS-master.init
	chmod 754 /etc/systemd/system/SHMS-Master.service
	systemctl daemon-reload
	systemctl enable SHMS-Master.service
	systemctl start SHMS-Master.service

update : 
	make uninstall
	cp ${NOW_DIR}/master.conf ../../
	cp ../Server/server.conf ../../
	cd ../../
	rm -rf ./SHMS/
	git clone https://github.com/sunowsir/SHMS.git
	cd ${NOW_DIR}
	mv ../../master.conf ${NOW_DIR}
	mv ../../server.conf ../Server/
	make clean 
	make 
	make install 

uninstall : 
	rm -rf /opt/SHMS-master/
	rm -rf /etc/SHMS-master/
	rm -rf /var/log/SHMS-master/
	systemctl stop SHMS-Master.service
	rm -rf /etc/systemd/system/SHMS-Master.service

clean : 
	rm -rf Master ${MASTER_RELY}


