
/*@
   requires \valid(a);
   assigns *a;

   behavior non_negative:
     assumes n >= 0;
     assigns *a;
     ensures *a == 0;
     ensures \result == 1;

   behavior negative:
     assumes n < 0;
     assigns \nothing;
     ensures \result == -1;

  complete behaviors;
  disjoint behaviors;
*/
int f(int* a, int n)
{
  if (n >= 0)
  {
    *a = 0;
    return 1;
  }
  else
  {
    return -1;
  }
}

struct X
{
  int* a;
  int  n;
};

typedef struct X X;

/*@
   requires \valid(x);
   requires \valid(x->a);
   requires \separated(x->a, &(x->n));
   assigns  *(x->a);

   behavior non_negative:
     assumes x->n >= 0;
     assigns *(x->a);
     ensures *(x->a) == 0;
     ensures \result == 1;

   behavior negative:
     assumes x->n < 0;
     assigns *(x->a);
     ensures \result == -1;

  complete behaviors;
  disjoint behaviors;
*/
int g(X* x)
{
  return f(x->a, x->n);
}



