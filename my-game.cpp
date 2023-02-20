// Game Name: Frenchie Gone Hungry!
// Written by: Brittany Avila
// Date: Nov. 16, 2022
//
// Instructions: Move your mouse to move dog, and get the treats. DONT GET HIT 
// BY THE POOP!!
//

#include "graphics.h"
#include <string>
#include <random>

using namespace std;

const int BACKGROUND_COLOR = LIGHTGREEN;
const int TEXT_COLOR = WHITE;
const int END_COLOR = RED;
const int FRENCHIE_BOX = LIGHTGRAY;
const int BONE_COLOR = YELLOW;
const int POOP_COLOR = BROWN;

random_device myEngine;
uniform_real_distribution<double> randomReal(30, 870);

void welcomeScreen();
void showScore(int);

int main()
{

    int score;
    bool keepGoing = true;
    char keyPressed;

    struct screenObject {
        int x, y, prevX, prevY;
    };

    // frenchie screen object 
    screenObject frenchiebox1, frenchiebox2;
    frenchiebox1.x = 900;
    frenchiebox1.y = 900;

    frenchiebox2.x = 900;
    frenchiebox2.y = 900;

    // bone screen object
    screenObject bone1, bone2, bone3;
    bone1.x = randomReal(myEngine);
    bone1.y = 100;

    bone2.x = randomReal(myEngine);
    bone2.y = 100;

    bone3.x = randomReal(myEngine);
    bone3.y = 100;

    // poop screen object 
    screenObject poop1, poop2, poop3;
    poop1.x = randomReal(myEngine);
    poop1.y = 100;

    poop2.x = randomReal(myEngine);
    poop2.y = 100;

    poop3.x = randomReal(myEngine);
    poop3.y = 100;



    // window title
    initwindow(1000, 1000, (char*)"Frenchie Gone Hungry ", 10, 10);

    welcomeScreen();

    bool playAgain = true;

    //
    // -------- Main "Play Again" loop
    //
    do {

        // show score 
        int score;
        score = 0;


        // 
        // -------- Main "Keep Going" loop
        // 
        keepGoing = true;
        while (keepGoing) {
            delay(50);

            // position of frenchie 
            frenchiebox1.prevX = frenchiebox1.x;
            frenchiebox1.prevY = frenchiebox1.y;
            frenchiebox2.prevX = frenchiebox2.x;
            frenchiebox2.prevY = frenchiebox2.y;

            // bone position 
            bone1.prevX = bone1.x;
            bone1.prevY = bone1.y;
            bone2.prevX = bone2.x;
            bone2.prevY = bone2.y;
            bone3.prevX = bone3.x;
            bone3.prevY = bone3.y;

            // poop position 
            // bone position 
            poop1.prevX = poop1.x;
            poop1.prevY = poop1.y;
            poop2.prevX = poop2.x;
            poop2.prevY = poop2.y;
            poop3.prevX = poop3.x;
            poop3.prevY = poop3.y;




            // tracking mouse 
            frenchiebox1.x = mousex();

            // draw frenchie again if moved 
            if (frenchiebox1.x != frenchiebox1.prevX) {
                setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
                bar(frenchiebox1.prevX - 25, frenchiebox1.prevY - 25, frenchiebox1.prevX + 25, frenchiebox1.prevY + 25);
                setfillstyle(SOLID_FILL, FRENCHIE_BOX);
                bar(frenchiebox1.x - 25, frenchiebox1.y - 25, frenchiebox1.x + 25, frenchiebox1.y + 25);

                setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
                bar(frenchiebox1.prevX - 45, frenchiebox1.prevY - 45, frenchiebox1.prevX - 15, frenchiebox1.prevY - 20);
                setfillstyle(SOLID_FILL, FRENCHIE_BOX);
                bar(frenchiebox1.x - 45, frenchiebox1.y - 45, frenchiebox1.x - 15, frenchiebox1.y - 20);

                setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
                bar(frenchiebox1.prevX + 45, frenchiebox1.prevY - 45, frenchiebox1.prevX + 15, frenchiebox1.prevY - 20);
                setfillstyle(SOLID_FILL, FRENCHIE_BOX);
                bar(frenchiebox1.x + 45, frenchiebox1.y - 45, frenchiebox1.x + 15, frenchiebox1.y - 20);
            }
            // reset treat position 

            if (bone1.y > 870) {

                bone1.x = randomReal(myEngine);
                bone1.y = 100;
            }

            if (bone2.y > 870) {

                bone2.x = randomReal(myEngine);
                bone2.y = 100;
            }

            if (bone3.y > 870) {
                bone3.x = randomReal(myEngine);
                bone3.y = 100;
            }

            // tracking bone 
            bone1.y += 10;
            bone2.y += 10;
            bone3.y += 10;

            // draw bone 
            if (bone1.y != bone1.prevY) {
                setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
                bar(bone1.prevX - 20, bone1.prevY + 20, bone1.prevX + 20, bone1.prevY - 20);
                setfillstyle(SOLID_FILL, BONE_COLOR);
                circle(bone1.x, bone1.y, 15);
            }

            if (bone2.y != bone2.prevY) {
                setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
                bar(bone2.prevX - 20, bone2.prevY + 20, bone2.prevX + 20, bone2.prevY - 20);
                setfillstyle(SOLID_FILL, BONE_COLOR);
                circle(bone2.x, bone2.y, 15);
            }

            if (bone3.y != bone3.prevY) {
                setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
                bar(bone3.prevX - 20, bone3.prevY + 20, bone3.prevX + 20, bone3.prevY - 20);
                setfillstyle(SOLID_FILL, BONE_COLOR);
                circle(bone3.x, bone3.y, 15);
            }


            // reset position

            if (poop1.y > 870) {

                poop1.x = randomReal(myEngine);
                poop1.y = 100;
            }

            if (poop2.y > 870) {

                poop2.x = randomReal(myEngine);
                poop2.y = 100;
            }

            if (poop3.y > 870) {

                poop3.x = randomReal(myEngine);
                poop3.y = 100;
            }

            // tracking poop 
            poop1.y += 10;
            poop2.y += 10;
            poop3.y += 10;

            // draw poop 
            if (poop1.y != poop1.prevY) {
                setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
                bar(poop1.prevX - 20, poop1.prevY + 20, poop1.prevX + 20, poop1.prevY - 20);
                setfillstyle(SOLID_FILL, POOP_COLOR);
                bar(poop1.x - 20, poop1.y + 20, poop1.x + 20, poop1.y - 20);
            }

            if (poop2.y != poop2.prevY) {
                setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
                bar(poop2.prevX - 20, poop2.prevY + 20, poop2.prevX + 20, poop2.prevY - 20);
                setfillstyle(SOLID_FILL, POOP_COLOR);
                bar(poop2.x - 20, poop2.y + 20, poop2.x + 20, poop2.y - 20);
            }

            if (poop3.y != poop3.prevY) {
                setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
                bar(poop3.prevX - 20, poop3.prevY + 20, poop3.prevX + 20, poop3.prevY - 20);
                setfillstyle(SOLID_FILL, POOP_COLOR);
                bar(poop3.x - 20, poop3.y + 20, poop3.x + 20, poop3.y - 20);
            }

            // -------- Check to see if a key has been pressed
            if (kbhit()) {
                keyPressed = getch();

                // KEY: Q or ESC pressed
                if (keyPressed == 'q' || keyPressed == 'Q' || keyPressed == 0x1b) {
                    keepGoing = false;
                }
            }

            // Check to see if a mouse was clicked 
            if (ismouseclick(WM_LBUTTONUP)) {
                int mouseX, mouseY;
                getmouseclick(WM_LBUTTONUP, mouseX, mouseY);

            }

            // check collision for bone
            int distance;


            distance = sqrt((frenchiebox1.x - bone1.x) * (frenchiebox1.x - bone1.x) + (frenchiebox1.y - bone1.y) * (frenchiebox1.y - bone1.y));
            if (distance <= 100)
            {
                score += 10;
            }

            distance = sqrt((frenchiebox1.x - bone2.x) * (frenchiebox1.x - bone2.x) + (frenchiebox1.y - bone2.y) * (frenchiebox1.y - bone2.y));
            if (distance <= 100)
            {
                score += 10;
            }

            distance = sqrt((frenchiebox1.x - bone3.x) * (frenchiebox1.x - bone3.x) + (frenchiebox1.y - bone3.y) * (frenchiebox1.y - bone3.y));
            if (distance <= 100)
            {
                score += 10;
            }

            showScore(score);


            // check collision for poop
            distance = sqrt((frenchiebox1.x - poop1.x) * (frenchiebox1.x - poop1.x) + (frenchiebox1.y - poop1.y) * (frenchiebox1.y - poop1.y));
            if (distance <= 100)
            {
                keepGoing = false;
            }

            distance = sqrt((frenchiebox1.x - poop2.x) * (frenchiebox1.x - poop2.x) + (frenchiebox1.y - poop2.y) * (frenchiebox1.y - poop2.y));
            if (distance <= 100)
            {
                keepGoing = false;
            }

            distance = sqrt((frenchiebox1.x - poop3.x) * (frenchiebox1.x - poop3.x) + (frenchiebox1.y - poop3.y) * (frenchiebox1.y - poop3.y));
            if (distance <= 100)
            {
                keepGoing = false;
            }



        } // end while(keepGoing)

        // Game has ended
        setcolor(END_COLOR);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
        outtextxy(80, 465, (char*)"GAME OVER, Play Again (Y/N)");
        keyPressed = getch();
        if (keyPressed == 'y' || keyPressed == 'Y') {
            welcomeScreen();

            poop1.x = randomReal(myEngine);
            poop1.y = 100;

            poop2.x = randomReal(myEngine);
            poop2.y = 100;

            poop3.x = randomReal(myEngine);
            poop3.y = 100;

            bone1.x = randomReal(myEngine);
            bone1.y = 100;

            bone2.x = randomReal(myEngine);
            bone2.y = 100;

            bone3.x = randomReal(myEngine);
            bone3.y = 100;
        }
        else {
            playAgain = false;
        }

    } while (playAgain == true);  // Play Again Loop 


    return 0;
} // end main()


