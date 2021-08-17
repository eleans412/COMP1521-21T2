#include <stdio.h>
#include <stdlib.h>

/*
Code if given 1 or more commands in the command line gives the sum, product, mean
min, max of all the values given
*/

// **argv is an array of inputs
// So we will need to convert the strings in argv into integers
/// atoi - converts the string to an int so that you can do your comparisons
int main(int argc, char **argv) {
	int elements = 0;
	int location = 0;

	
	int min = 0;
	int max = 0;
	int sum = 0;
	// This must be set at 1 because 0 * anything will be 0
	int prod = 1;
	int mean = 0;

	// If there is only the name of the file as the argument
	if (argc == 1) {
		printf("Usage %s NUMBER [NUMBER ...]\n", argv[0]);
		return 0;
	}
	else {
		// Else do the calculations
		
		// Loop through all the arguments in the array
		elements = argc - 1;

		// Find the biggest number
		int i = 1;
		location = 1;
		
		while (i <= elements) {
			if (atoi(argv[i]) >= atoi(argv[location])) {
				location = i;
			}
			i++;
		}
		max = atoi(argv[location]);
		
		// Reset variables
		i = 1;
		location = 1;
		
		while (i <= elements) {
			if (atoi(argv[i]) <= atoi(argv[location])) {
				location = i;
			}
			i++;
		}
		min = atoi(argv[location]);
		
		// Reset variables
		i = 1;
		location = 1;
		// Find the sum of all the numbers
		while (i <=elements) {
			sum = sum + atoi(argv[i]);
			i++;
		}
		// Find the product
		// Reset variables
		i = 1;
		location = 1;

		while (i<=elements) {
			prod = atoi(argv[i]) * prod;
			i++;
		}
		

		// Find the average
		mean = sum / elements;
		
	}
	
	printf("MIN:  %d\n", min);
	printf("MAX:  %d\n", max);
	printf("SUM:  %d\n", sum);
	printf("PROD: %d\n", prod);
	printf("MEAN: %d\n", mean);
	return 0;
}
