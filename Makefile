
CXX_FLAGS = -std=c++11 -Wall
HEADERS = $(wildcard *.h) $(wildcard *.hpp)

ifeq ($(TEST), 1)  
	CFLAGS += -DTEST
endif

interview: main.o sort.o lists.o randomexamples.o strings.o expr.o expr_tests.o color_region.o\
	tree_tests.o nqueens.o list_tests.o
	$(CXX) -g -o interview main.o sort.o lists.o \
		randomexamples.o strings.o tree_tests.o expr_tests.o expr.o color_region.o\
		nqueens.o list_tests.o



%.o: %.cpp
	$(CXX) -g $(CXX_FLAGS) -c $<

%.o: %.cxx
	$(CXX) -g $(CXX_FLAGS) -c $<

%.o: %.c
	$(CC) -c $<

all: interview

clean:
	rm -f *.o
	rm -f interview
