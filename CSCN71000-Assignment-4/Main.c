#include "player.h"

int main(void)
{
    int mystery_number = 0;

    do
    {
        mystery_number = GetMysteryNumber();
    } while (!mystery_number);

    return 0;
}