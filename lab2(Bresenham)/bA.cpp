#include <graphics.h>
#include <stdio.h>
#include <math.h>
void BLA(int x1, int y1, int x2, int y2, int midX, int midY) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1;
    int y = y1;
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;
    if (dx >= dy) {
        int p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            putpixel(midX + x, midY - y, WHITE);
            delay(10);
            printf("(%d, %d)\n", x, y);
            x += sx;
            if (p < 0) {
                p = p + 2 * dy;
            } else {
                y += sy;
                p = p + 2 * (dy - dx);
            }
        }
    }
    else {
        int p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) {
            putpixel(midX + x, midY - y, WHITE);
            delay(10);
            printf("(%d, %d)\n", x, y);
            y += sy;
            if (p < 0) {
                p = p + 2 * dx;
            } else {
                x += sx;
                p = p + 2 * (dx - dy);
            }
        }
    }
}
int main() {
    int x1, y1, x2, y2;

    printf("Enter x1 y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter x2 y2: ");
    scanf("%d %d", &x2, &y2);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;

    line(0, midY, getmaxx(), midY); 
    line(midX, 0, midX, getmaxy()); 

    BLA(x1, y1, x2, y2, midX, midY);

    getch();
    closegraph();
    return 0;
}


