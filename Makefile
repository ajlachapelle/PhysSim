all: PhysSim MatrixTest

# Main program
SRC=main.C menu.C menu.h algebra.C TestTheory.C
OBJ=$(SRC:.C=.o)
PhysSim: $(OBJ)
	g++ $(OBJ) -o PhysSim

# Performance/accuracy test for row reduction algorithm
SRC2=matrixTest.C algebra.C
OBJ2=$(SRC2:.C=.o)
MatrixTest: $(OBJ2)
	g++ $(OBJ2) -o MatrixTest

.C.o: $<
	g++  -g  -I.  -c $<

clean:
	rm *.o PhysSim MatrixTest
