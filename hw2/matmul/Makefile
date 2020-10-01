CC=g++
CFLAGS=-c
EXECUTALBE=prog

all:
	$(CC) $(CFLAGS) matrix_operations_lib.cpp $(OPT)
	ar rc minilib.a matrix_operations_lib.o
	$(CC) main.cpp minilib.a -o $(EXECUTABLE)
clean:
	rm *.o minilib.a $(EXECUTABLE)
run:
	./$(EXECUTABLE)
