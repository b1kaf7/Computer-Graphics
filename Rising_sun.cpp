#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawSun(int x, int y, int radius) {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(x, y, radius);
    floodfill(x, y, YELLOW);
}

void drawSky(int height) {
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(0, 0, getmaxx(), height);
}

void drawGround(int height) {
    setfillstyle(SOLID_FILL, GREEN);
    bar(0, height, getmaxx(), getmaxy());
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int sunX = getmaxx() / 2;
    int sunY = getmaxy(); // Start below the screen
    int radius = 30;
    int skyHeight = getmaxy() / 2;
    int groundHeight = skyHeight;

    // Sunrise animation
    for (int y = getmaxy(); y >= 100; y -= 2) {
        cleardevice();
        drawSky(skyHeight);
        drawGround(groundHeight);
        drawSun(sunX, y, radius);
        delay(30);
    }

    getch();
    closegraph();
    return 0;
}

