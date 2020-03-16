#include <stdio.h>
#include <stdlib.h>
#include "nh_list.h"

int main()
{
    char *c1 = "hello";
    char *c2 = "hello";
    printf("%d\n", (c1 - c2));
}