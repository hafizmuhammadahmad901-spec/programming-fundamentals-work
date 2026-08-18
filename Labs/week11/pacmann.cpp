#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

// ================= GOToxy =================
void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// ================= GLOBALS =================
const int rows = 20;
const int cols = 40;
char maze[rows][cols];

int pacX = 5, pacY = 5;
int lives = 3;
int score = 0;
bool powerMode = false;
int powerCounter = 0;

// Ghosts
int g1x = 10, g1y = 5;   // horizontal
int g2x = 15, g2y = 10;  // vertical
int g3x = 20, g3y = 10;  // random
int g4x = 25, g4y = 15;  // chaser

int dir1 = 1, dir2 = 1;

// ================= LOAD MAZE =================
void loadMaze() {
    ifstream file("maze.txt");
    for (int i = 0; i < rows; i++) {
        file.getline(maze[i], cols);
    }
    file.close();
}

// ================= PRINT =================
void printMaze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

// ================= PACMAN =================
void movePacman(char input) {

    int newX = pacX;
    int newY = pacY;

    if (input == 'w') newY--;
    if (input == 's') newY++;
    if (input == 'a') newX--;
    if (input == 'd') newX++;

    if (maze[newY][newX] != '#') {

        // score
        if (maze[newY][newX] == '.') score += 10;

        // power pellet
        if (maze[newY][newX] == 'P') {
            powerMode = true;
            powerCounter = 30;
        }

        gotoxy(pacX, pacY); cout << " ";
        pacX = newX;
        pacY = newY;
        gotoxy(pacX, pacY); cout << "C";
    }
}

// ================= GHOSTS =================

// a) Horizontal
void ghost1() {
    int newX = g1x + dir1;

    if (maze[g1y][newX] == '#')
        dir1 = -dir1;
    else {
        gotoxy(g1x, g1y); cout << " ";
        g1x = newX;
        gotoxy(g1x, g1y); cout << "G";
    }
}

// b) Vertical
void ghost2() {
    int newY = g2y + dir2;

    if (maze[newY][g2x] == '#')
        dir2 = -dir2;
    else {
        gotoxy(g2x, g2y); cout << " ";
        g2y = newY;
        gotoxy(g2x, g2y); cout << "G";
    }
}

// c) Random
void ghost3() {
    int dir = rand() % 4;

    int nx = g3x, ny = g3y;

    if (dir == 0) nx++;
    if (dir == 1) nx--;
    if (dir == 2) ny++;
    if (dir == 3) ny--;

    if (maze[ny][nx] != '#') {
        gotoxy(g3x, g3y); cout << " ";
        g3x = nx; g3y = ny;
        gotoxy(g3x, g3y); cout << "G";
    }
}

// d) Chase Pacman
void ghost4() {
    int nx = g4x, ny = g4y;

    if (pacX > g4x) nx++;
    else if (pacX < g4x) nx--;

    if (maze[g4y][nx] != '#')
        g4x = nx;
    else {
        if (pacY > g4y) ny++;
        else if (pacY < g4y) ny--;

        if (maze[ny][g4x] != '#')
            g4y = ny;
    }

    gotoxy(g4x, g4y); cout << "G";
}

// ================= COLLISION =================
void checkCollision() {

    if ((pacX == g1x && pacY == g1y) ||
        (pacX == g2x && pacY == g2y) ||
        (pacX == g3x && pacY == g3y) ||
        (pacX == g4x && pacY == g4y)) {

        if (powerMode) {
            // eat ghost → reset
            g1x = 10; g1y = 5;
        } else {
            lives--;
            pacX = 5; pacY = 5;

            if (lives == 0) {
                gotoxy(0, rows + 2);
                cout << "GAME OVER";
                exit(0);
            }
        }
    }
}

// ================= MAIN =================
int main() {

    loadMaze();
    printMaze();

    while (true) {

        if (GetAsyncKeyState('W')) movePacman('w');
        if (GetAsyncKeyState('S')) movePacman('s');
        if (GetAsyncKeyState('A')) movePacman('a');
        if (GetAsyncKeyState('D')) movePacman('d');

        ghost1();
        ghost2();
        ghost3();
        ghost4();

        checkCollision();

        // power mode timer
        if (powerMode) {
            powerCounter--;
            if (powerCounter == 0)
                powerMode = false;
        }

        // score display
        gotoxy(0, rows + 1);
        cout << "Score: " << score << "   Lives: " << lives;

        Sleep(150);
    }

    return 0;
}