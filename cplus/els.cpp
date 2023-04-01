#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int WIDTH = 10;
const int HEIGHT = 20;
const int BLOCK_SIZE = 20;

int board[HEIGHT][WIDTH] = {0};

struct Point {
    int x, y;
} a[4], b[4];

int shapes[7][4] = {
    1,3,5,7,
    2,4,5,7,
    3,5,4,6,
    3,5,4,7,
    2,3,5,7,
    3,5,7,6,
    2,3,4,5
};

bool check() {
    for (int i = 0; i < 4; i++) {
        if (a[i].x < 0 || a[i].x >= WIDTH || a[i].y >= HEIGHT) return 0;
        if (board[a[i].y][a[i].x]) return 0;
    }
    return 1;
}

int main() {
    srand(time(0));
    int n = rand() % 7;
    int color = rand() % 7 + 1;
    for (int i = 0; i < 4; i++) {
        a[i].x = shapes[n][i] % 2;
        a[i].y = shapes[n][i] / 2;
    }
    while (1) {
        Sleep(100);
        if (GetAsyncKeyState(VK_DOWN)) {
            for (int i = 0; i < 4; i++) {
                b[i] = a[i];
                a[i].y += 1;
            }
            if (!check()) {
                for (int i = 0; i < 4; i++) {
                    board[b[i].y][b[i].x] = color;
                }
                n = rand() % 7;
                color = rand() % 7 + 1;
                for (int i = 0; i < 4; i++) {
                    a[i].x = shapes[n][i] % 2;
                    a[i].y = shapes[n][i] / 2;
                }
            }
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            for(int i = 0; i < 4; i++) {
                b[i] = a[i];
                a[i].x -= 1;
            }
            if (!check()) {
                for (int i = 0; i < 4; i++) {
                    a[i] = b[i];
                }
            }
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            for (int i = 0; i < 4; i++) {
                b[i] = a[i];
                a[i].x += 1;
            }
            if (!check()) {
                for (int i = 0; i < 4; i++) {
                    a[i] = b[i];
                }
            }
        }
        if (GetAsyncKeyState(VK_UP)) {
            for (int i = 0; i < 4; i++) {
                b[i] = a[i];
                a[i].x = a[1].x + a[1].y - a[i].y;
                a[i].y = a[1].y + a[1].x - a[i].x;
            }
            if (!check()) {
                for (int i = 0; i < 4; i++) {
                    a[i] = b[i];
                }
            }
        }
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (board[i][j] == 0) {
                    cout << " ";
                } else {
                    cout << "*";
                }
            }
            cout << endl;
        }
        cout << "Score: " << endl;
    }
    return 0;
}