#include <stdio.h>
#include <stdlib.h>

#include "shadowlib.h"


int main(int argc, char *argv[])
{
  int i, j;
  int x, y;
  printf("Enter two numbers.\nI'll send them to the shadow zone and then pull them back\n");
  scanf("%d %d", &i, &j);

  __shadowlib_insert(&i, i);
  __shadowlib_insert(&j, j);

  x = __shadowlib_get(&i);
  y = __shadowlib_get(&j);
  printf("Pulled back %d %d\n", x, y);

  return 0;
}
