

/*@
   predicate Positive(int a) = 0 < a;
*/

/*@
   predicate Positive(short a) = 0 < a;
*/

/*@
   requires Positive(a);

   assigns \nothing;

   ensures  Positive(\result);
*/
int foo(short a)
{
    return a;
}


struct Pair
{
    int first, second;
};

typedef struct Pair Pair;

/*@
  predicate Positive(Pair p) = Positive(p.first) && Positive(p.second);
*/


/*@
   requires Positive(a);
   assigns \nothing;
   ensures Positive(\result);
*/
Pair bar(int a)
{
    Pair p;
    p.first  = a;
    p.second = a;

    return p;
}
