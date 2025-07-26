#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int midX, int midY, int color) {
    setcolor(color);
    line(midX + x1, midY - y1, midX + x2, midY - y2);
    line(midX + x2, midY - y2, midX + x3, midY - y3);
    line(midX + x3, midY - y3, midX + x1, midY - y1);
}

void translatePoint(int *x, int *y, int tx, int ty) {*x += tx;
    *y += ty;}

void shearTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float shx, float shy) {
    int sx1 = *x1 + shx * (*y1);
    int sy1 = shy * (*x1) + *y1;
    int sx2 = *x2 + shx * (*y2);
    int sy2 = shy * (*x2) + *y2;
    int sx3 = *x3 + shx * (*y3);
    int sy3 = shy * (*x3) + *y3;

    *x1 = sx1;
    *y1 = sy1;
    *x2 = sx2;
    *y2 = sy2;
    *x3 = sx3;
    *y3 = sy3;
}

int main() {
    int x1, y1, x2, y2, x3, y3, xf, yf;
    float shx, shy;
    printf("Enter triangle points:\n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("Enter fixed point (xf yf): ");
    scanf("%d %d", &xf, &yf);

    printf("Enter shear factors (shx shy): ");
    scanf("%f %f", &shx, &shy);

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

    shearTriangle(&x1, &y1, &x2, &y2, &x3, &y3, shx, shy);
    drawTriangle(x1, y1, x2, y2, x3, y3, midX, midY, RED);
    outtextxy(20, 60, "Sheared Triangle");

    translatePoint(&x1, &y1, xf, yf);
    translatePoint(&x2, &y2, xf, yf);
    translatePoint(&x3, &y3, xf, yf);
    drawTriangle(x1, y1, x2, y2, x3, y3, midX, midY, GREEN);
    outtextxy(20, 80, "Final Sheared Triangle");
    getch();
    closegraph();
    return 0;
}

