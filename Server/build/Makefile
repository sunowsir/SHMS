CC 			= gcc

PROPATH 	= ../..

TARGET 		= Server

CFLAGS 		= -g -Wall

CCFLAGS 	= -g -Wall -fPIC

LIBPATH 	= -L ${PROPATH}/lib

LIBS 		= -lpthread -lShared

INCPATH 	= -I ../include -I ${PROPATH}/lib/include

VPATH 		= ..:../src:../include:${PROPATH}/lib:${PROPATH}/lib/include

SERVER_RELY = \
			ServerConnect.o \
			dataTransmission.o \
			sendWarningInfo.o \
			heartBeat.o \
			getScriptRunInfo.o \
			runScriptAndSave.o \
			mainServer.o 





${TARGET} : ${SERVER_RELY}
	@echo "[\033[1;32mLinking\033[0m] Server"
	@${CC} ${CFLAGS} -o ${TARGET} ${SERVER_RELY} ${LIBPATH} ${LIBS}

mainServer.o : mainServer.c mainServer.h 
	@echo "[\033[1;32mBuilding\033[0m] [CC] mainServer.c"
	@${CC} -c ${CCFLAGS} ${INCPATH} $<

sendWarningInfo.o : sendWarningInfo.c sendWarningInfo.h 
	@echo "[\033[1;32mBuilding\033[0m] [CC] sendWarningInfo.c"
	@${CC} -c ${CCFLAGS} ${INCPATH} $<

getScriptRunInfo.o : getScriptRunInfo.c getScriptRunInfo.h 
	@echo "[\033[1;32mBuilding\033[0m] [CC] getScriptRunInfo.c"
	@${CC} -c ${CCFLAGS} ${INCPATH} $<

ServerConnect.o : ServerConnect.c mainServer.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] ServerConnect.c"
	@${CC} -c ${CCFLAGS} ${INCPATH} $<

runScriptAndSave.o : runScriptAndSave.c runScriptAndSave.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] runScriptAndSave.c"
	@${CC} -c ${CCFLAGS} ${INCPATH} $<

dataTransmission.o : dataTransmission.c dataTransmission.h 
	@echo "[\033[1;32mBuilding\033[0m] [CC] dataTransmission.c"
	@${CC} -c ${CCFLAGS} ${INCPATH} $<

heartBeat.o : heartBeat.c heartBeat.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] heartBeat.c"
	@${CC} -c ${CCFLAGS} ${INCPATH} $<

.PHONY: clean install uninstall

install : 
	mkdir /opt/SHMS-server/ 
	mkdir /etc/SHMS-server/
	mkdir /var/log/SHMS-server/
	touch /var/log/SHMS-server/SHMS-Server.log
	touch /etc/SHMS-server/server.pid
	cp ./Server /opt/SHMS-server/ 
	cp ../server.conf /etc/SHMS-server/
	cp ../SHMS-server.init /opt/SHMS-server/ 
	cp ../SHMS-Server.service /etc/systemd/system/
	chmod 755 /opt/SHMS-server/SHMS-server.init 
	chmod 754 /etc/systemd/system/SHMS-Server.service
	systemctl daemon-reload
	systemctl enable SHMS-Server.service
	systemctl start SHMS-Server.service 

uninstall :
	rm -rf /opt/SHMS-server/
	rm -rf /etc/SHMS-server/
	rm -rf /var/log/SHMS-server/
	systemctl stop SHMS-Server.service
	rm -rf /etc/systemd/system/SHMS-Server.service

clean : 
	@echo "[\033[1;32mClean\033[0m] Clean compile file."
	@rm -rf ${TARGET} ${SERVER_RELY}


