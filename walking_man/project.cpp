#include <graphics.h>
#include <conio.h>


void drawStickMan(int x, int y) {
    setcolor(WHITE);  
    circle(x, y, 10);
    line(x, y + 10, x, y + 40);
    line(x, y + 20, x - 15, y + 30);
    line(x, y + 20, x + 15, y + 30);
    line(x, y + 40, x - 10, y + 60);
    line(x, y + 40, x + 10, y + 60);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setbkcolor(BLACK);
    cleardevice();

    int screenW = getmaxx();
    int screenH = getmaxy();
    int midY = screenH / 2;

    int startX = 20;
    int endX = screenW - 20;
    int y = midY - 60;
    int x = startX;
    int dx = 2;
    int baseSpeed = 2;

    while (!kbhit()) {
        screenW = getmaxx();
        screenH = getmaxy();
        midY = screenH / 2;
        endX = screenW - 20;
        y = midY - 60;

        cleardevice();

        setcolor(WHITE);
        line(0, midY, screenW - 1, midY);

        drawStickMan(x, y);

        setcolor(WHITE);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(x - 20, y - 40, "MAN");

//        setcolor(BLACK);
//        setfillstyle(SOLID_FILL, BLACK);
//
//		if (dx != 0) {
//    		bar(x - 25, y + 15, x - 5, y + 40);  // left arm and leg
//    		bar(x + 5, y + 20, x , y + 40);  // right arm and leg
//		}

//
//        delay(80);
//        x += dx;

        if (dx > 0) {
            int distanceFromStart = x - startX;
            int distanceToEnd = endX - x;

            if (distanceFromStart > 150 && distanceToEnd > 150) {
                dx = baseSpeed + 6;
            } else if (distanceToEnd < 100) {
                dx = baseSpeed;
            } else if (distanceFromStart > 150) {
                dx = baseSpeed + 3;
            } else {
                dx = baseSpeed;
            }
        } else {
            int distanceFromEnd = endX - x;
            int distanceToStart = x - startX;

            if (distanceFromEnd > 150 && distanceToStart > 150) {
                dx = -(baseSpeed + 6);
            } else if (distanceToStart < 100) {
                dx = -baseSpeed;
            } else if (distanceFromEnd > 150) {
                dx = -(baseSpeed + 3);
            } else {
                dx = -baseSpeed;
            }
        }

        if (x >= endX) {
            dx = -baseSpeed;
        } else if (x <= startX) {
            dx = baseSpeed;
        }
    }

    getch();
    closegraph();
    return 0;
}

