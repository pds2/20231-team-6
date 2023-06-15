CC=g++
CFLAGS=-std=c++17 -Wall

all: main

pessoa.o: include/pessoa.h src/pessoa.cpp
	${CC} ${CFLAGS} -c src/pessoa.cpp -o build/pessoa.o

funcionario.o: pessoa.o include/funcionario.h src/funcionario.cpp
	${CC} ${CFLAGS} -c src/funcionario.cpp -o build/funcionario.o

professor.o: funcionario.o include/professor.h src/professor.cpp
	${CC} ${CFLAGS} -c src/professor.cpp -o build/professor.o

main.o: funcionario.o src/main.cpp
	${CC} ${CFLAGS} -c src/main.cpp -o build/main.o

main: main.o pessoa.o funcionario.o professor.o
	${CC} ${CFLAGS} build/main.o build/pessoa.o build/funcionario.o 
	build/professor.o -o vpl_execution

clean:
	rm -f vpl_execution *.o
