SRC = ioput.cpp
MAIN = main.cpp

SRCS = $(MAIN) $(SRC)

SOURCE = source/
LIB = lib/
INCLUDE = header/

INC = $(SRC:.cpp=.h)

OBJS = $(addprefix $(LIB),$(SRCS:.cpp=.o))

CXX			=	icpc
CPPFLAGS	=	-std=c++11 -I $(INCLUDE)

EXEC = out

build: out
	
$(LIB)ioput.o: $(SOURCE)$(SRC) $(INCLUDE)$(INC)
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(LIB)main.o: $(MAIN) $(INCLUDE)$(INC)
	$(CXX) $(CPPFLAGS) -c $< -o $@

out: $(OBJS)
	@echo $(OBJS)
	$(CXX) -o $@ $^
	
	@echo "Program built."
.PHONY: clean clean_all rebuild
clean:
	@echo "Object files removed!"
	@rm -f $(LIB)*.o
clean_all:
	@echo "Object files and executable removed!"
	@rm -f $(LIB)*.o $(EXEC) *~ $(SOURCE)/*~ $(INCLUDE)/*~
	
rebuild:
	@echo "Rebuilding project."
	make clean
	make build
	
