#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function to convert degrees to radians
float degrees_to_radian(float degrees) {
    return degrees * (M_PI / 180.0);
}

// Main Function
int main() {
    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set background color to white
    setbkcolor(WHITE);
    cleardevice(); // Clear the screen with the new background color

    // Variables for the initial coordinates of the triangle
    int x1, x2, y1, y2, x3, y3;
    
    // Get the initial coordinates
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third point (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Draw the initial triangle
    setcolor(BLACK);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    delay(1000);

    // Display menu
    int choice;
    printf("Choose the transformation:\n");
    printf("1. Translation \n");
    printf("2. Scaling \n");
    printf("3. Rotation\n");
    printf("4. Reflection\n");
    printf("5. Shearing \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    cleardevice(); // Clear screen before drawing transformed triangle

    switch (choice) {
        case 1: { // Translation
            int tx, ty;
            printf("Enter the translation factors (tx ty): ");
            scanf("%d %d", &tx, &ty);

            x1 += tx; y1 += ty;
            x2 += tx; y2 += ty;
            x3 += tx; y3 += ty;

            setcolor(RED);
            line(x1, y1, x2, y2);
            line(x2, y2, x3, y3);
            line(x3, y3, x1, y1);
            break;
        }
        case 2: { // Scaling
            float sx, sy;
            printf("Enter the scaling factors (sx sy): ");
            scanf("%f %f", &sx, &sy);

            x1 = (int)(x1 * sx); y1 = (int)(y1 * sy);
            x2 = (int)(x2 * sx); y2 = (int)(y2 * sy);
            x3 = (int)(x3 * sx); y3 = (int)(y3 * sy);

            setcolor(RED);
            line(x1, y1, x2, y2);
            line(x2, y2, x3, y3);
            line(x3, y3, x1, y1);
            break;
        }
        case 3: { // Rotation
            float angle;
            printf("Enter the rotation angle (in degrees): ");
            scanf("%f", &angle);
            float radian = degrees_to_radian(angle);

            int new_x1 = (int)(x1 * cos(radian) - y1 * sin(radian));
            int new_y1 = (int)(x1 * sin(radian) + y1 * cos(radian));
            int new_x2 = (int)(x2 * cos(radian) - y2 * sin(radian));
            int new_y2 = (int)(x2 * sin(radian) + y2 * cos(radian));
            int new_x3 = (int)(x3 * cos(radian) - y3 * sin(radian));
            int new_y3 = (int)(x3 * sin(radian) + y3 * cos(radian));

            setcolor(RED);
            line(new_x1, new_y1, new_x2, new_y2);
            line(new_x2, new_y2, new_x3, new_y3);
            line(new_x3, new_y3, new_x1, new_y1);
            break;
        }
        case 4: { // Reflection
            int axis;
            printf("1. X-axis\n2. Y-axis\nEnter your choice: ");
            scanf("%d", &axis);

            int screen_width = getmaxx();
            int screen_height = getmaxy();

            if (axis == 1) { // Reflect over X-axis
                y1 = screen_height - y1;
                y2 = screen_height - y2;
                y3 = screen_height - y3;
            } else if (axis == 2) { // Reflect over Y-axis
                x1 = screen_width - x1;
                x2 = screen_width - x2;
                x3 = screen_width - x3;
            } else {
                printf("Invalid choice\n");
                break;
            }

            setcolor(RED);
            line(x1, y1, x2, y2);
            line(x2, y2, x3, y3);
            line(x3, y3, x1, y1);
            break;
        }
        case 5: { // Shearing
            float shx, shy;
            printf("Enter the shearing factors (shx shy): ");
            scanf("%f %f", &shx, &shy);

            int new_x1 = x1 + (int)(shx * y1);
            int new_y1 = y1 + (int)(shy * x1);
            int new_x2 = x2 + (int)(shx * y2);
            int new_y2 = y2 + (int)(shy * x2);
            int new_x3 = x3 + (int)(shx * y3);
            int new_y3 = y3 + (int)(shy * x3);

            setcolor(RED);
            line(new_x1, new_y1, new_x2, new_y2);
            line(new_x2, new_y2, new_x3, new_y3);
            line(new_x3, new_y3, new_x1, new_y1);
            break;
        }
        default:
            printf("Invalid choice\n");
    }

    delay(300000);
    closegraph();
    return 0;
}
