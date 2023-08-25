#include "common.h"
int func(unsigned int x, int y)
{
    return ((x + y > 0) ? x * func(x, y + 1) : 3);
}
int main(int argc, char *argv[])
{
    unsigned int x = 5;
    int y = -7;
    int c = 0;
    c = func(x, y);
    printf("c = %d\n", c);
    system("pause");
    return 0;
}
