#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>

int main() {
    float x, y, x1, y1, x2, y2, dx, dy, stepLength;
    int i;
    int gd = DETECT, gm; // Graphic mode initialize

    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE); // Set background color to white
    cleardevice();     // Clear the screen with the new background color

	printf("\nDigital Differential Analyzer Algorithm\n\n");
    printf("Enter the value of x1 and y1: ");
    scanf("%f%f", &x1, &y1);
    printf("Enter the value of x2 and y2: ");
    scanf("%f%f", &x2, &y2);

    dx = fabs(x2 - x1); // Use fabs for floating-point absolute value
    dy = fabs(y2 - y1);

    if (dx >= dy)
        stepLength = dx;
    else
        stepLength = dy;

    // Handle division by zero
    if (stepLength == 0) {
        printf("Both points are the same. No line to draw.\n");
        closegraph();
        return 0;
    }

    dx = dx / stepLength;
    dy = dy / stepLength;

    x = x1;
    y = y1;

    i = 1;
    while (i <= stepLength){
        putpixel(x, y, BLACK); 
        x = x + dx;
        y = y + dy;
    	i = i + 1;
    }

    delay(100000);
    closegraph();
    return 0;
}
