#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c = 'Q';
    char *pc;
    void *p;
    pc = &c;
    p = &c;
    printf("Char: %c\n", *pc);
    printf("ponteiro: %p\n", p);
    p = &pc; // endereço do ponteiro
    printf("Char: %c\n", *pc);
    printf("ponteiro: %p\n", p);
    return 0;
}