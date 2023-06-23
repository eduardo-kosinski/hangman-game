#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 100
#define WORD_LENGTH strlen(g_secretWord)
//#define RANDOM_WORD

char g_secretWord[MAX_WORD_LENGTH];
char g_guessedWord[MAX_WORD_LENGTH];

int tries = 0;
char guess;
bool correctGuess;

void Entrance();
void ChooseWord();
void BlankGuessedWord();
void WordGuessing();
void ClearScreen();
void CheckLosing();

void Entrance()
{
    printf("***********************\n");
    printf("* Welcome to Hangman! *\n");
    printf("***********************\n");
}

void ChooseWord()
#ifdef RANDOM_WORD
{
    FILE *f;

    // This file must be on output directory!
    f = fopen("wordbank.txt", "r");
    if (f == 0)
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
        fscanf(f, "%s", g_secretWord);
    }

    fclose(f);
}
#else // RANDOM_WORD
{
    printf("Enter the secret word: ");
    scanf("%s", g_secretWord);
    printf("%s\n", g_secretWord);
}
#endif // RANDOM_WORD

void BlankGuessedWord()
{
    for (int i = 0; i < WORD_LENGTH; i++)
        g_guessedWord[i] = '_';

    g_guessedWord[WORD_LENGTH] = '\0';
}

// bool CorrectLetter(char letter)
// {
//     for (int i = 0; i < WORD_LENGTH; i++)
//     {
//         if (letter == g_secretWord[i])
//         {
//             g_guessedWord[i] = letter;
//             return true;
//         }
//     }

//     return false;
// }

void WordGuessing()
{
    while (tries < MAX_TRIES)
    {
        printf("You have %d tries left.\n", MAX_TRIES - tries);
        printf("Guessed word: %s\n", g_guessedWord);
        printf("Enter your guess: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        printf("%c\n", guess);

        correctGuess = false;

        for (int i = 0; i < WORD_LENGTH; i++)
        {
            if (guess == g_secretWord[i])
            {
                g_guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        ClearScreen();

        if (!correctGuess)
        {
            tries++;
            printf("Incorrect guess!\n");
        }
        else
        {
            printf("Correct guess!\n");
        }

        if (strcmp(g_secretWord, g_guessedWord) == 0)
        {
            printf("Congratulations! You won!\n");
            printf("The word was %s\n", g_secretWord);
            break;
        }
    }
}

void ClearScreen()
{
    printf("\e[1;1H\e[2J");
}

void CheckLosing()
{
    if (tries == MAX_TRIES)
    printf("You lost! The word was %s\n", g_secretWord);
}