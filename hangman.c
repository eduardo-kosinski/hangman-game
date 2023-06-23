#include "hangman.h"

int main()
{
    // Opening
    Entrance();

    // Pick a random word from database
    ChooseWord();

    // Hide secret word into guessed word
    BlankGuessedWord();

    // Game loop
    WordGuessing();

    // Show defeat message
    CheckLosing();

    return 0;
}