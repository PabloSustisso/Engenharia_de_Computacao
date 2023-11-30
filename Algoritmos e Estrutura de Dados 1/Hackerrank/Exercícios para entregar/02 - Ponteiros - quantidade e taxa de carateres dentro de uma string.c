#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void str (char string[], char c, int *p, float *f)
{
    int i = 0, qtd = 0;

    while (string[i] != '\0')
    {
        if (string[i] == c)
        {
            qtd++;
        }
        
        i++;
    }

    *p = qtd;
    *f = (float)*p / strlen(string);

}

int main() {

    char string[100], c;
    int p;
    float f;

    scanf("%s", string);
    scanf(" %c", &c);
    
    str(string, c, &p, &f);
    printf("%d\n", p);
    printf("%.2f\n", f);

    return 0;
}
