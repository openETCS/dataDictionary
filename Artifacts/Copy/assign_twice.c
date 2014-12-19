
#include <limits.h>

struct A
{
   unsigned int size;
   unsigned int pos;
};

typedef struct A A;


/*@
    requires \valid(a);
    requires length <= 64;
    requires a->pos + length <= UINT_MAX;
    requires a->pos + length <= a->size;

    assigns  a->pos;

    ensures  a->pos == \old(a->pos) + length;
*/
void foo(A* a, unsigned int length)
{
    a->pos += length;
}

/*@
    requires \valid(a);
    requires length <= 64;
    requires a->pos + length <= UINT_MAX;
    requires a->pos + length <= a->size;

    assigns  a->pos;

    ensures  a->pos == \old(a->pos) + length;
*/
void bar(A* a, unsigned int length)
{
    foo(a, length);
    a->pos -= length;
    foo(a, length);
}


