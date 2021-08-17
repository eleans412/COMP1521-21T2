#include <stdio.h>
#include <string.h>
/*
Code reads in one line of input at a time 
Prints out one line at a time

Code checks that the length of the line is even or odd
Will remove the final charcter of the line to make the line even
if the line is odd
*/


int main(void) {

	char line[100];
	int length = 0;
	while (fgets(line, 100, stdin) != NULL) {
		// Read one line at a time
		
		
		// Count the number of characters in the line
		length = strlen(line);

		
		// If the line is even print
		if (length % 2 != 0) {
			continue;
		}
		// If the line is even just output that
		else {
			fputs(line, stdout);
		}
	}
	

	


	
	return 0;
}
