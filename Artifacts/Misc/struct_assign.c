

struct Point
{
    int x;
    int y;
    int z;
};


typedef struct Point Point;

/*@
    requires \valid(p);

    assigns  p->x;
    assigns  p->y;
    assigns  p->z;

    ensures  p->x == 0;
    ensures  p->y == 0;
    ensures  p->z == 0;
*/
void init(Point* p)
{
    p->x = 0;
    p->y = 0;
    p->z = 0;
}

/*@
    requires \valid(p);

    assigns  *p;

    ensures  p->x == 0;
    ensures  p->y == 0;
    ensures  p->z == 0;
*/
void set_zero(Point* p)
{
    p->x = 0;
    p->y = 0;
    p->z = 0;
}

