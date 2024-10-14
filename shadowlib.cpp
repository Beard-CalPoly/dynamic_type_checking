#include <map>
#include <iostream>


extern "C" void __shadowlib_insert(void *ptr, int value);
extern "C" int __shadowlib_get(void *ptr);


std::map<void *, int> shadowmem;


//void __shadowlib_initialize


void __shadowlib_insert(void *ptr, int value)
{
  shadowmem[ptr] = value;
}

int __shadowlib_get(void *ptr)
{
  return shadowmem[ptr];
}

/*
int main(int argc, char **argv)
{
    std::map<void *, int> m;
    int a;
    char b;

    m[&a] = 1;
    m[&b] = 2;


    std::cout << "A value " << m[&a] << " B value " << m[&b] << std::endl;


    return 0;
}
*/
