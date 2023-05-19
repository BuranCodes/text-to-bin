/*
* Buran
* Text to binary translation in C language.
* WORK IN PROGRESS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void txtbin(const char *txt, size_t len)
{
    char *bintxt = NULL;
    char *tmpstr = NULL;
    if ((bintxt = (char *)calloc(9*len, sizeof(char))) == NULL) {
        fputs("Cannot create output string.", stdout);
        exit(EXIT_FAILURE);
    }
    if ((tmpstr = (char *)calloc(9*len, sizeof(char))) == NULL) {
        fputs("Cannot create temporary string.", stdout);
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
    * my bad for doing tmpstr = bintxt
    * thanks, brain 
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
    txtbin("Hello!", 6);
    return EXIT_SUCCESS;
}
