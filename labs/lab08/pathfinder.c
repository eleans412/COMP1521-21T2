#include <sys/types.h>

#include <sys/stat.h>

#include <assert.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>


static char **tokenize (char *string, char *separator);
static void free_tokens (char **tokens);
static bool is_executable (char *pathname);


int
main (int argc, char *argv[])
{

    char* full_path = getenv("PATH");
    char **tokens = tokenize(full_path, ":");

    int j = 0;
    int found = 0;

    // if the first argument is not ./pathfinder
    if (strcmp(argv[0], "./pathfinder") != 0) {
        size_t buffer_len = strlen(tokens[0]) + 1 + strlen(argv[0]) + 1; // this length is calculated so don't need the sizeof in the next line
        char* path_name = malloc(buffer_len); 
        snprintf(path_name, buffer_len, "%s/%s", tokens[0], argv[0]);
        if (is_executable(path_name)) {
            printf("%s\n", path_name);
            found = 1;
        }
    }

    else {
        j = 1;
        while (argv[j] != NULL) {
            int i = 0;
            
            while (tokens[i] != NULL) {
                
                // We can't just call strcat on a buffer because we might not have the space for the concatenation
                // Before you concatenate want to call malloc
                // Typedef for a big integer unsigned type
                // Plus 1 is for the slash
                // This will give the length of the token we want
                size_t buffer_len = strlen(tokens[i]) + 1 + strlen(argv[j]) + 1; // this length is calculated so don't need the sizeof in the next line
                char* path_name = malloc(buffer_len); 

                // Lets us printf into a string
                // arguments that this takes are: buffer or the thing we are printing into , the size
                // you should loop through multile arguments of argv because we have to loop throguh multiple arguments for the task 
                // snprintf does not print to terminal
                snprintf(path_name, buffer_len, "%s/%s", tokens[i], argv[j]);

                // If the path is found then print to terminal and return 0
                if (is_executable(path_name)) {
                    printf("%s\n", path_name);
                    found = 1;
                }
                i++;
            }
            j++;
        }
        
    }
    
    if (!found) {
        // If it could not find the argument, print out that it could not find
        // argv[j-1] because the while loop incremented upon exit
        printf("%s not found\n", argv[j - 1]);
        free_tokens(tokens);
        return 2;
    }

    free_tokens(tokens);
    return 0;

    
}
////////////////////////////////////////////////////////////////////////
//    . . . you do not need to modify code beyond this point . . .    //

//
// Split a string 'str' into pieces by any one of a set of separators.
// Returns an array of strings, with the last element being `NULL'.
// The array itself, and the strings, are allocated with `malloc(3)';
// the provided `free_token' function can deallocate this.
//
static char **
tokenize (char *str, char *sep)
{
    size_t n_tokens = 0;
    char **tokens = NULL;

    while (*str != '\0') {
        // We are pointing at zero or more of any of the separators.
        // Skip all leading instances of the separators.
        str += strspn (str, sep);

        // Trailing separators after the last token mean that, at this
        // point, we are looking at the end of the string, so:
        if (*str == '\0')
            break;

        // Now, `s' points at one or more characters we want to keep.
        // The number of non-separator characters is the token length.
        // Allocate a copy of the token, and preserve it.
        size_t len = strcspn (str, sep);
        char *tok = strndup (str, len);
        assert (tok != NULL);
        str += len;

        // Add this token.  (Should really use reallocarray(3) here.)
        tokens = realloc (tokens, ++n_tokens * sizeof *tokens);
        tokens[n_tokens - 1] = tok;
    }

    // Add the final `NULL'.
    tokens = realloc (tokens, ++n_tokens * sizeof *tokens);
    tokens[n_tokens - 1] = NULL;

    return tokens;
}

//
// Free an array of strings.
//
static void
free_tokens (char **tokens)
{
    for (int i = 0; tokens != NULL && tokens[i] != NULL; i++)
        free (tokens[i]);

    free (tokens);
}


//
// Check whether this process can execute a file.
//
static bool
is_executable (char *pathname)
{
    struct stat s;
    return
        // does the file exist?
        stat (pathname, &s) == 0 &&
        // is the file a regular file?
        S_ISREG (s.st_mode) &&
        // can we execute it?
        faccessat (AT_FDCWD, pathname, X_OK, AT_EACCESS) == 0;
}
