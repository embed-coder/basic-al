/*
Implement function sort_words that sorts an array of words that contain lowercase characters from english alphabet, in descending order, and is efficient with respect to time used.
For example, the array { "cherry", "orange", "apple" } should, after sorting, become { "orange", "cherry", "apple" }.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void sort_words(char *words[], int count)
{
    int i, j;
    char *temp;
    for (i = 0; i < count-1; i++)
    // Last i elements are already in place 
        for (j = 0; j < count-i-1; j++)
            if (strcmp(words[j], words[j+1]) < 0) {
                temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
}

#ifndef RunTests
int main()
{
    char *words[] = { "cherry", "orange", "apple" };

    sort_words(words, 3);

    for (int i = 0; i < 3; i++)
    {
        printf("%s ", words[i]);
    }
}
#endif