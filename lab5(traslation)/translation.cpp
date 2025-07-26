#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int midX, int midY, int color) {
    setcolor(color);
    line(midX + x1, midY - y1, midX + x2, midY - y2);
    line(midX + x2, midY - y2, midX + x3, midY - y3);
    line(midX + x3, midY - y3, midX + x1, midY - y1);
}

void translateTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
                       int tx, int ty, int midX, int midY) {
    drawTriangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty, x3 + tx, y3 + ty, midX, midY, GREEN);
    outtextxy(20, 40, "Translated Triangle");

    printf("Translated Coordinates:\n");
    printf("(%d, %d)  (%d, %d)  (%d, %d)\n",
           x1 + tx, y1 + ty, x2 + tx, y2 + ty, x3 + tx, y3 + ty);
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    int tx, ty;

    printf("Enter coordinates of triangle:\n");
    printf("Point 1 (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Point 2 (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Point 3 (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    printf("Enter translation factors (tx ty): ");
    scanf("%d %d", &tx, &ty);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;

    line(0, midY, getmaxx(), midY);  // X-axis
    line(midX, 0, midX, getmaxy());  // Y-axis

    drawTriangle(x1, y1, x2, y2, x3, y3, midX, midY, WHITE);
    outtextxy(20, 20, "Original Triangle");

    printf("\nOriginal Coordinates:\n");
    printf("(%d, %d)  (%d, %d)  (%d, %d)\n", x1, y1, x2, y2, x3, y3);

    delay(1000);

    translateTriangle(x1, y1, x2, y2, x3, y3, tx, ty, midX, midY);

    getch();
    closegraph();
    return 0;
}

