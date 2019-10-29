SRC=main.C algebra.C algebra.h
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ $(OBJ) -o PhysSim

.C.o: $<
	g++  -g  -I.  -c $<

clean:
	rm *.o PhysSim
