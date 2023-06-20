#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    char secret_word[MAX_WORD_LENGTH];
    char guessed_word[MAX_WORD_LENGTH];
    int wordLength;

    // Opening entrance
    printf("***********************\n");
    printf("* Welcome to Hangman! *\n");
    printf("***********************\n");

    // Word input for testing
    printf("Enter the secret word: ");
    scanf("%s", secret_word);
    printf("%s\n", secret_word);

    wordLength = strlen(secret_word);

    for (int i = 0; i < wordLength; i++)
        guessed_word[i] = '-';

    guessed_word[wordLength] = '\0';

    printf("%s\n", guessed_word);
    
    return 0;
}