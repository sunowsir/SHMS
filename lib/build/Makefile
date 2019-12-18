CC 			= gcc

LIBS 		= -pthread

TARGET 		= libshared.so

INCPATH 	= -I ../include 

CFLAGS 		= -shared -g -Wall  

CCFLAGS 	= -c -fPIC -g -Wall 

VPATH 		= ..:../src:../include

LIB_RELY = \
			sockFrame.o\
			Get_conf.o \
			StrtoInt.o \
			LinkList.o \
			Write_Pi_Log.o



${TARGET} : ${LIB_RELY}
	@echo "[\033[1;32mmake\033[0m] [LIB] libshared.so => ../"
	@${CC} ${CFLAGS} ${LIB_RELY} ${LIBS} -o ${TARGET}
	@cp ./${TARGET} ../

sockFrame.o : sockFrame.c sockFrame.h
	@echo "[\033[1;32mbuild\033[0m] [CC] sockFrame.c"
	@${CC} ${CCFLAGS} ${INCPATH} $<

Get_conf.o : Get_conf.c Get_conf.h
	@echo "[\033[1;32mbuild\033[0m] [CC] Get_conf.c"
	@${CC} ${CCFLAGS} ${INCPATH} $<

StrtoInt.o : StrtoInt.c StrtoInt.h
	@echo "[\033[1;32mbuild\033[0m] [CC] StrtoInt.c"
	@${CC} ${CCFLAGS} ${INCPATH} $<

Write_Pi_Log.o : Write_Pi_Log.c Write_Pi_Log.h
	@echo "[\033[1;32mbuild\033[0m] [CC] Write_Pi_Log.c"
	@${CC} ${CCFLAGS} ${INCPATH} $<

LinkList.o : LinkList.c LinkList.h
	@echo "[\033[1;32mbuild\033[0m] [CC] LinkList.c"
	@${CC} ${CCFLAGS} ${INCPATH} $<


.PHONY: clean install uninstall

clean : 
	@echo "[\033[1;32mClean\033[0m] Clean compile file"
	@-rm -rf ${TARGET} ${LIB_RELY}


