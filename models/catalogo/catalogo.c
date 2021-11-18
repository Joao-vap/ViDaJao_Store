#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "lance.h"
#include "produto.h"
#include "catalogo.h"

struct catalogo {
    Produto *produt;
    struct catalogo *prox, *ant;
};