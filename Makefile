CC = gcc
AR = ar
FLAGS = -Wall -g


all:  txtfind isort  

txtfind: txtfind.c txtfind.h  
	$(CC) $(FLAGS) txtfind.c -o txtfind


isort: isort.c isort.h
	$(CC) $(FLAGS) isort.c -o isort


	


.PHONY: clean 
	
clean: 
	rm -f *.o txtfind isort 
	
