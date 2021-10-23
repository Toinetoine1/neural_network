OBJS	= main.o XOR.o 2DArr# Makefile

CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
LDFLAGS =
LDLIBS =

OBJ = matrix.o main.o
DEP = ${OBJ:.o=.d}

all: main

main: ${OBJ}

clean:
	${RM} ${OBJ} ${DEP} main

-include ${DEP}

# ENDay.o MatrixUtils.o MathUtils.o
SOURCE	= main.c XOR.c 2DArray.c MatrixUtils.c MathUtils.c
HEADER	= XOR.h 2DArray.h MatrixUtils.h MathUtils.h
OUT	= myproject1
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c -std=c99

XOR.o: XOR.c
	$(CC) $(FLAGS) XOR.c -std=c99

2DArray.o: 2DArray.c
	$(CC) $(FLAGS) 2DArray.c -std=c99

MatrixUtils.o: MatrixUtils.c
	$(CC) $(FLAGS) MatrixUtils.c -std=c99

MathUtils.o: MathUtils.c
	$(CC) $(FLAGS) MathUtils.c -std=c99


clean:
	rm -f $(OBJS) $(OUT)
