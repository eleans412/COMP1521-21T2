#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	// If there is only the name of the file as the argument
	if (argc == 1) {
		printf("Usage %s NUMBER \n", argv[0]);
		return 0;
	}
	// Convert the string to int
	int num = atoi(argv[1]);

	// Print the initial number
	printf("%d\n", num);

	// Loop until 1
	while (num > 1) {
		// If n/2
		if (num % 2 == 0) {
			num = num/2;
			printf("%d\n", num);
		}
		// Otherwise 3n + 1
		else {
			num = num * 3 + 1;
			printf("%d\n", num);
		}
	}

	return EXIT_SUCCESS;
}
