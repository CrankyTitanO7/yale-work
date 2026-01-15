#include <stdio.h>
int main()
{
    char answer;
    printf("Are you ready? ");
    answer = getchar();
    if (answer == 'y')
    {
        printf("Welcome to 223!\n");
    }
    else
    {
        printf("Maybe later...\n");
    }
    return 0;
}
