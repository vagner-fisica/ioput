CPP	=	icpc

INCLUDE	=	headers/
SOURCE	=	source/
LIB		=	lib/

SRC1	=	ioput
MAIN	=	main

EXEC	=	exec

all:	$(EXEC)

ioput.o: $(SOURCE)$(SRC1).cpp $(INCLUDE)$(SRC1).h
	$(CPP) -I $(INCLUDE) -c $(SOURCE)$(SRC1).cpp -o $(LIB)$(SRC1).o
main.o: $(MAIN).cpp $(INCLUDE)$(SRC1).h
	$(CPP) -I $(INCLUDE) -c $(MAIN).cpp -o $(LIB)$(MAIN).o
exec: $(SRC1).o $(MAIN).o
	$(CPP) -I $(LIB) -o $(EXEC) $(LIB)$(SRC1).o $(LIB)$(MAIN).o
run:
	./exec
clean:
	rm -f $(LIB)*.o
