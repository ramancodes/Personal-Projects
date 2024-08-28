#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
// #include <iostream.h>

class bresen
{
    float x, y, x1, y1, x2, y2, dx, dy, m, c, xend;

public:
    void get();
    void cal();
};
void main()
{
    bresen b;
    b.get();
    b.cal();
    getch();
}
Void bresen ::get()
{
    print("Enter start & end points");
    print("enter x1, y1, x2, y2");
    scanf("%f%f%f%f", sx1, sx2, sx3, sx4)
}
void bresen ::cal()
{
    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, " ");
    /* read result of initialization */
    errorcode = graphresult();
    if (errorcode ! = grOK) /*an error occurred */
    {
        printf ("Graphics error: %s \n", grapherrormsg (errorcode));  
        printf ("Press any key to halt:");  
        getch ();  
        exit (1); /* terminate with an error code */
    }
    dx = x2 - x1;
    dy = y2 - y1;
    m = dy / dx;
    c = y1 - (m * x1);
    if (dx < 0)
    {
        x = x2;
        y = y2;
        xend = x1;
    }
    else
    {
        x = x1;
        y = y1;
        xend = x2;
    }
    while (x <= xend)
    {
        putpixel(x, y, RED);
        y++;
        y = (x * x) + c;
    }
}