#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 100
#define RANDOM_WORD

void printEntrance();
char *getRandomWord();
char *chooseWord();
char *initializeGuessedWord(size_t wordLength);
void drawHangman();
int isValidGuess(char guess, char* guessedLetters, int numGuessedLetters);
int isCorrectGuess(char letter, char* secretWord, char* guessedWord);
void clearScreen();

void printEntrance()
{
    printf("***********************\n");
    printf("* Welcome to Hangman! *\n");
    printf("***********************\n");
}

char *getRandomWord()
{
    FILE *f;
    char *secretWord = malloc(MAX_WORD_LENGTH * sizeof(char));

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

    srand(time(NULL));
    int random = rand() % wordCounter;

    for (int i = 0; i <= random; i++)
    {
        fscanf(f, "%s", secretWord);
    }

    fclose(f);
    return secretWord;
}

char *chooseWord()
{
    char *secretWord = malloc(MAX_WORD_LENGTH * sizeof(char));

    printf("Enter the secret word: ");
    scanf("%s", secretWord);

    return secretWord;
}

char *initializeGuessedWord(size_t wordLength)
{
    char *guessedWord = malloc(wordLength * sizeof(char));

    for (int i = 0; i < wordLength; i++)
        guessedWord[i] = '_';

    guessedWord[wordLength] = '\0';

    return guessedWord;
}

void drawHangman()
{

}

int isValidGuess(char guess, char* guessedLetters, int numGuessedLetters)
{
    if (!isalpha(guess))
    {
        printf("Invalid guess. Please enter a valid letter.\n");
        return 0;
    }
    
    for (int i = 0; i < numGuessedLetters; i++)
    {
        if (guessedLetters[i] == guess)
        {
           printf("You already guessed the letter '%c'. Please enter a different letter.\n", guess);
           return 0;
        }
    }

    return 1;
}

int isCorrectGuess(char guess, char* secretWord, char* guessedWord)
{
    int correctLetter = 0;

    for (int i = 0; i < strlen(secretWord); i++)
    {
        if (guess == tolower(secretWord[i]))
        {
            guessedWord[i] = guess;
            correctLetter = 1; 
        }
    }

    return correctLetter;
}

void clearScreen()
{
    printf("\e[1;1H\e[2J");
}