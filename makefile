DIR_INC=./include
DIR_SRC=./src
DIR_BIN=./bin
DIR_OBJ=./obj

PATH_GRAPH_ITE=graph/iterator
PATH_GRAPH_DIJKSTRA=graph/dijkstra
PATH_SORT=sort

TARGET=${DIR_BIN}/main
SRC=${wildcard ${DIR_SRC}/*.cpp} \
	${wildcard ${DIR_SRC}/${PATH_SORT}/*.cpp}
SRC_GRAPH_ITE=${wildcard ${DIR_SRC}/${PATH_GRAPH_ITE}/*.cpp}
SRC_GRAPH_DIJKSTRA=${wildcard ${DIR_SRC}/${PATH_GRAPH_DIJKSTRA}/*.cpp}

OBJ=${patsubst %.cpp,${DIR_OBJ}/%.o,${notdir ${SRC}}} \
	${patsubst %.cpp,${DIR_OBJ}/${PATH_GRAPH_ITE}/%.o,${notdir ${SRC_GRAPH_ITE}}} \
	${patsubst %.cpp,${DIR_OBJ}/${PATH_GRAPH_DIJKSTRA}/%.o,${notdir ${SRC_GRAPH_DIJKSTRA}}}

CC=g++
CFLAGS=-g -Wall -std=c++11 -I${DIR_INC}


${TARGET}:${OBJ}
	${CC} ${OBJ} -o $@

#compile folder src/
${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	${CC} ${CFLAGS} -c $< -o $@
#compile folder src/graph/iterator/
${DIR_OBJ}/${PATH_GRAPH_ITE}/%.o:${DIR_SRC}/${PATH_GRAPH_ITE}/%.cpp
	${CC} ${CFLAGS} -c $< -o $@
#compile folder src/graph/dijkstra/
${DIR_OBJ}/${PATH_GRAPH_DIJKSTRA}/%.o:${DIR_SRC}/${PATH_GRAPH_DIJKSTRA}/%.cpp
	${CC} ${CFLAGS} -c $< -o $@
#compile folder src/sort/
${DIR_OBJ}/%.o:${DIR_SRC}/${PATH_SORT}/%.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	find ${DIR_OBJ} -name *.o -exec rm -rf {} \;
	rm -rf ${DIR_BIN}/*

debug:
	@echo "... debug"
	@echo "obj = ${OBJ}"
	@echo "src = ${SRC}"
	@echo "src_graph_ite = ${SRC_GRAPH_ITE}"
	@echo "src_graph_dijkstra = ${SRC_GRAPH_DIJKSTRA}"