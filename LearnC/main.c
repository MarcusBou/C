#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char s[64];
    printf("Messaged to be reversed: ");
    scanf("%s", &s);
    int len = strlen(s);
    char result[len+1];

    char *pts = s + len - 1;

    for (int i = 0; i < len; i++, pts--) {
        result[i] = *pts;
    }

    result[len] = '\0';

    printf("Original string: %s\n", s);
    printf("Reversed string: %s\n", result);

    return 0;
}

