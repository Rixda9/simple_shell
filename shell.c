#include <stdio.h>
#include <string.h>

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
        // newline
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye\n");
            break;
        }
        char *args[128];
        int argc = 0;
        char *strToken = strtok(input, SEPARATOR);

        while (strToken != NULL)
        {
            args[argc] = strToken;
            argc++;
            //printf("%s successfully copied\n", args[argc]);
            strToken = strtok( NULL, SEPARATOR);
        }

        args[argc] = NULL;

        printf("Command: %s\n", args[0]);
        for (int i = 0; args[i] != NULL; i++) {
            printf(" args[%d] = %s\n", i, args[i]);
        }
    }
}
