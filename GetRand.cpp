#include <time.h>
#include <stdlib.h>

int GetRandomNumber(int min, int max)
{
    srand(time(NULL));
    int num = min + rand() % (max - min + 1);

    return num;
}