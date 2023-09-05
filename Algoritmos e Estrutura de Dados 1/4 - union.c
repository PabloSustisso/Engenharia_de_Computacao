#include <stdio.h>
#include <string.h>

// typedef union
// {
//     int val_int;
//     long val_long;
//     double val_double;
// } umpratodos;

// int main()
// {
//     umpratodos u;

//     u.val_int = 15;
//     printf("%d\n", u.val_int);

//     u.val_double = 1.38;
//     printf("%g\n", u.val_double);
//     printf("%d\n", u.val_int);

//     return 0;
// }

typedef union
{
    long nro_id;
    char char_id[20];
} identificador;

typedef struct
{
    char marca[20];
    identificador id;
    int tipo;
} inventario;

int main()
{
    inventario inv;
    strcpy(inv.marca, "Doli");
    inv.id.nro_id = 5678;

    printf("%d %s", inv.id.nro_id, inv.marca);

    return 0;
}