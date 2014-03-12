SRC = ioput.cpp
MAIN = main.cpp

SRCS = $(SRC) $(MAIN)

SOURCE = source/
LIB = lib/
INCLUDE = header/

INC = $(SRC:.cpp=.h)

OBJS = $(SRCS:.cpp=.o)

CXX			=	icpc
CPPFLAGS	=	-std=c++11 -I $(INCLUDE)

EXEC = out

all: $(EXEC)

ioput.o: $(SOURCE)$(SRC) $(INCLUDE)$(INC)
	$(CXX) $(CPPFLAGS) -c $< -o $(LIB)$@
	
main.o: $(MAIN) $(INCLUDE)$(INC)
	$(CXX) $(CPPFLAGS) -c $< -o $(LIB)$@

$(EXEC): $(OBJS)
	@echo $(OBJS)
	$(CXX) -o $@ $(addprefix $(LIB),$^)

.PHONY: clean clean_all
clean:
	@echo "Object files removed!"
	@rm -f $(LIB)*.o
clean_all:
	@echo "Object files and executable removed!"
	@rm -f $(LIB)*.o $(EXEC) *~
	
rebuild: clean all
