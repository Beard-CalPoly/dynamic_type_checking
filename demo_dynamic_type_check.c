#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "shadowlib.h"

#undef  INSTRUMENTATION
#define INSTRUMENTATION

/* Fake overloaded add
 * ty : 0 => Integers
 * ty : 1 => Floats
 *
 * Given the type, do the right casting to do an add
 */
void fake_overload_add(void *dst, void *op1, void *op2, unsigned int ty)
{
#ifdef INSTRUMENTATION
  int __instvalue;
#endif

  if(ty == 0)
  {
#ifdef INSTRUMENTATION
    __instvalue = __shadowlib_get(op1);
    assert(__instvalue == 0 && "This wasn't an int!");

    __instvalue = __shadowlib_get(op1);
    assert(__instvalue == 0 && "This wasn't an int!");

    __shadowlib_insert(dst, 0);
#endif
    *(int *)dst = *(int *)op1 + *(int *)op2;
  }
  else if(ty == 1)
  {
#ifdef INSTRUMENTATION
    __instvalue = __shadowlib_get(op1);
    assert(__instvalue == 1 && "This wasn't a float!");

    __instvalue = __shadowlib_get(op1);
    assert(__instvalue == 1 && "This wasn't a float!");

    __shadowlib_insert(dst, 1);
#endif
    *(float *)dst = *(float *)op1 + *(float *)op2;
  }
}


int main(int argc, char *argv[])
{
#ifdef INSTRUMENTATION
  int __instvalue;
#endif

  int x, y, z, tmp1, tmp2;
  float f1, f2, f3, ft1, ft2;
  printf("Enter two integers to be added together\n");
  scanf("%d %d", &tmp1, &tmp2);
#ifdef INSTRUMENTATION
  // This is a little weird because I'm reading from scanf
  // and then just copying because I want to make the store
  // explicit here. These would also be interleaved but
  // I'm putting them both here because ifdefs are nasty looking

  __shadowlib_insert((void*)&x, 0);
  __shadowlib_insert((void*)&y, 0);
#endif
  x = tmp1;
  y = tmp2;
  fake_overload_add(&z, &x, &y, 0);

#ifdef INSTRUMENTATION
 __instvalue = __shadowlib_get((void*)&z);
 assert(__instvalue == 0 && "This wasn't an int!");

 __instvalue = __shadowlib_get((void*)&x);
 assert(__instvalue == 0 && "This wasn't an int!");

  __instvalue = __shadowlib_get((void*)&y);
 assert(__instvalue == 0 && "This wasn't an int!");
#endif
  printf("%d = %d + %d\n", z, x, y);


  printf("Enter two floats to be added together\n");
  scanf("%f %f", &ft1, &ft2);

#ifdef INSTRUMENTATION
  __shadowlib_insert((void*)&f2, 1);
  __shadowlib_insert((void*)&f3, 1);
#endif
  f2 = ft1;
  f3 = ft2;
  fake_overload_add(&f1, &f2, &f3, 1); // TODO Change to a 0 to make it fail

#ifdef INSTRUMENTATION
    __instvalue = __shadowlib_get((void*)&f1);
    assert(__instvalue == 1 && "This wasn't a float!");

    __instvalue = __shadowlib_get((void*)&f2);
    assert(__instvalue == 1 && "This wasn't a float!");

    __instvalue = __shadowlib_get((void*)&f3);
    assert(__instvalue == 1 && "This wasn't a float!");
#endif
  printf("%f = %f + %f\n", f1, f2, f3);

  return 0;
}
