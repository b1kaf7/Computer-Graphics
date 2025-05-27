#include <graphics.h>
#include <conio.h>
#include <dos.h>

// Function to draw a smiley face
void drawSmiley(int x, int y) {
    // Face (circle)
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(x, y, 50);
    floodfill(x, y, YELLOW);

    // Eyes
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x - 20, y - 20, 10, 15); // Left eye
    fillellipse(x + 20, y - 20, 10, 15); // Right eye

    // Mouth (arc)
    arc(x, y + 10, 210, 330, 30);
}

// Function to animate the smiley face
void animateSmiley() {
    int x = 50, y = 200;                    // Initial position of the smiley
    int maxWidth = getmaxx();              // Maximum width of the screen

    while (!kbhit()) {                     // Exit on key press
        cleardevice();                     // Clear previous smiley

        drawSmiley(x, y);                  // Draw new smiley at updated position
        delay(30);                         // Delay for animation

        x += 5;                            // Move the smiley to the right

        if (x > maxWidth - 50)             // If smiley reaches edge, reset position
            x = 50;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    animateSmiley();                       // Run the animation

    getch();
    closegraph();
    return 0;
}

