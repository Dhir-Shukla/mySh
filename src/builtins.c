#include <string.h>

#include "builtins.h"
#include "io_helpers.h"
#include "variables.h"

#define DOLLAR "$"

// ====== Command execution =====

/* Return: index of builtin or -1 if cmd doesn't match a builtin
 */
bn_ptr check_builtin(const char *cmd) {
    ssize_t cmd_num = 0;
    while (cmd_num < BUILTINS_COUNT &&
           strncmp(BUILTINS[cmd_num], cmd, MAX_STR_LEN) != 0) {
        cmd_num += 1;
    }
    return BUILTINS_FN[cmd_num];
}


// ===== Builtins =====

/* Prereq: tokens is a NULL terminated sequence of strings.
 * Return 0 on success and -1 on error ... but there are no errors on echo. 
 */
ssize_t bn_echo(char **tokens) {
    ssize_t index = 1;

    if (tokens[index] != NULL) {
        char * s = tokens[index];
        //char *dollar = "$";
        //if (strchr(s, *dollar) == NULL){
         if (tokens[index][0] == *"$") {
            int length = sizeof(tokens[index])
            char post[length] = malloc(sizeof(char * length))
            strncpy()
           strtok(s, DOLLAR)
            char * post = strtok(NULL, DELIMITERS);
            char * new_string = valid_node(post);
            if (new_string != NULL){
                display_message(new_string);
            }
            // If variable does not exist, treat as normal string
            display_message("$");
            display_message(post);
        }
        else{
            display_message(tokens[index]);
        }
        index += 1;
    }
    while (tokens[index] != NULL) {
        // TODO:
        // Implement the echo command
        display_message(" ");
        display_message(tokens[index]);
        index += 1;
    }
    display_message("\n");
    return 0;
}
