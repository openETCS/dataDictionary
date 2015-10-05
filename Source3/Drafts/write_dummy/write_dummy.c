
struct A { int qualifier; int dummy; };

typedef struct A A;

/*@
   logic integer writes_begin{L}(A* a) = 0;

   axiomatic writes_end_Axiomatic
   {
       logic integer writes_end{L}(A* a)
           reads a->qualifier;

       axiom writes_end_write{L}: \forall A* a;
           a->qualifier == 1 ==> writes_end(a) == writes_begin(a) + 1;

       axiom writes_end_skip{L}: \forall A* a;
           a->qualifier != 1 ==> writes_end(a) == writes_begin(a);
    }
*/

/*@
   requires \valid(a);
   assigns a->dummy;
*/
void write_dummy(A* a)
{
    /*@
       assigns a->dummy;

       behavior write:
           assumes a->qualifier == 1;
	   assigns a->dummy;
	   ensures writes_end(a) == writes_begin(a) + 1;

       behavior skip:
           assumes a->qualifier != 1;
	   assigns \nothing;
	   ensures writes_end(a) == writes_begin(a);

       complete behaviors;
       disjoint behaviors;
    */
    if(a->qualifier == 1)
    {
        /*@
	   requires a->qualifier == 1;
           assigns a->dummy;
	   ensures writes_end(a) == writes_begin(a) + 1;
	*/
	{ a->dummy == 1; }
	//@ assert writes_end(a) == writes_begin(a) + 1;
    }
}

