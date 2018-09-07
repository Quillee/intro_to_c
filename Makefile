source = hello_world.c
target = hello_world
command = g++

all:
	$(command) $(source) -o $(target)
