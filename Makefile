SRC=start.C object.C equation.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ $(OBJ) -o start

.C.o: $<
	g++  -g -I. -c $<

clean:
	rm *.o start
