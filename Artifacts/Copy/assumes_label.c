
struct vector
{
    int* addr;
    unsigned int sz;
    unsigned int cap;
};

typedef struct vector vector;


/*@
  predicate invariant(vector* v) =
         v->sz <= v->cap &&
         \valid(v->addr + (0..v->cap-1)) &&
         \separated(v, v->addr + (0..v->cap-1));

  predicate full(vector* v) = (v->sz == v->cap);
*/

/*@
    requires \valid(v);
    requires invariant(v);

    assigns v->sz;
    assigns v->addr[v->sz];

    behavior enough_space:
        assumes !full(v);

        assigns v->sz;
        assigns v->addr[v->sz];

        ensures \result == 1;
        ensures v->sz == \old(v->sz) + 1;
        ensures v->addr[\old(v->sz)] == x;
        ensures \forall integer i; 0 <= i < \old(v->sz)  ==>  v->addr[i] == \old(v->addr[i]);


   behavior no_space:
       assumes full(v);

       assigns \nothing;

       ensures \result == 0;

   complete behaviors;
   disjoint behaviors;
*/
int push_back(vector* v, int x)
{
    if (v->sz < v->cap)
    {
        v->addr[v->sz] = x;
        v->sz++;
        return 1;
    }
    else
    {
        return 0;
    }
}

