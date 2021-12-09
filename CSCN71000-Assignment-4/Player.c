#include "player.h"

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