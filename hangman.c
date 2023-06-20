#include <stdio.h>

#define MAX_WORD_LENGTH 100

int main() {
    char secret_word[MAX_WORD_LENGTH];

    // Opening entrance
    printf("***********************\n");
    printf("* Welcome to Hangman! *\n");
    printf("***********************\n");

    // Word input for testing
    printf("Enter the secret word: ");
    scanf("%s", secret_word);
    printf("%s\n", secret_word);
    
    return 0;
}