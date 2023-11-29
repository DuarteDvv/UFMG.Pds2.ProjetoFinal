CC=g++
CFLAGS=-std=c++11 -Wall
TARGET= executavel
all := ${TARGET}

EXE = ./Exe
BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

${EXE}/${TARGET}: ${BUILD_DIR}/main.o ${BUILD_DIR}/Sistema.o ${BUILD_DIR}/Usuario.o ${BUILD_DIR}/Filmes.o ${BUILD_DIR}/Function.o 
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o $@
 
${BUILD_DIR}/Filmes.o: ${INCLUDE_DIR}/Film.hpp ${SRC_DIR}/IClasses/iFilm.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/IClasses/iFilm.cpp -o ${BUILD_DIR}/Filmes.o
 
${BUILD_DIR}/Usuario.o: ${INCLUDE_DIR}/Usuario.hpp ${SRC_DIR}/IClasses/iUsuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/IClasses/iUsuario.cpp -o ${BUILD_DIR}/Usuario.o
 
${BUILD_DIR}/Sistema.o: ${INCLUDE_DIR}/system.hpp ${SRC_DIR}/IClasses/isystem.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/IClasses/isystem.cpp -o ${BUILD_DIR}/Sistema.o
 
${BUILD_DIR}/Function.o: ${INCLUDE_DIR}/Function.hpp ${SRC_DIR}/IClasses/IFunction.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/IClasses/IFunction.cpp -o ${BUILD_DIR}/Function.o
 
${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Usuario.hpp ${INCLUDE_DIR}/Film.hpp ${INCLUDE_DIR}/system.hpp ${SRC_DIR}/Main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Main.cpp -o ${BUILD_DIR}/main.o
 
clean:
	rm -f ${BUILD_DIR}/*

run: ${EXE}/${TARGET}
	./${EXE}/${TARGET}