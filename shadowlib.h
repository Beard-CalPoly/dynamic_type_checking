#ifndef SHADOW_LIB_H
#define SHADOW_LIB_H

extern void __shadowlib_insert(void *ptr, int value);
extern int __shadowlib_get(void *ptr);

#endif // SHADOW_LIB_H
