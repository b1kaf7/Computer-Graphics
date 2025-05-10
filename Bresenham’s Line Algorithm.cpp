#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
int main()
{
    float x, y, x1, y1, x2, y2, dx, dy, stepLength;
    int i;
    int gd = DETECT, gm; // graphic mode initialize

    initgraph(&gd, &gm, NULL);

    printf("Enter the value of x1 and y1 : ");
    scanf("%f%f", &x1, &y1);
    printf("Enter the value of x2 and y2: ");
    scanf("%f%f", &x2, &y2);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dx >= dy)
        stepLength = dx;
    else
        stepLength = dy;

    dx = dx / stepLength;
    dy = dy / stepLength;

    x = x1;
    y = y1;

    i = 1;
    while (i <= stepLength)
    {
        putpixel(x, y, WHITE);
        x = x + dx;
        y = y + dy;
        i = i + 1;
    }
    delay(100000);
    // getch();
    closegraph();
    return 0;
}