//
// Created by wbai on 8/17/2023.
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 20;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

class Tetris {
private:
    vector<vector<int>> board;
    Point currentBlockPos;
    vector<Point> currentBlock;
    int currentBlockType;

public:
    Tetris() : board(HEIGHT, vector<int>(WIDTH, 0)), currentBlockPos(WIDTH / 2, 0), currentBlockType(0) {}

    void generateBlock() {
        currentBlock.clear();

        // Generate a new block type (0 to 6)
        currentBlockType = rand() % 7;

        // Create the block's shape
        // Add points (x, y) to the currentBlock vector
        // The points should define the shape of the block

        // Initialize the block's position
        currentBlockPos = Point(WIDTH / 2, 0);
    }

    bool isCollision() {
        for (const Point& p : currentBlock) {
            int x = p.x + currentBlockPos.x;
            int y = p.y + currentBlockPos.y;
            if (x < 0 || x >= WIDTH || y >= HEIGHT || board[y][x] != 0) {
                return true;
            }
        }
        return false;
    }

    void placeBlock() {
        for (const Point& p : currentBlock) {
            int x = p.x + currentBlockPos.x;
            int y = p.y + currentBlockPos.y;
            board[y][x] = currentBlockType + 1; // Mark with block type
        }
    }

    void clearLines() {
        // Check and clear complete lines
        // Update the board by shifting the lines above cleared lines down
    }

    void drawBoard() {
        system("cls"); // Clear the console

        // Draw the game board and the current block
        // Loop through the board and print appropriate characters
        // Loop through the currentBlock and print it on top of the board

        cout << "Score: 0" << endl; // Display the score
    }

    void run() {
        while (true) {
            // Handle user input using _kbhit() and _getch()

            // Move the block left, right, or down based on user input

            // If the block can't move down anymore, place it and generate a new one

            // Clear complete lines and update the score

            // Draw the board
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    Tetris tetris;
    tetris.run();
    return 0;
}