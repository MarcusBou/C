#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[64];
    printf("Messaged to be counted: ");
    scanf("%s", &s);
    int len = strlen(s);
    printf("Count of string %s is %d", &s, len);
    return 0;
}