// void function for welcome screen 

void showScore(int sc) {
    char s[20]; // An array of char, which is a string
    sprintf_s(s, "Score: %d", sc);
    setcolor(WHITE);
    outtextxy(20, 20, &s[0]); // Draw that string in the graphics window
}

void welcomeScreen() {
    setbkcolor(BACKGROUND_COLOR);
    cleardevice();

    // TITLE
    setcolor(TEXT_COLOR);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(180, 270, (char*)"FRENCHIE GONE HUNGRY");
    setlinestyle(DOTTED_LINE, 2, 3);
    line(160, 305, 850, 305);

    // INSTRUCTIONS 
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2.5);
    outtextxy(205, 620, (char*)"Move the frenchie with mouse to get the treats!");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2.5);
    outtextxy(300, 640, (char*)"DON'T GET HIT BY THE POOP!!");

    //KEY TO BEGIN
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2.5);
    outtextxy(330, 660, (char*)"Press any key to begin");

    //MAIN FACE 
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    fillellipse(500, 500, 60, 60);

    // CHEEKS
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    fillellipse(460, 525, 40, 40);

    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    fillellipse(535, 525, 40, 40);

    // EARS
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    pieslice(480, 470, 90, 160, 60);

    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    pieslice(520, 470, 5, 80, 60);

    // EYES
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(475, 500, 10, 10);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(520, 500, 10, 10);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(475, 505, 5, 5);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(520, 505, 5, 5);

    // MOUTH 
    setfillstyle(SOLID_FILL, BLACK);
    bar(499, 535, 501, 560);

    setcolor(BLACK);
    arc(515, 547, 180, 5, 15);

    setcolor(BLACK);
    arc(485, 547, 180, 5, 15);

    //NOSE 
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(500, 530, 10, 5);


    // BONE
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    fillellipse(515, 547, 5, 5);
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    fillellipse(515, 560, 5, 5);

    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    fillellipse(486, 547, 5, 5);
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    fillellipse(486, 560, 5, 5);

    setfillstyle(SOLID_FILL, BROWN);
    bar(488, 548, 514, 560);



    getch();
    cleardevice();
}








