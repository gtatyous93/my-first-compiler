CXX	= g++

.cc.o:
	$(CXX) -O3 -c $< -o $*.o

default: all

all: tube2

tube2.tab.cc: tube2.y
	bison -o tube2.tab.cc -b tube2 -d tube2.y

tube2.yy.cc: tube2.lex
	flex -o tube2.yy.cc tube2.lex

tube2: tube2.tab.o tube2.yy.o ast.o
	$(CXX) -o tube2 tube2.tab.o tube2.yy.o ast.o -ll -ly

clean:
	rm -f tube2.tab.cc tube2.tab.hh tube2.yy.cc *~ *.o tube2
