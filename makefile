DIR_INC=./include
DIR_SRC=./src
DIR_BIN=./bin
DIR_OBJ=./obj

TARGET=${DIR_BIN}/main
SRC=${wildcard ${DIR_SRC}/*.cpp}
OBJ=${patsubst %.cpp,${DIR_OBJ}/%.o,${notdir ${SRC}}}

CC=g++
CFLAGS=-g -Wall -std=c++11 -I${DIR_INC}

${TARGET}:${OBJ}
	${CC} ${OBJ} -o $@

${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	find ${DIR_OBJ} -name *.o -exec rm -rf {} \;
	rm -rf ${DIR_BIN}/*
