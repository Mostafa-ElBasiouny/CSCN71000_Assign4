#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_GUESSES 6

extern int Invalid_Guesses;
extern int Guesses_List[MAX_GUESSES];
extern int Guesses_List_Count;

typedef enum Guess
{
    Invalid, // Invalid denotes zero/false hence being the first enumerator.
    Lower,
    Equal,
    Greater
} Guess;

int GetMysteryNumber(void);
Guess GetPlayerGuess(int);

void IncrementInvalidGuesses(void);
bool MaxAllowedGuesses(void);
void UpdateGuesses(int);
void DisplayPreviousGuesses(void);