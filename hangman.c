#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 100

int main() {
    char secretWord[MAX_WORD_LENGTH];
    char guessedWord[MAX_WORD_LENGTH];
    int tries = 0;
    int wordLength;
    char guess;
    bool correctGuess;

    // Opening entrance
    printf("***********************\n");
    printf("* Welcome to Hangman! *\n");
    printf("***********************\n");

    // Word input for testing
    printf("Enter the secret word: ");
    scanf("%s", secretWord);
    printf("%s\n", secretWord);

    wordLength = strlen(secretWord);

    for (int i = 0; i < wordLength; i++)
        guessedWord[i] = '-';

    guessedWord[wordLength] = '\0';

    printf("%s\n", guessedWord);

    while (tries < MAX_TRIES) {
        printf("Guessed word: %s\n", guessedWord);
        printf("Enter your guess: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        printf("%c\n", guess);

        correctGuess = false;

        for (int i = 0; i < wordLength; i++) {
            if (guess == secretWord[i]) {
                guessedWord[i] = guess;
                correctGuess = true;
            }   
        }

        if (!correctGuess) {
            tries++;
            printf("Incorrect guess! You have %d tries left.\n", MAX_TRIES - tries);
        }
            
        if (strcmp(secretWord, guessedWord) == 0) {
            printf("Congratulations! You won!\n");
            break;
        }
        
    }
    
    if (tries == MAX_TRIES)
        printf("You lost! The word was %s\n", secretWord);

    return 0;
}