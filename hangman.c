#include "hangman.h"

int main()
{
    char guessedWord[MAX_WORD_LENGTH];
    int tries = 0;
    char guess;
    bool correctGuess;

    // Opening
    Entrance();

    // Pick a random word from database
    ChooseWord();

    for (int i = 0; i < WORD_LENGTH; i++)
        guessedWord[i] = '_';

    guessedWord[WORD_LENGTH] = '\0';

    while (tries < MAX_TRIES)
    {
        printf("You have %d tries left.\n", MAX_TRIES - tries);
        printf("Guessed word: %s\n", guessedWord);
        printf("Enter your guess: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        printf("%c\n", guess);

        correctGuess = false;

        for (int i = 0; i < WORD_LENGTH; i++)
        {
            if (guess == g_secretWord[i])
            {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        ClearScreen();

        if (!correctGuess)
        {
            tries++;
            printf("Incorrect guess!\n");
        }

        if (strcmp(g_secretWord, guessedWord) == 0)
        {
            printf("Congratulations! You won!\n");
            printf("The word was %s\n", g_secretWord);
            break;
        }
    }

    if (tries == MAX_TRIES)
        printf("You lost! The word was %s\n", g_secretWord);

    return 0;
}