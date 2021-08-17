#include <stdio.h>
#include <string.h>

int main(void) {
	// Initialise the ch
	char ch = '\0';
	
	// Keep running until EOF is found
	// scanf only returns a 0 or a 1 so when EOF is given it will not be equal to 1
	// Read in one character at a time
	while (scanf("%c", &ch) == 1) {

		// Check that the word has a vowel
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
		ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
			// When we see a vowel - skip
			continue;
		}
		// Otherwise output that character
		else {
			printf("%c", ch);
		}
		
	}
	return 0;
}