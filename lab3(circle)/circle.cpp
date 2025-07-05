#include <graphics.h>
#include <stdio.h>
#include <math.h>

void plotCirclePoints(int xc, int yc, int x, int y, int midX, int midY) {
    putpixel(midX + xc + x, midY - (yc + y), WHITE);
    putpixel(midX + xc - x, midY - (yc + y), WHITE);
    putpixel(midX + xc + x, midY - (yc - y), WHITE);
    putpixel(midX + xc - x, midY - (yc - y), WHITE);
    putpixel(midX + xc + y, midY - (yc + x), WHITE);
    putpixel(midX + xc - y, midY - (yc + x), WHITE);
    putpixel(midX + xc + y, midY - (yc - x), WHITE);
    putpixel(midX + xc - y, midY - (yc - x), WHITE);

   printf("(%d, %d) (%d, %d) (%d, %d)  (%d, %d)\n",
                   xc + x, yc + y, xc - x, yc + y,   xc + x, yc - y, 
                   xc - x, yc - y);
}
void midpointCircle(int xc, int yc, int r, int midX, int midY) {
    int x = 0;
    int y = r;
    int p = 1 - r;

    plotCirclePoints(xc, yc, x, y, midX, midY);
    delay(50);

    while (x < y) {
        x++;
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * x + 1 - 2 * y;
        }

        plotCirclePoints(xc, yc, x, y, midX, midY);
        delay(50);
    }
}


int main() {
    int xc, yc, r;

    printf("Enter center of circle (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius of circle: ");
    scanf("%d", &r);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;

    line(0, midY, getmaxx(), midY);  // X-axis
    line(midX, 0, midX, getmaxy());  // Y-axis

    printf("\nPlotted coordinates (8-way symmetric points):\n");
    midpointCircle(xc, yc, r, midX, midY);

    getch();
    closegraph();
    return 0;
}
