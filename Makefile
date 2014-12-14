
CXX_FLAGS = -std=c++11 -Wall
HEADERS = $(wildcard *.h) $(wildcard *.hpp)

ifeq ($(TEST), 1)  
	CFLAGS += -DTEST
endif

datalgo: main.o sort.o list.o miscellaneous.o strings.o expr.o expr_tests.o color_region.o\
	tree_tests.o nqueens.o list_tests.o
	@echo "building "$@
	$(CXX) -g -o $@ $?



%.o: %.cpp
	$(CXX) -g $(CXX_FLAGS) -c $<

%.o: %.cxx
	$(CXX) -g $(CXX_FLAGS) -c $<

%.o: %.c
	$(CC) -c $<

all: interview

clean:
	rm -f *.o

mrproper: clean
	rm -f datalgo

