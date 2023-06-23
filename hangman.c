#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 100

char g_secretWord[MAX_WORD_LENGTH];

void ChooseWord() {
    FILE* f;

    f = fopen("wordbank.txt", "r");
    if(f == 0) {
        printf("Database not available =(\n\n");
        exit(1);
    }

    int wordCounter;
    fscanf(f, "%d", &wordCounter);

    srand(time(0));
    int random = rand() % wordCounter;

    for(int i = 0; i <= random; i++) {
        fscanf(f, "%s", g_secretWord);
    }

    fclose(f);
}

int main() {
    char guessedWord[MAX_WORD_LENGTH];
    int tries = 0;
    int wordLength;
    char guess;
    bool correctGuess;

    // Opening
    printf("***********************\n");
    printf("* Welcome to Hangman! *\n");
    printf("***********************\n");

    // Word input for testing
    // printf("Enter the secret word: ");
    // scanf("%s", g_secretWord);
    // printf("%s\n", g_secretWord);

    ChooseWord();

    wordLength = strlen(g_secretWord);

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
            if (guess == g_secretWord[i]) {
                guessedWord[i] = guess;
                correctGuess = true;
            }   
        }

        // Clean the screen
        printf("\e[1;1H\e[2J"); 

        if (!correctGuess) {
            tries++;
            printf("Incorrect guess! You have %d tries left.\n", MAX_TRIES - tries);
        }
            
        if (strcmp(g_secretWord, guessedWord) == 0) {
            printf("Congratulations! You won!\n");
            break;
        }
        

    }
    
    if (tries == MAX_TRIES)
        printf("You lost! The word was %s\n", g_secretWord);

    return 0;
}