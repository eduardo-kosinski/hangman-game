#include "hangman.h"

int main()
{
    char guess;
    char guessedLetters[MAX_WORD_LENGTH] = {0};
    int triesLeft = MAX_TRIES;
    int numGuessedLetters = 0;

    printEntrance();

#ifdef RANDOM_WORD
    char *secretWord = getRandomWord();
#else
    char *secretWord = chooseWord();
#endif // RANDOM_WORD

    char *guessedWord = initializeGuessedWord(strlen(secretWord));

    while (triesLeft)
    {
        do
        {
            printf("You have %d tries left.\n", triesLeft);
            printf("Guessed word: %s\n", guessedWord);
            printf("Tried letters: ");

            for (int i = 0; i < numGuessedLetters; i++)
                printf("%c ", guessedLetters[i]);

            printf("\nEnter your guess: ");
            scanf(" %c", &guess);
            clearScreen();
        } while (!isValidGuess(tolower(guess), guessedLetters, numGuessedLetters));

        guessedLetters[numGuessedLetters] = tolower(guess);
        numGuessedLetters++;

        if (isCorrectGuess(tolower(guess), secretWord, guessedWord))
            printf("Correct guess!\n");
        else
        {
            triesLeft--;
            printf("Incorrect guess!\n");
        }

        if (strcmp(secretWord, guessedWord) == NULL)
        {
            printf("Congratulations! You won!\n");
            printf("The word was %s\n", secretWord);
            break;
        }
    }

    // Show defeat message
    if (triesLeft == 0)
        printf("You lost! The word was %s\n", secretWord);

    free(secretWord);
    free(guessedWord);

    return 0;
}