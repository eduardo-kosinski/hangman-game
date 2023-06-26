#include "hangman.h"

int main()
{
    //char secretWord[MAX_WORD_LENGTH];
    char guessedWord[MAX_WORD_LENGTH];

    int tries = 0;
    char guess;
    bool correctGuess;

    // Opening
    Entrance();

    // Pick a random word from database
#ifdef RANDOM_WORD
    char* secretWord = ChooseRandomWord();
#else  // RANDOM_WORD
    printf("Enter the secret word: ");
    scanf("%s", secretWord);
    printf("%s\n", secretWord);
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

    free(secretWord);

    // Show defeat message
    if (tries == MAX_TRIES)
        printf("You lost! The word was %s\n", secretWord);

    return 0;
}