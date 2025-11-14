#include <stdio.h>
#include <string.h>

int main(void) {

    char input[1024];


    while (1) {

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

        printf("You just entered %s\n", input);
    }
}
