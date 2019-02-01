#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    float d = 4.0;
    char s[] = "HackerRank ";
    int new_i;
    float new_d;
    char new_s[1000];

    scanf("%d", &new_i);
    scanf("%f", &new_d);
    scanf("%s", new_s);

    printf("%d\n", new_i+i);
    printf("%f\n", (new_d + d));
    printf("%s\n", s);

    return 0;
}
