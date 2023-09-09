// Strings in C are simply arrays of character type

#include <stdio.h>

int main(void){
    char word[10] = "Winter";
    char word2[7] = "Spring";

    printf("%s\n", word);
    printf("%s\n",word2);

    return 0;
}