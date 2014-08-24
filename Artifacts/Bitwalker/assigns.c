
/*@
   requires \valid(a);
   assigns *a;

   behavior non_negative:
     assumes n >= 0;
     assigns *a;
     ensures \result == 1;

   behavior negative:
     assumes n < 0;
     assigns \nothing;
     ensures \result == -1;
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

