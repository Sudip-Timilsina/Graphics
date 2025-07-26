#include <graphics.h>
#include <stdio.h>

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

void scaleTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float sx, float sy) {
    *x1 = (int)(*x1 * sx);
    *y1 = (int)(*y1 * sy);
    *x2 = (int)(*x2 * sx);
    *y2 = (int)(*y2 * sy);
    *x3 = (int)(*x3 * sx);
    *y3 = (int)(*y3 * sy);
}

int main() {
    int x1, y1, x2, y2, x3, y3, xf, yf;
    float sx, sy;

    printf("Enter triangle points:\n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("Enter fixed point (xf yf): ");
    scanf("%d %d", &xf, &yf);
    printf("Enter scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

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

    scaleTriangle(&x1, &y1, &x2, &y2, &x3, &y3, sx, sy);
    drawTriangle(x1, y1, x2, y2, x3, y3, midX, midY, RED);
    outtextxy(20, 60, "Scaled Triangle");

    translatePoint(&x1, &y1, xf, yf);
    translatePoint(&x2, &y2, xf, yf);
    translatePoint(&x3, &y3, xf, yf);
    
    drawTriangle(x1, y1, x2, y2, x3, y3, midX, midY, GREEN);
    outtextxy(20, 80, "Final Scaled Triangle");

    getch();
    closegraph();
    return 0;
}

