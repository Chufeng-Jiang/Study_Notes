target = main
objects = main.o fun1.o fun2.o sum.o
CC = gcc
CPPFLAGS = -I./

#这里的$(objects)不能替换成$^,因为此处是条件，不是命令
$(target): $(objects) 
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< $(CPPFLAGS)

###########################################

#main.o: main.c
#	$(CC) -c $< $(CPPFLAGS)

#fun1.o: fun1.c
#	$(CC) -c $<
	
#fun2.o: fun2.c
#	$(CC) -c $<

#sum.o: sum.c
#	$(CC) -c $<
