#include <graphics.h>
#include <stdio.h>
#include <math.h>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int midX, int midY, int color) {
    setcolor(color);
    line(midX + x1, midY - y1, midX + x2, midY - y2);
    line(midX + x2, midY - y2, midX + x3, midY - y3);
    line(midX + x3, midY - y3, midX + x1, midY - y1);
}

void translatePoint(int *x, int *y, int tx, int ty) {
    *x += tx;
    *y += ty;
}

void rotateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float theta) {
    float rad = theta * (3.1416 / 180);

    int tx1 = *x1, ty1 = *y1;
    int tx2 = *x2, ty2 = *y2;
    int tx3 = *x3, ty3 = *y3;

    *x1 = tx1 * cos(rad) - ty1 * sin(rad);
    *y1 = tx1 * sin(rad) + ty1 * cos(rad);

    *x2 = tx2 * cos(rad) - ty2 * sin(rad);
    *y2 = tx2 * sin(rad) + ty2 * cos(rad);

    *x3 = tx3 * cos(rad) - ty3 * sin(rad);
    *y3 = tx3 * sin(rad) + ty3 * cos(rad);
}

int main() {
    int x1, y1, x2, y2, x3, y3, xf, yf;
    float theta;

    printf("Enter triangle points:\n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("Enter fixed point (xf yf): ");
    scanf("%d %d", &xf, &yf);
    printf("Enter angle (degrees): ");
    scanf("%f", &theta);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int midX = getmaxx() / 2, midY = getmaxy() / 2;

    line(0, midY, getmaxx(), midY);
    line(midX, 0, midX, getmaxy());

    drawTriangle(x1, y1, x2, y2, x3, y3, midX, midY, WHITE);
    outtextxy(20, 20, "Original Triangle");

    translatePoint(&x1, &y1, -xf, -yf);
    translatePoint(&x2, &y2, -xf, -yf);
    translatePoint(&x3, &y3, -xf, -yf);

    drawTriangle(x1, y1, x2, y2, x3, y3, midX, midY, YELLOW);
    outtextxy(20, 40, "Translated Triangle");
    rotateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, theta);
    drawTriangle(x1, y1, x2, y2, x3, y3, midX, midY, RED);
    outtextxy(20, 60, "Rotated Triangle");
    translatePoint(&x1, &y1, xf, yf);
    translatePoint(&x2, &y2, xf, yf);
    translatePoint(&x3, &y3, xf, yf);
    drawTriangle(x1, y1, x2, y2, x3, y3, midX, midY, GREEN);
    outtextxy(20, 80, "Final Rotated Triangle");
    getch();
    closegraph();
    return 0;
}



