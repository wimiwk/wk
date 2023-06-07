#include <iostream>
using namespace std;

int main() {
    char grid[9][9];
    int count = 0;
    // read input
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
        }
    }
    // check every possible square
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == '#') {
                /*for (int k = 1; k < 9; k++) {
                    if (i + k < 9 && j + k < 9 && grid[i][j+k] == '#' && grid[i+k][j] == '#' && grid[i+k][j+k] == '#') {
                        count++;
                    }
                }*/
                for (int k_y = 0; k_y < 9; k_y++)
                {
                    for (int k_x = 1; k_x < 9; k_x++)
                    {
                        if (i + k_y < 9 && j + k_x < 9 &&i + k_x < 9 && j - k_y >=0 &&i + k_y+k_x < 9 && j + k_x -k_y< 9 && grid[i+k_y][j+k_x] == '#' && grid[i+k_x][j-k_y] == '#' && grid[i+k_x+k_y][j+k_x-k_y] == '#') {
                            count++;
                        }
                    }
                    
                }
                
            }
        }
    }
    // output result
    cout << count << endl;
    return 0;
}