#include "hangman.h"

int main()
{
    int triesLeft = MAX_TRIES;
    char guess;

    // Opening
    printEntrance();

    // Pick a random word from database or input word
#ifdef RANDOM_WORD
    char *secretWord = getRandomWord();
#else
    char *secretWord = chooseWord();
#endif // RANDOM_WORD

    // Hide secret word into guessed word
    char *guessedWord = initializeGuessedWord(strlen(secretWord));

    // Game loop
    while (triesLeft)
    {
        printf("You have %d tries left.\n", triesLeft);
        printf("Guessed word: %s\n", guessedWord);
        printf("Enter your guess: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        clearScreen();

        // Checks if the guess is correct
        if (isCorrectGuess(guess, secretWord, guessedWord))
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
    if (!triesLeft)
        printf("You lost! The word was %s\n", secretWord);

    free(secretWord);
    free(guessedWord);

    return 0;
}