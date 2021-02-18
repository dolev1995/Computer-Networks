
#file: makefile

all:   prefix_table_opt	prefix_table  

prefix_table: prefix_table.cpp prefix_table.hpp
	g++ prefix_table.cpp -o prefix_table 
#	./prefix_table

prefix_table_opt: prefix_table_opt.cpp prefix_table_opt.hpp
	g++  -o prefix_table_opt prefix_table_opt.cpp
#	./prefix_table_opt

clean:
	rm -f *.o  prefix_table 