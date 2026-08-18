
#include <iostream>

using namespace std;

int main() {
    // 1. Game Constants & Storage
    const int width = 30;
    const int height = 15;
    char board[height][width];

    // Snake arrays (Head is index 0)
    int snakeX[100], snakeY[100]; 
    int snakeLength = 4;
    
    // Initial Spawn
    for(int i = 0; i < snakeLength; i++) {
        snakeX[i] = 10 - i;
        snakeY[i] = 7;
    }

    int foodX = 20, foodY = 10;
    int dir = 0; // 0:Right, 1:Down, 2:Left, 3:Up
    int score = 0;
    bool gameOver = false;

    // 2. Main Game Loop
    while (!gameOver) {
        // --- HEADER SECTION ---
        // Creating a unique visual identity for the game
        cout << "####################################" << endl;
        cout << "##       SNAKE GAME    ##" << endl;
        cout << "####################################" << endl;
        cout << "  Score: " << score << "   |   Length: " << snakeLength << endl;
        cout << "------------------------------------" << endl;

        // --- STEP A: INITIALIZE GRID ---
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                    board[i][j] = 'X'; // Double-wall border
                else
                    board[i][j] = ' '; 
            }
        }

        // Place Food
        board[foodY][foodX] = '*';

        // Place Snake
        for (int i = 0; i < snakeLength; i++) {
            if (i == 0) board[snakeY[i]][snakeX[i]] = 'Q'; // The Head
            else board[snakeY[i]][snakeX[i]] = 'o';        // The Body
        }

        // --- STEP B: RENDER ---
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }

        // --- STEP C: INPUT ---
        cout << "\nControls: [W] Up [S] Down [A] Left [D] Right [Q] Quit" << endl;
        cout << "Your Move: ";
        char move;
        cin >> move;

        // Update direction with "Logic check" (preventing 180-degree turns)
        if ((move == 'w' || move == 'W') && dir != 1) dir = 3;
        else if ((move == 's' || move == 'S') && dir != 3) dir = 1;
        else if ((move == 'a' || move == 'A') && dir != 0) dir = 2;
        else if ((move == 'd' || move == 'D') && dir != 2) dir = 0;
        else if (move == 'q' || move == 'Q') gameOver = true;

        // --- STEP D: MOVEMENT LOGIC ---
        // Move Body
        for (int i = snakeLength - 1; i > 0; i--) {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }

        // Move Head
        if (dir == 0) snakeX[0]++;      
        else if (dir == 1) snakeY[0]++; 
        else if (dir == 2) snakeX[0]--; 
        else if (dir == 3) snakeY[0]--; 

        // --- STEP E: COLLISIONS ---
        // Wall Collision
        if (snakeX[0] <= 0 || snakeX[0] >= width - 1 || snakeY[0] <= 0 || snakeY[0] >= height - 1) {
            gameOver = true;
        }

        // Self Collision
        for (int i = 1; i < snakeLength; i++) {
            if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
                gameOver = true;
            }
        }

        // Food Collection
        if (snakeX[0] == foodX && snakeY[0] == foodY) {
            score += 10;
            snakeLength++;
            // Simple logic to move food
            foodX = (foodX * 13 + 7) % (width - 2) + 1;
            foodY = (foodY * 7 + 3) % (height - 2) + 1;
        }

        // Clear terminal space for next frame
        for(int i = 0; i < 15; i++) cout << "\n";
    }

    // --- GAME OVER SCREEN ---
    cout << "************************************" << endl;
    cout << "          CRASHED! GAME OVER        " << endl;
    cout << "          Final Score: " << score << endl;
    cout << "************************************" << endl;

    return 0;
}