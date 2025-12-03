#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>

/* fast cursor move to avoid flicker */
void clear_screen_fast() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
}

/* reset game values */
void resetGame(int *x, int *step, int *obstaclePos, int *score, int *lives) {
    *x = 1;
    *step = 0;
    *obstaclePos = rand() % 3;
    *score = 0;
    *lives = 3;
}

int main() {
    system("color 4F");
    srand((unsigned)time(0));

    int x, step, obstaclePos, score, lives;

RESTART_GAME:

    // reset game values
    resetGame(&x, &step, &obstaclePos, &score, &lives);

    // play background music looped
    PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);

    while (1) {

        // -------- INPUT --------
        if (_kbhit()) {
            int ch = getch();
            if (ch == 0 || ch == 224) {
                // arrow keys
                ch = getch();
                if (ch == 75 && x > 0) x--;      // LEFT
                else if (ch == 77 && x < 2) x++; // RIGHT
            } else {
                // other keys
                if (ch == 'a' || ch == 'A') { if (x > 0) x--; }
                else if (ch == 'd' || ch == 'D') { if (x < 2) x++; }
            }
        }

        // -------- DRAW --------
        clear_screen_fast();
        printf("SCORE: %d   LIVES: %d\n", score, lives);
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++) {
            if (i == step) {
                if (obstaclePos == 0)
                    printf("| #         |\n");
                else if (obstaclePos == 1)
                    printf("|    #      |\n");
                else
                    printf("|         # |\n");
            } else {
                printf("|           |\n");
            }
        }

        // -------- PLAYER --------
        if (x == 0)
            printf("| A         |\n");
        else if (x == 1)
            printf("|    A      |\n");
        else
            printf("|         A |\n");

        // -------- COLLISION --------
        if (step == 9 && x == obstaclePos) {
            lives--;

            // stop background music temporarily
            PlaySound(NULL, NULL, 0);

            // play impact sound synchronously
            PlaySound(TEXT("impact.wav"), NULL, SND_SYNC);

            // resume background music if game is not over
            if (lives > 0) {
                PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);
            }

            // check Game Over
            if (lives == 0) {
                clear_screen_fast();
                printf("===== GAME OVER =====\n");       // line 1
                printf("FINAL SCORE: %d\n", score);     // line 2
                printf("Press R to Restart\n");         // line 3
                printf("Press any other key to Exit\n"); // line 4

                char choice = getch();
                if (choice == 'r' || choice == 'R')
                    goto RESTART_GAME;
                else
                    exit(0);
            }

            // reset obstacle for next life
            step = 0;
            obstaclePos = rand() % 3;
        }

        Sleep(150);  // frame delay

        // -------- MOVE OBSTACLE --------
        step++;

        if (step > 9) {
            step = 0;
            obstaclePos = rand() % 3;
            score++;   // increase score for each obstacle passed
        }
    }

    return 0;
}
