#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 100

int main() {
    char secret_word[MAX_WORD_LENGTH];
    char guessed_word[MAX_WORD_LENGTH];
    int tries = 0;
    int wordLength;
    char guess;
    bool correct_guess;

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

    while (tries < MAX_TRIES) {
        printf("Guessed word: %s\n", guessed_word);
        printf("Enter your guess: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        printf("%c\n", guess);

        correct_guess = false;

        for (int i = 0; i < wordLength; i++) {
            if (guess == secret_word[i]) {
                guessed_word[i] = guess;
                correct_guess = true;
            }   
        }

    }
    
    return 0;
}