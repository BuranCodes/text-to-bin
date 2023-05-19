/*
* Buran
* Text to binary translation in C language.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXPANSION_FACTOR 1.5

void txtbin(const char *txt, size_t len)
{
    char *bintxt = NULL;
    char *tmpstr = NULL;
    if ((bintxt = (char *)calloc(9*len, sizeof(char))) == NULL) {
        fputs("Cannot create output string.", stderr);
        exit(EXIT_FAILURE);
    }
    if ((tmpstr = (char *)calloc(9*len, sizeof(char))) == NULL) {
        fputs("Cannot create temporary string.", stderr);
        exit(EXIT_FAILURE);
    }
    /*
     * in this case, 9 instead of 8 since it includes spaces to
     * separate binary substrings; \0 needed too when done looping thru text
    */

   for (int i = len-1; i >= 0; i--) {
        char tmp[9] = "";
        int bc = txt[i];
        while (bc != 0) {
            if (bc%2 == 0)
                strcat(tmp, "0");
            else if (bc%2 == 1)
                strcat(tmp, "1");
            bc = bc/2;
        }
        if (strlen(tmp) != 8) {
            for (int j = 0; j <= 8 - strlen(tmp); j++)
                strcat(tmp, "0"); /* add leading zeroes */
        }
        strcat(tmp, " ");
        strcat(bintxt, tmp);
    }
    strcpy(tmpstr, bintxt);
    /* 
    * WITH HUMOR
    * my bad for doing tmpstr = bintxt
    * thanks, brain and python/C++
    */
    for (int i = 0, j = strlen(tmpstr)-2;
        i < strlen(tmpstr) && j >= 0; i++, j--)
        bintxt[i] = tmpstr[j];

     fprintf(stdout, "Resulting binary output: %s", bintxt);
     free(bintxt);
     free(tmpstr);
}

int main(void)
{
    fputs("Enter any text to convert to binary: ", stdout);
    char tmpc[2] = "0\0";
    char *input = NULL;
    int strsize = 8; /* starting size */
    int tmp = EOF;

    if ((input =(char *)calloc(strsize, sizeof(char))) == NULL) {
        fputs("Cannot create input string.", stderr);
        exit(EXIT_FAILURE);
    }
    while (tmp) {
        tmp = fgetc(stdin);

        if (tmp == EOF || tmp == '\n')
            tmp = 0;

        if (strlen(input) == strsize-1) {
            strsize *= EXPANSION_FACTOR;
            if ((input = (char *)realloc(input, strsize)) == NULL) {
                fputs("Reallocation failed.", stderr);
                exit(EXIT_FAILURE);
            }
        }
        tmpc[0] = (char)tmp;
        strcat(input, tmpc);
    }
    txtbin(input, strlen(input));
    free(input);
    return EXIT_SUCCESS;
}
