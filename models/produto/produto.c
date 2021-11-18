#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "produto.h"
#include "lance.h"

struct produto {
    char *nome_prod;
    Lance *lance_ini, *lance_fim;
};
