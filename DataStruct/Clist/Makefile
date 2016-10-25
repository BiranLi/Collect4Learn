_INC_  = ./include

INC_PATH=$(addprefix -I , $(_INC_))

#MACRO_DEF = -DHAVE_CONFIG_H -DMTA_USE_PTHREADS

ifeq ($(DEBUG),Y)
CCFLAG = -g -O2 -c -pthread -Wall -Werror -fstack-protector-all -rdynamic
SPLIT_DBG=objcopy --only-keep-debug mguard mguard.dbg
TRIM_BIN=objcopy --strip-debug mguard
else
CCFLAG = -g -c -pthread -Wall -Werror -fstack-protector-all -rdynamic
SPLIT_DBG=
TRIM_BIN=
endif

SRC_C  = array.c
SRC_C += main.c

#SRC_CPP  = mguard.cpp

#SRC_CPP11  = mguard_heartbeat.cpp

OBJECTS_C = $(patsubst %.c, %.o, $(SRC_C))

OBJECTS_CPP  = $(patsubst %.cpp, %.o, $(SRC_CPP))

OBJECTS_CPP11  = $(patsubst %.cpp, %.o, $(SRC_CPP11))

_LIB_ =
_LIB_ += pthread

LIBS = $(addprefix -l , $(_LIB_))

LIBS += -Wl,-rpath=/usr/local/lib #-Wl,-rpath=../lib

#_LIB_PATH_  = ../output

LIB_PATH = $(addprefix -L , $(_LIB_PATH_))

vpath %.c ./src
vpath %.cpp ./src
#vpath %.cpp ../public/src

all : array_test
	@echo $(OBJECTS_C)
	@echo $(OBJECTS_CPP)

$(OBJECTS_CPP11) : %.o : %.cpp
	g++ $(CCFLAG) -std=c++11 $(INC_PATH) $^ -o $@

$(OBJECTS_CPP) : %.o : %.cpp
	g++ $(CCFLAG) $(INC_PATH) $^ -o $@

$(OBJECTS_C) : %.o : %.c
	gcc $(CCFLAG) $(MACRO_DEF) $(INC_PATH) $^ -o $@

array_test :  $(OBJECTS_CPP) $(OBJECTS_CPP11) $(OBJECTS_C)
	g++ $(MACRO_DEF) -o $@ $^ $(LIB_PATH) $(LIBS)
	$(SPLIT_DBG)
	$(TRIM_BIN)

.PHONY : clean
clean :
	-rm -f *.o array_test
