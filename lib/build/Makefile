CC 			= gcc
CFLAGS 		= -g -Wall -I ../include/ -I ../../Share/include/ 
VPATH 		= ..:../src:../include
MASTER_RELY = \
			sockFrame.o\
			Get_conf.o \
			StrtoInt.o \
			LinkList.o \
			Write_Pi_Log.o

libShared.so : ${MASTER_RELY}
	@echo "[\033[1;32mmake\033[0m] [LIB] libShared.so => ../"
	@${CC} -shared ${CFLAGS} ${MASTER_RELY} -l pthread -o libShared.so 
	@cp ./libShared.so ../

sockFrame.o : sockFrame.c sockFrame.h
	@echo "[\033[1;32mbuild\033[0m] [CC] sockFrame.c"
	@${CC} -c -fPIC ${CFLAGS} -l pthread $<

Get_conf.o : Get_conf.c Get_conf.h
	@echo "[\033[1;32mbuild\033[0m] [CC] Get_conf.c"
	@${CC} -c -fPIC ${CFLAGS} $<

StrtoInt.o : StrtoInt.c StrtoInt.h
	@echo "[\033[1;32mbuild\033[0m] [CC] StrtoInt.c"
	@${CC} -c -fPIC ${CFLAGS} $<

Write_Pi_Log.o : Write_Pi_Log.c Write_Pi_Log.h
	@echo "[\033[1;32mbuild\033[0m] [CC] Write_Pi_Log.c"
	@${CC} -c -fPIC ${CFLAGS} $<

LinkList.o : LinkList.c LinkList.h
	@echo "[\033[1;32mbuild\033[0m] [CC] LinkList.c"
	@${CC} -c -fPIC ${CFLAGS} $<


.PHONY: clean install uninstall

clean : 
	@echo "[\033[1;32mClean\033[0m] Clean compile file"
	@rm -rf libShared.so ${MASTER_RELY}


