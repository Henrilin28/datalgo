# Makefile for asio_zsock
# expects boost and zeromq
#

BOOST_LFLAGS = -lboost_system
LD_FLAGS = -L/usr/local/lib/
CXX_FLAGS = -std=c++11 -Wall
HEADERS = $(wildcard *.h) $(wildcard *.hpp)
CFLAGS = -I/usr/local/include
ifeq ($(TEST), 1)  
CFLAGS += -DTEST
endif

interview: main.o sort.o lists.o randomexamples.o strings.o expr.o expr_tests.o color_region.o\
	tree_tests.o nqueens.o
	g++ -g $(LD_FLAGS) $(BOOST_LFLAGS)  -o interview main.o sort.o lists.o \
		randomexamples.o strings.o tree_tests.o expr_tests.o expr.o color_region.o\
		nqueens.o



%.o: %.cpp
	g++ -g $(CFLAGS) $(CXX_FLAGS) -c $<

%.o: %.cxx
	g++ -g $(CFLAGS) $(CXX_FLAGS) -c $<

%.o: %.c
	cc -c $(CFLAGS) $<

all: interview

clean:
	rm -f *.o
	rm -f interview
