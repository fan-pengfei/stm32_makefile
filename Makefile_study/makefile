#makefi的名字最好开头用大写

OBJ = main.o kbd.o command.o display.o \
     insert.o search.o files.o utils.o
#windows下需要指定CC=gcc
CC = gcc

edit : $(OBJ)
	gcc -o edit $(OBJ)


main.o :  defs.h
kbd.o : defs.h command.h
command.o :  defs.h command.h
display.o :  defs.h buffer.h
insert.o :  defs.h buffer.h
search.o :  defs.h buffer.h
files.o :  defs.h buffer.h command.h
utils.o :  defs.h

#一般makefil都要加入clean指令
.PHONY : clean #表示clean是一个伪目标
clean :
	rm edit $(OBJ)