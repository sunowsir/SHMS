CC 			= gcc
CFLAGS 		= -g -Wall -I ../include/ -I ../../Share/include/ 
VPATH 		= ../:../src:../include/:../../Share/src/:../../Share/include/
MASTER_RELY = \
			Write_Pi_Log.o \
			sockFrame.o \
			Get_conf.o \
			StrtoInt.o \
			LinkList.o \
			CreateConnect.o \
			dataTransmission.o \
			masterConnect.o \
			getWarningInfo.o \
			mainMaster.o 

Master : ${MASTER_RELY}
	@echo "[\033[1;32mLinking\033[0m] Master"
	@${CC} ${CFLAGS} ${MASTER_RELY} -l pthread -o Master 

mainMaster.o : mainMaster.c mainMaster.h 
	@echo "[\033[1;32mBuilding\033[0m] [CC] mainMaster.c"
	@${CC} -c ${CFLAGS} $<

masterConnect.o : masterConnect.c mainMaster.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] masterConnect.c"
	@${CC} -c ${CFLAGS} -l pthread $<

getWarningInfo.o : getWarningInfo.c getWarningInfo.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] getWarningInfo.c"
	@${CC} -c ${CFLAGS} -l pthread $<

CreateConnect.o : CreateConnect.c CreateConnect.h 
	@echo "[\033[1;32mBuilding\033[0m] [CC] CreateConnect.c"
	@${CC} -c ${CFLAGS} -l pthread $<

dataTransmission.o : dataTransmission.c dataTransmission.h 
	@echo "[\033[1;32mBuilding\033[0m] [CC] dataTransmission.c"
	@${CC} -c ${CFLAGS} $< 

LinkList.o : LinkList.c LinkList.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] LinkList.c"
	@${CC} -c ${CFLAGS} $<

Get_conf.o : Get_conf.c Get_conf.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] Get_conf.c"
	@${CC} -c ${CFLAGS} $<

StrtoInt.o : StrtoInt.c StrtoInt.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] StrtoInt.c"
	@${CC} -c ${CFLAGS} $<

sockFrame.o : sockFrame.c sockFrame.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] sockFrame.c"
	@${CC} -c ${CFLAGS} $<

Write_Pi_Log.o : Write_Pi_Log.c Write_Pi_Log.h
	@echo "[\033[1;32mBuilding\033[0m] [CC] Write_Pi_Log.c"
	@${CC} -c ${CFLAGS} $<

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
	@rm -rf Master ${MASTER_RELY}


