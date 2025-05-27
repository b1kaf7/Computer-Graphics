#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawCar(int x, int y) {
    // Draw the car body
    rectangle(x, y, x + 100, y + 40);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(x + 1, y + 1, WHITE);

    // Draw the windows
    rectangle(x + 10, y + 20, x + 90, y);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    floodfill(x + 11, y - 1, WHITE);

    // Draw the wheels
    circle(x + 20, y + 40, 10); // Left wheel
    circle(x + 80, y + 40, 10); // Right wheel
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x + 20, y + 41, WHITE);
    floodfill(x + 80, y + 41, WHITE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 0;
    int y = getmaxy() - 100;

    while (!kbhit()) {  // Loop until a key is pressed
        cleardevice();
        drawCar(x, y);
        delay(30);
        x += 5;

        if (x > getmaxx()) {
            x = 0; // Reset to the left side
        }
    }

    closegraph();
    return 0;
}

