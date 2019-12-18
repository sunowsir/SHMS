CC 			= gcc

PROPATH 	= ../..

TARGET 		= Master

CFLAGS 		= -g -Wall 

CCFLAGS 	= -c -fPIC -g -Wall

LIBPATH 	= -L ${PROPATH}/lib

LIBS 		= -lpthread -lShared

INCPATH 	= -I ../include -I ${PROPATH}/lib/include

VPATH 		= ..:../src:../include:${PROPATH}/lib/include

MASTER_RELY = \
			CreateConnect.o \
			dataTransmission.o \
			masterConnect.o \
			getWarningInfo.o \
			mainMaster.o 





${TARGET} : ${MASTER_RELY}
	@echo "[\033[1;32mLinking\033[0m] Master"
	@${CC} ${CFLAGS} -o ${TARGET} ${MASTER_RELY} ${LIBPATH} ${LIBS}

mainMaster.o : mainMaster.c mainMaster.h 
	@echo "[\033[1;32mBuilding\033[0m] [CC] mainMaster.c"
	@${CC} ${CCFLAGS} ${INCPATH} $<

masterConnect.o : masterConnect.c mainMaster.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] masterConnect.c"
	@${CC} ${CCFLAGS} ${INCPATH} $<

getWarningInfo.o : getWarningInfo.c getWarningInfo.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] getWarningInfo.c"
	@${CC} ${CCFLAGS} ${INCPATH} $<

CreateConnect.o : CreateConnect.c CreateConnect.h 
	@echo "[\033[1;32mBuilding\033[0m] [CC] CreateConnect.c"
	@${CC} ${CCFLAGS} ${INCPATH} $<

dataTransmission.o : dataTransmission.c dataTransmission.h 
	@echo "[\033[1;32mBuilding\033[0m] [CC] dataTransmission.c"
	@${CC} ${CCFLAGS} ${INCPATH}  $< 



.PHONY: clean install uninstall

install : 
	mkdir /opt/SHMS-master/
	mkdir /etc/SHMS-master/
	mkdir /var/log/SHMS-master/
	touch /var/log/SHMS-master/SHMS-Master.log
	touch /etc/SHMS-master/master.pid
	cp ./Master /opt/SHMS-master/
	cp ../master.conf /etc/SHMS-master/
	cp ../SHMS-master.init /opt/SHMS-master/
	cp ../SHMS-Master.service /etc/systemd/system/
	chmod 755 /opt/SHMS-master/SHMS-master.init
	chmod 754 /etc/systemd/system/SHMS-Master.service
	systemctl daemon-reload
	systemctl enable SHMS-Master.service
	systemctl start SHMS-Master.service

uninstall : 
	rm -rf /opt/SHMS-master/
	rm -rf /etc/SHMS-master/
	rm -rf /var/log/SHMS-master/
	systemctl stop SHMS-Master.service
	rm -rf /etc/systemd/system/SHMS-Master.service

clean : 
	@echo "[\033[1;32mClean\033[0m] Clean compile file"
	@rm -rf ${TARGET} ${MASTER_RELY}


