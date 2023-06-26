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
char* ChooseRandomWord();
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

char* ChooseRandomWord()
{
    FILE *f;
    char* secretWord = NULL;

    // This file must be on output directory!
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

// void ChooseRandomWord()
// #ifdef RANDOM_WORD
// {
//     FILE *f;

//     // This file must be on output directory!
//     f = fopen("wordbank.txt", "r");
//     if (f == 0)
//     {
//         printf("Database not available =(\n\n");
//         exit(1);
//     }

//     // The first line of the file is the number of words
//     int wordCounter;
//     fscanf(f, "%d", &wordCounter);

//     srand(time(0));
//     int random = rand() % wordCounter;

//     printf("Getting a random word from database...\n");

//     for (int i = 0; i <= random; i++)
//     {
//         fscanf(f, "%s", secretWord);
//     }

//     fclose(f);
// }
// #else // RANDOM_WORD
// {
//     printf("Enter the secret word: ");
//     scanf("%s", secretWord);
//     printf("%s\n", secretWord);
// }
// #endif // RANDOM_WORD

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

// void WordGuessing()
// {
//     while (tries < MAX_TRIES)
//     {
//         printf("You have %d tries left.\n", MAX_TRIES - tries);
//         printf("Guessed word: %s\n", guessedWord);
//         printf("Enter your guess: ");
//         scanf(" %c", &guess);
//         guess = tolower(guess);

//         printf("%c\n", guess);

//         correctGuess = false;

//         for (int i = 0; i < WORD_LENGTH; i++)
//         {
//             if (guess == secretWord[i])
//             {
//                 guessedWord[i] = guess;
//                 correctGuess = true;
//             }
//         }

//         ClearScreen();

//         if (!correctGuess)
//         {
//             tries++;
//             printf("Incorrect guess!\n");
//         }
//         else
//         {
//             printf("Correct guess!\n");
//         }

//         if (strcmp(secretWord, guessedWord) == 0)
//         {
//             printf("Congratulations! You won!\n");
//             printf("The word was %s\n", secretWord);
//             break;
//         }
//     }
// }

void ClearScreen()
{
    printf("\e[1;1H\e[2J");
}

// void CheckLosing()
// {
//     if (tries == MAX_TRIES)
//         printf("You lost! The word was %s\n", secretWord);
// }