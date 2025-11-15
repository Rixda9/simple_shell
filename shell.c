#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {

    char input[1024];

    while (1) {

        const char *SEPARATOR = " ";

        // prompt
        printf("myshell> ");
        fflush(stdout);

        // read input
        if(fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // get rid of newline
        input[strcspn(input, "\n")] = 0;


        if (strcmp(input, "exit") == 0) {
            printf("Goodbye\n");
            break;
        }
        // setup to use commands
        char *args[128];
        int argc = 0;
        char *strToken = strtok(input, SEPARATOR);

        // parse inputs
        while (strToken != NULL) {
            args[argc] = strToken;
            argc++;
            strToken = strtok( NULL, SEPARATOR);
        }

        args[argc] = NULL;

        if (argc == 0){
            continue;
        }

        // handle cd before forking
        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "cd: missing arguments\n");
            }
            else {
                if (chdir(args[1])!= 0) {
                    perror("cd");
                }
            }
            continue;
        }

        // create a fork to execute the command in a different process
        pid_t pid = fork();

        if (pid<0) {
            perror("fork failed");
            exit(1);
        }

        else if (pid == 0){
            execvp(args[0], args);
            fprintf(stderr, "%s: command not found\n", args[0]);
            exit(127);
        }
        else {
            wait(NULL);
        }
    }
}
