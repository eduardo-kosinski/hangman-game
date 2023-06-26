#include "hangman.h"

int main()
{
    char guessedWord[MAX_WORD_LENGTH];

    int tries = 0;
    char guess;
    bool correctGuess;

    // Opening
    Entrance();

    // Pick a random word from database or input word
#ifdef RANDOM_WORD
    char* secretWord = GetRandomWord();
#else 
    char* secretWord = ChooseWord();
#endif // RANDOM_WORD

    // Hide secret word into guessed word
    for (int i = 0; i < WORD_LENGTH; i++)
        guessedWord[i] = '_';

    guessedWord[WORD_LENGTH] = '\0';

    // Game loop
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
            if (guess == secretWord[i])
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
        else
        {
            printf("Correct guess!\n");
        }

        if (strcmp(secretWord, guessedWord) == 0)
        {
            printf("Congratulations! You won!\n");
            printf("The word was %s\n", secretWord);
            break;
        }
    }

    // Show defeat message
    if (tries == MAX_TRIES)
        printf("You lost! The word was %s\n", secretWord);

    free(secretWord);

    return 0;
}