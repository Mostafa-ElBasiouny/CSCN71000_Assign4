#include "player.h"

int main(void)
{
    int mystery_number = 0;

    do
    {
        mystery_number = GetMysteryNumber();
    } while (!mystery_number);

    do
    {
        printf("Incorrect guesses: %d\n", Invalid_Guesses);

        Guess guess = GetPlayerGuess(mystery_number);

        if (guess == Equal) return 0; // Quits if the guess is equal to the mystery number.

        IncrementInvalidGuesses();
        printf("\n");
    } while (!MaxAllowedGuesses());

    return 0;
}