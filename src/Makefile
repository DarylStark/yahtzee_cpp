# Default arguments for the compiler

CXXFLAGS = -std=c++20 -fdiagnostics-color=always -Wall

# Variables for the outputfiles. These can be overwritten with environment
# variables

EXEC_FILE ?= yahtzee
OUT_DIR ?= ../build
OUT_OBJ_DIR ?= ../build/obj
CLEAN_DIR ?= ../build

# Phonies
.PHONY: all release debug clean

# Default target

all: release

# Targets to create the needed output dirs

${OUT_DIR}:
	mkdir -p ${OUT_DIR}

${OUT_OBJ_DIR}:
	mkdir -p ${OUT_OBJ_DIR}

# Targets for release

release: ${OUT_DIR} ${OUT_OBJ_DIR}
release: ${OUT_DIR}/${EXEC_FILE}

# Targets for debugging

debug: CXXFLAGS += -g
debug: ${OUT_DIR} ${OUT_OBJ_DIR}
debug: ${OUT_DIR}/${EXEC_FILE}

tst:
	echo ${EXEC_FILE}
	echo ${OUT_DIR}
	echo ${OUT_OBJ_DIR}

# Linking

${OUT_DIR}/${EXEC_FILE}: ${OUT_OBJ_DIR}/die.o ${OUT_OBJ_DIR}/dieset.o ${OUT_OBJ_DIR}/entity.o ${OUT_OBJ_DIR}/main.o ${OUT_OBJ_DIR}/player.o ${OUT_OBJ_DIR}/scorecard.o ${OUT_OBJ_DIR}/scorecardentry.o ${OUT_OBJ_DIR}/yathzee.o
	${CXX} ${CXXFLAGS} -o ${OUT_DIR}/${EXEC_FILE} ${OUT_OBJ_DIR}/*.o

# Object files

${OUT_OBJ_DIR}/main.o: main.cpp
	${CXX} ${CXXFLAGS} -o ${OUT_OBJ_DIR}/main.o -c main.cpp

${OUT_OBJ_DIR}/die.o: die.cpp
	${CXX} ${CXXFLAGS} -o ${OUT_OBJ_DIR}/die.o -c die.cpp

${OUT_OBJ_DIR}/dieset.o: dieset.cpp
	${CXX} ${CXXFLAGS} -o ${OUT_OBJ_DIR}/dieset.o -c dieset.cpp

${OUT_OBJ_DIR}/entity.o: entity.cpp
	${CXX} ${CXXFLAGS} -o ${OUT_OBJ_DIR}/entity.o -c entity.cpp

${OUT_OBJ_DIR}/player.o: player.cpp
	${CXX} ${CXXFLAGS} -o ${OUT_OBJ_DIR}/player.o -c player.cpp

${OUT_OBJ_DIR}/scorecard.o: scorecard.cpp
	${CXX} ${CXXFLAGS} -o ${OUT_OBJ_DIR}/scorecard.o -c scorecard.cpp

${OUT_OBJ_DIR}/scorecardentry.o: scorecardentry.cpp
	${CXX} ${CXXFLAGS} -o ${OUT_OBJ_DIR}/scorecardentry.o -c scorecardentry.cpp

${OUT_OBJ_DIR}/yathzee.o: yathzee.cpp
	${CXX} ${CXXFLAGS} -o ${OUT_OBJ_DIR}/yathzee.o -c yathzee.cpp

# Cleaning

clean:
	rm -rf ${CLEAN_DIR}