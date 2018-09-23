flags = -Wall -g
filename = ex03.c
output = ex03
dbug_args = --batch --ex run --ex bt

clean:
	rm $(output)
all:
	gcc $(flags) $(filename) -o $(output)
# debug ex 04
debug:	
	gdb $(dbug_args) --args $(output)
