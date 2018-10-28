### EXCERCISE TABLE ### \
ec1 	|	make max_rows & data a value that can be changed

flags = -Wall -g
# default file and output
filename = ex17.c
main_output = ex17
# ec 1
ec1_filename = ec2_max_change.c
ec1_output = ex17_ec_diff_max

clean:
	rm $(main_output)
	rm $(ec1_output)
extra-credit:
	gcc $(flags) $(ec1_filename) -o$(ec1_output)
build:
	gcc $(flags) $(filename) -o $(main_output)
all:
	gcc $(flags) $(filename) -o $(main_output)
	gcc $(flags) $(ec1_filename) -o$(ec1_output)
