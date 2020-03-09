#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Turns arguments into loltext\n\n");
        printf("USAGE: ./loltext text to turn into loltext\n");
        return EXIT_FAILURE;
    }

    int nstrs = argc - 1;
    char** strs = ++argv;

    /* Initialize random generator */
    time_t t;
    srand((unsigned) time(&t));

    int i, j;

    int lengths[nstrs];

    int total_length = 0;
    for (i = 0; i < nstrs; ++i) {
        total_length += lengths[i] = strlen(strs[i]);
    }

    // Add one for the null terminator and nstrs-1 for the spaces in between.
    total_length += 1 + (nstrs - 1);

    char buffer[total_length];
    int position = 0;

    for (i = 0; i < nstrs; ++i) {
        for (j = 0; j < lengths[i]; ++j) {
            buffer[position++] = rand() % 2 == 0
                ? tolower(strs[i][j])
                : toupper(strs[i][j]);
        }
        // Maybe add the space.
        if (i < nstrs - 1) {
            buffer[position++] = ' ';
        }

    }
    // Add the null terminator.
    buffer[position] = '\0';

    printf("%s\n", buffer);

    return EXIT_SUCCESS;
}