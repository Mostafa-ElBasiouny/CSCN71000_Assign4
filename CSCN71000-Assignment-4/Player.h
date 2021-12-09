#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef enum Guess
{
    Invalid, // Invalid denotes zero/false hence being the first enumerator.
    Lower,
    Equal,
    Greater
} Guess;

int GetMysteryNumber(void);
Guess GetPlayerGuess(int);