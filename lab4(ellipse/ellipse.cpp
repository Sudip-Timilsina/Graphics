#include <graphics.h>
#include <stdio.h>
#include <math.h>
void plotEllipsePoints(int xc, int yc, int x, int y, int midX, int midY) {
    putpixel(midX + xc + x, midY - (yc + y), WHITE);
    putpixel(midX + xc - x, midY - (yc + y), WHITE);
    putpixel(midX + xc + x, midY - (yc - y), WHITE);
    putpixel(midX + xc - x, midY - (yc - y),         WHITE);
    printf("(%d, %d)  (%d, %d)  (%d, %d)  (%d, %d)\n",
           xc + x, yc + y, xc - x, yc + y,
           xc + x, yc - y, xc - x, yc - y);
}
void midpointEllipse(int xc, int yc, int rx, int ry, int midX, int midY) {
    int x = 0;
    int y = ry;
    int rx2 = rx * rx;
    int ry2 = ry * ry;
    int p1 = ry2 - (rx2 * ry) + (rx2 / 4);
    int dx = 2 * ry2 * x;
    int dy = 2 * rx2 * y;
   
    while (dx < dy) {
        plotEllipsePoints(xc, yc, x, y, midX, midY);
        delay(50);
        x++;
        dx += 2 * ry2;
        if (p1 < 0) {
            p1 += dx + ry2;
        } else {
            y--;
            dy -= 2 * rx2;
            p1 += dx - dy + ry2;
        }
    }
    int p2 = (int)(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
    while (y >= 0) {
        plotEllipsePoints(xc, yc, x, y, midX, midY);
        delay(50);
        y--;
        dy -= 2 * rx2;
        if (p2 > 0) {
            p2 -= dy - rx2;
        } else {
            x++;
            dx += 2 * ry2;
            p2 += dx - dy + rx2;
        }
    }
}

int main() {
    int xc, yc, rx, ry;
    printf("Enter center of ellipse (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter horizontal radius (rx): ");
    scanf("%d", &rx);
    printf("Enter vertical radius (ry): ");
    scanf("%d", &ry);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;
    line(0, midY, getmaxx(), midY);
    line(midX, 0, midX, getmaxy());

    printf("\nPlotted coordinates (symmetric ellipse points):\n");
    midpointEllipse(xc, yc, rx, ry, midX, midY);

    getch();
    closegraph();
    return 0;
}
