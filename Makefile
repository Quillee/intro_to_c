source = hello_world.c
target = hello_world
command = gcc

all:
	$(command) $(source) -o $(target)
