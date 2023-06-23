#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 100
#define WORD_LENGTH strlen(g_secretWord)
#define RANDOM_WORD

char g_secretWord[MAX_WORD_LENGTH];

void Entrance();
void ChooseWord();
void ClearScreen();

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

bool CorrectLetter(char letter)
{
    for (int i = 0; i < WORD_LENGTH; i++)
    {
        if (letter == g_secretWord[i])
        {
            return true;
        }
    }
    
    return false;
}

void ClearScreen()
{
    printf("\e[1;1H\e[2J");
}