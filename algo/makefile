source = main.c
cc = gcc
cflags = -I .
deps = all.h
output = -o algo_runner

%.o: %.c $(deps)
	$(cc) -c -o $@ $< $(cflags)

all: insertion_sort.o
	$(cc) $(output) insertion_sort.o