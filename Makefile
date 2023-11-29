CC=g++
CFLAGS=-std=c++11 -Wall
TARGET= executavel
all = ${TARGET}

BUILD_DIR = ./ProjetoFinal_PDS2/build
SRC_DIR = ./ProjetoFinal_PDS2/src
INCLUDE_DIR = ./ProjetoFinal_PDS2/include

./ProjetoFinal_PDS2/${TARGET}: ${BUILD_DIR}/Filmes.o ${BUILD_DIR}/Usuario.o ${BUILD_DIR}/Sistema.o ${BUILD_DIR}/main.o
 ${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ./${TARGET}
 
${BUILD_DIR}/Filmes.o: ${INCLUDE_DIR}/Filme.hpp ${SRC_DIR}/IClasses/iFilme.cpp
 ${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/IClasses/iFilme.cpp -o ${BUILD_DIR}/Filmes.o
 
${BUILD_DIR}/Usuario.o: ${INCLUDE_DIR}/Usuario.hpp ${SRC_DIR}/IClasses/iUsuario.cpp
 ${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/IClasses/iUsuario.cpp -o ${BUILD_DIR}/Usuario.o
 
${BUILD_DIR}/Sistema.o: ${INCLUDE_DIR}/system.hpp ${SRC_DIR}/IClasses/isystem.cpp
 ${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/IClasses/isystem.cpp -o ${BUILD_DIR}/Sistema.o
 
${BUILD_DIR}/Function.o: ${INCLUDE_DIR}/Function.hpp ${SRC_DIR}/IClasses/IFunction.cpp
 ${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/IClasses/IFunction.cpp -o ${BUILD_DIR}/Function.o
 
${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Usuario.hpp ${INCLUDE_DIR}/Filme.hpp ${INCLUDE_DIR}/system.hpp ${SRC_DIR}/Main.cpp
 ${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Main.cpp -o ${BUILD_DIR}/main.o
 
clean:
 rm -f ${BUILD_DIR}/*
