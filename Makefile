CC =gcc -fsanitize=address

CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=-lm

all: main

main : main.o MathUtils.o MatrixUtils.o NeuralNetwork.o XOR.o 2DArray.o

clean:
	${RM} *.o
	${RM} *.d
	${RM} main
