#include <graphics.h>
#include <stdio.h>
#include <math.h>

void DDA(int a1, int b1, int a2, int b2, int midX, int midY) {
    int da = a2 - a1;
    int db = b2 - b1;
    int steps = abs(da) > abs(db) ? abs(da) : abs(db);
    float ainc = da / (float)steps;
    float binc = db / (float)steps;
    float a = a1;
    float b = b1;
    for (int i = 0; i <= steps; i++) {
        putpixel(midX + round(a), midY - round(b), WHITE);
        a += ainc;
        b += binc;
    }
}

int main() {
    int a1, b1, a2, b2;
    printf("Enter a1 b1: ");
    scanf("%d %d", &a1, &b1);
    printf("Enter a2 b2: ");
    scanf("%d %d", &a2, &b2);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;
    line(0, midY, getmaxx(), midY); // A-axis (was X-axis)
    line(midX, 0, midX, getmaxy()); // B-axis (was Y-axis)
    DDA(a1, b1, a2, b2, midX, midY);
    getch();
    closegraph();
    return 0;
}

