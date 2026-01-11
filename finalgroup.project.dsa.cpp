//DSA GROUP PROJECT BY SETC23, SETC33, SETC37, SETC42
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void drawRock(int x, int y) {
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    fillellipse(x, y, 50, 40);
}
void drawPaper(int x, int y) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(x - 40, y - 50, x + 40, y + 50);
    setcolor(LIGHTGRAY);
    rectangle(x - 40, y - 50, x + 40, y + 50);
}
void drawScissors(int x, int y) {
    setcolor(LIGHTRED);
    line(x - 30, y - 30, x + 30, y + 30);
    line(x + 30, y - 30, x - 30, y + 30);
    circle(x - 35, y + 35, 8);
    circle(x + 35, y - 35, 8);
}
void drawChoice(int choice, int x, int y) {
    if (choice == 1)
        drawRock(x, y);
    else if (choice == 2)
        drawPaper(x, y);
    else if (choice == 3)
        drawScissors(x, y);
}
void showText(int x, int y, char *text, int color, int size) {
    setcolor(color);
    settextstyle(3, 0, size);
    outtextxy(x, y, text);
}
void drawButton(int left, int top, int right, int bottom, char *label) {
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(left, top, right, bottom);
    setcolor(WHITE);
    rectangle(left, top, right, bottom);
    settextstyle(3, 0, 2);
    outtextxy(left + 25, top + 15, label);
}
int isClicked(int left, int top, int right, int bottom, int x, int y) {
    return (x >= left && x <= right && y >= top && y <= bottom);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\");
    srand(time(0));

    int userChoice = 0, compChoice, result;
    int x, y;

    while (1) {
        cleardevice();
        showText(180, 70, "ROCK  PAPER  SCISSORS", YELLOW, 3);
        showText(200, 120, "Click your choice below", LIGHTCYAN, 2);
        drawButton(100, 200, 220, 260, "ROCK");
        drawButton(260, 200, 380, 260, "PAPER");
        drawButton(420, 200, 540, 260, "SCISSORS");
        while (!ismouseclick(WM_LBUTTONDOWN));
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (isClicked(100, 200, 220, 260, x, y))
            userChoice = 1;
        else if (isClicked(260, 200, 380, 260, x, y))
            userChoice = 2;
        else if (isClicked(420, 200, 540, 260, x, y))
            userChoice = 3;
        else
            continue;
        compChoice = (rand() % 3) + 1;

        cleardevice();
        showText(150, 100, "You", CYAN, 3);
        showText(500, 100, "Computer", CYAN, 3);

        drawChoice(userChoice, 200, 250);
        drawChoice(compChoice, 550, 250);

        if (userChoice == compChoice)
            result = 0;
        else if ((userChoice == 1 && compChoice == 3) ||
                 (userChoice == 2 && compChoice == 1) ||
                 (userChoice == 3 && compChoice == 2))
            result = 1;
        else
            result = -1;

        if (result == 0)
            showText(250, 400, "It's a DRAW!", YELLOW, 3);
        else if (result == 1)
            showText(270, 400, "You WIN!", GREEN, 3);
        else
            showText(270, 400, "You LOSE!", RED, 3);

        showText(200, 450, "Click anywhere to play again, or press ESC to exit.", LIGHTGRAY, 1);

        int exitFlag = 0;
        while (1) {
            if (kbhit() && getch() == 27) { 
                exitFlag = 1;
                break;
            }
            if (ismouseclick(WM_LBUTTONDOWN)) {
                clearmouseclick(WM_LBUTTONDOWN);
                break;
            }
        }
        if (exitFlag)
            break;
    }

    closegraph();
    return 0;
}

