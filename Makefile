SRC=main.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ $(OBJ) -o PhysSim

.C.o: $<
	g++  -g  -c $<

clean:
	rm *.o PhysSim
