#include <stdio.h>

int main(int argc, char **argv) {
	int arguments_count = 0;
	int arg_num = 0;
	arguments_count = argc;
	printf("Program name: %s\n", argv[0]);
	if (arguments_count > 1) {
		int i = 1;
		arg_num = arguments_count - 1;
		printf("There are %d arguments:\n", arg_num);
		while (i < arguments_count) {
			printf("\tArgument %d is \"%s\"\n", i, argv[i]);
			i++;
			
		} 
	}
	else {
		printf("There are no other arguments\n");
	}
	return 0;
}
