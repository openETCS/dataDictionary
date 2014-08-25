
int global_state;

/*@
   assigns global_state;

   behavior non_negative:
     assumes n >= 0;
     assigns \nothing;
     ensures \result == 1;

   behavior negative:
     assumes n < 0;
     assigns global_state;
     ensures \result == 0;
     ensures global_state == -1;

  complete behaviors;
  disjoint behaviors;
*/
int f(int n)
{
  if (n >= 0)
  {
    return 1;
  }
  else
  {
    global_state = -1;
    return 0;
  }
}


/*@
   assigns global_state;

   behavior non_negative:
     assumes n >= 0;
     assigns global_state;
     ensures \result == 1;

   behavior negative:
     assumes n < 0;
     assigns global_state;
     ensures global_state == -1;
     ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int g(int n)
{
  return f(n);
}



