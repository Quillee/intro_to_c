### EXCERCISE TABLE ###

flags = -Wall -g
no_dbg = -DNDEBUG
# default file and output
lib = ex22.c
lib_output = ex22.o
filename = ex22_main.c
main_output = ex22_main

clean:
	rm $(main_output)
extra-credit:
	# extra credit commands
build:
	gcc $(flags) $(filename) -o $(main_output)
debug:
	gcc $(flags) $(filename) -o $(main_output)
all:
	gcc $(flags) $(no_dbg) -c -o $(lib_output) $(lib)
	gcc $(flags) $(no_dbg) $(filename) $(lib_output) -o $(main_output)
#	gcc $(flags) $(no_dbg) $(filename) -o $(main_output)

no_wall:
	gcc $(filename) -o $(main_output)