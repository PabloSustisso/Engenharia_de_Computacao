#include <float.h>
#include <stdio.h>

int main(void)
{
    int i;
    double eps, eps1;

    i = 0;
    eps = 1.0;
    eps1 = 0.0;
    do  {
        eps /= 2.0;
        eps1 = eps + 1.0;
        printf("%3d reduzida eps = %-10.10g \n", ++i, eps);
    } while ( eps1 > 1.0);

    printf("A maquina pensa que '%10.10g' eh igual a zero\n", eps);

    return 0;
    
}