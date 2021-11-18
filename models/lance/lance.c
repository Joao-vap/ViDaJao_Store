#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "lance.h"

struct lance {
    char *pessoa;
    float valor;
    struct lance *prox, *ant;
    };
