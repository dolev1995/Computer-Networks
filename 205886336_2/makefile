#file: makefile

all: edf  bd

edf: edf.cpp edf.hpp
	g++ -c edf.cpp
	g++ edf.o -o edf

bd: bd.cpp bd.hpp
	g++ -c bd.cpp
	g++ bd.o -o bd

clean:
	rm -f *.o  edf 