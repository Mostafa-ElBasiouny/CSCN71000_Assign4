#include "player.h"

int Invalid_Guesses = 0;
int Guesses_List[MAX_GUESSES] = { -1, -1, -1, -1, -1, -1 }; // Initialize with negative one to differentiate between invalid and empty elements.
int Guesses_List_Count = 0;

// Allows the player to set the mystery number.
// Returns the mystery number if valid, otherwise zero.
int GetMysteryNumber(void)
{
	int mystery_number = 0;

	printf("Enter the mystery number from 1 to 1000 (inclusive): ");
	int result = scanf("%d", &mystery_number);

	if (result == 1 // Checks if scanf successfully matched a number.
		&& getchar() == '\n' // Checks if stdin does not contain any trailing characters.
		&& mystery_number >= 1 // Checks if the mystery number is greater than or equal to one.
		&& mystery_number <= 1000) // Checks if the mystery number is less than or equal to one thousand.
	{
		#if defined(_WIN32) || defined(_WIN64)
		system("cls"); // Windows specific command.
		#else
		system("clear"); // Unix specific command.
		#endif

		return mystery_number; // Returns the mystery number if valid.
	}

	if (result != 1) while (getchar() != '\n'); // Clears stdin.

	printf("Invalid mystery number, try again.\n");

	return 0; // Returns zero if the mystery number is invalid.
}

// Allows the player to enter his guess.
// Returns an enumerator based on the guess.
Guess GetPlayerGuess(int mystery_number)
{
	int guess = 0;

	printf("Enter the guess from 1 to 1000 (inclusive): ");
	int result = scanf("%d", &guess);

	if (result == 1 // Checks if scanf successfully matched a number.
		&& getchar() == '\n' // Checks if stdin does not contain any trailing characters.
		&& guess >= 1 // Checks if the guess is greater than or equal to one.
		&& guess <= 1000) // Checks if the guess is less than or equal to one thousand.
	{
		if (guess < mystery_number)
		{
			printf("The guess is too low.\n");
			UpdateGuesses(guess);
			return Lower;
		}
		else if (guess == mystery_number)
		{
			printf("You win.\n");
			return Equal;
		}
		else
		{
			printf("The guess is too high.\n");
			UpdateGuesses(guess);
			return Greater;
		}
	}

	if (result != 1) while (getchar() != '\n'); // Clears stdin.
	printf("Invalid guess, not a number or out of range.\n");
	UpdateGuesses(Invalid);

	return Invalid;
}

// Increments the invalid guesses counter.
void IncrementInvalidGuesses(void)
{
	Invalid_Guesses++;
}

// Checks if the maximum allowed guesses is reached.
// Returns true if reached, otherwise false.
bool MaxAllowedGuesses(void)
{
	if (Invalid_Guesses < MAX_GUESSES)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// Appends guess to guesses list.
void UpdateGuesses(int guess)
{
	Guesses_List[Guesses_List_Count] = guess;
	Guesses_List_Count++;
}

// Displays previous guesses.
void DisplayPreviousGuesses(void)
{
	printf("Previous guesses:");

	for (int i = 0; i < MAX_GUESSES; i++)
	{
		if (Guesses_List[i] == -1) printf(" _");
		else if (Guesses_List[i] == 0) printf(" X");
		else printf(" %d", Guesses_List[i]);

		if (i < MAX_GUESSES - 1) printf(", ");
		else printf("\n");
	}
}