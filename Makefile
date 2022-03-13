# Default arguments for the compiler

CXXFLAGS = -std=c++20 -fdiagnostics-color=always -Wall

# Variables for the outputfiles. These can be overwritten with environment
# variables

EXEC_FILE ?= yahtzee
OUT_DIR ?= build
OUT_OBJ_DIR ?= build/obj
CLEAN_DIR ?= build
SRC_DIR = src

# Object files that need to be created
OBJS = main1.o test1.o

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

release: CXXFLAGS += -O3
release: ${OUT_DIR} ${OUT_OBJ_DIR}
release: ${OUT_DIR}/${EXEC_FILE}

# Targets for debugging

debug: CXXFLAGS += -g
debug: ${OUT_DIR} ${OUT_OBJ_DIR}
debug: ${OUT_DIR}/${EXEC_FILE}

# Linking

${OUT_DIR}/${EXEC_FILE}: ${OUT_OBJ_DIR}/die.o ${OUT_OBJ_DIR}/dieset.o ${OUT_OBJ_DIR}/entity.o ${OUT_OBJ_DIR}/main.o ${OUT_OBJ_DIR}/player.o ${OUT_OBJ_DIR}/scorecard.o ${OUT_OBJ_DIR}/scorecardentry.o ${OUT_OBJ_DIR}/yahtzee.o
	${CXX} ${CXXFLAGS} -o ${OUT_DIR}/${EXEC_FILE} ${OUT_OBJ_DIR}/*.o

# Object files

${OUT_OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	${CXX} ${CXXFLAGS} -o $@ -c $<

# Cleaning

clean:
	rm -rf ${CLEAN_DIR}