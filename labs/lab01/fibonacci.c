#include <stdio.h>
#include <stdlib.h>

#define SERIES_MAX 46

int main(void) {
    //int already_computed[SERIES_MAX + 1] = { 0, 1 };
	
    
    int num = 0;
    while (scanf("%d", &num) == 1) {
        int first = 0;
        int second = 1;
        int next = first + second;

        for (int i = 1; i <= num; i++) {
            first = second;
            second = next;
            next = first + second;
        }
        
        printf("%d\n", first);
    
    }
    

    
    return EXIT_SUCCESS;
}
