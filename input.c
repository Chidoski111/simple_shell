#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1000

void execute_command(const char *command) {
    // You can use system() to execute the command in the shell
    int exit_status = system(command);
    if (exit_status == -1) {
        perror("system");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];

    // Read and execute commands from the file
    while (fgets(command, sizeof(command), file) != NULL) {
        // Remove trailing newline character if present
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        execute_command(command);
    }

    fclose(file);
    return 0;
}
