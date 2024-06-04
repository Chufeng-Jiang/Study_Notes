target = main
src = $(wildcard *.c)
objects = $(patsubst %.c, %.o, $(src))
CC = gcc
CPPFLAGS = -I./

$(target): $(objects) 
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< $(CPPFLAGS)

#clean和前面的命令没有依赖关系
.PHONY: clean
clean:
	rm -f $(objects) $(target)
