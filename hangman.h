#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 100
#define WORD_LENGTH strlen(secretWord)
#define RANDOM_WORD

void Entrance();
char* GetRandomWord();
char* ChooseWord();
// void BlankGuessedWord();
// void WordGuessing();
void ClearScreen();
// void CheckLosing();

void Entrance()
{
    printf("***********************\n");
    printf("* Welcome to Hangman! *\n");
    printf("***********************\n");
}

char* GetRandomWord()
{
    FILE *f;
    char* secretWord = NULL;

    // This file must be on the same directory as hangman file!
    f = fopen("wordbank.txt", "r");
    if (f == NULL)
    {
        printf("Database not available =(\n\n");
        exit(1);
    }

    // The first line of the file is the number of words
    int wordCounter;
    fscanf(f, "%d", &wordCounter);

    srand(time(0));
    int random = rand() % wordCounter;

    printf("Getting a random word from database...\n");

    for (int i = 0; i <= random; i++)
    {
        secretWord = malloc(MAX_WORD_LENGTH * sizeof(char));
        fscanf(f, "%s", secretWord);
    }

    fclose(f);
    return secretWord;
}

char* ChooseWord()
{
    char* secretWord = malloc(MAX_WORD_LENGTH * sizeof(char));

    printf("Enter the secret word: ");
    scanf("%s", secretWord);

    return secretWord;
}

// void BlankGuessedWord()
// {
//     for (int i = 0; i < WORD_LENGTH; i++)
//         guessedWord[i] = '_';

//     guessedWord[WORD_LENGTH] = '\0';
// }

// bool CorrectLetter(char letter)
// {
//     for (int i = 0; i < WORD_LENGTH; i++)
//     {
//         if (letter == secretWord[i])
//         {
//             guessedWord[i] = letter;
//             return true;
//         }
//     }

//     return false;
// }

void ClearScreen()
{
    printf("\e[1;1H\e[2J");
}