#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Minesweeper {
private:
    const int rows = 6;
    const int cols = 6;
    const int num_gophers = 6;
    int num_moves;
    int num_cells;
    vector<vector<int>> num_g;
    vector<vector<bool>> explored_box;

public:
    Minesweeper() {
        num_moves = 0;
        num_cells = rows * cols;
        num_g.resize(rows, vector<int>(cols));
        explored_box.resize(rows, vector<bool>(cols, false));
        srand(time(NULL));
        for (int i = 0; i < num_gophers; i++) {
            int row = rand() % rows;
            int col = rand() % cols;
            while (num_g[row][col] == -1) {
                row = rand() % rows;
                col = rand() % cols;
            }
            num_g[row][col] = -1;
            for (int r = row - 1; r <= row + 1; r++) {
                for (int c = col - 1; c <= col + 1; c++) {
                    if (r >= 0 && r < rows && c >= 0 && c < cols && num_g[r][c] != -1) {
                        num_g[r][c]++;
                    }
                }
            }
        }
    }

    void print_board() {
        cout << "|";
        for (int c = 0; c < cols; c++) {
            cout << "---|";
        }
        cout << endl;
        for (int r = 0; r < rows; r++) {
            cout << "|";
            for (int c = 0; c < cols; c++) {
                if (!explored_box[r][c]) {
                    cout << "+++|";
                } else if (num_g[r][c] == -1) {
                    cout << " G |";
                } else {
                    cout << " " << num_g[r][c] << " |";
                }
            }
            cout << endl;
            cout << "|";
            for (int c = 0; c < cols; c++) {
                cout << "---|";
            }
            cout << endl;
        }
    }
     void uncover_cell(int row, int col) {
        explored_box[row][col] = true;
        num_moves++;

        if (num_g[row][col] == 0) {
            for (int r = row - 1; r <= row + 1; r++) {
                for (int c = col - 1; c <= col + 1; c++) {
                    if (r >= 0 && r < rows && c >= 0 && c < cols && !explored_box[r][c]) {
                        uncover_cell(r, c);
                    }
                }
            }
        }
    }
    void play() {
    while (num_moves < num_cells - num_gophers) {
        print_board();
        int row, col;
        do {
            cout << "Enter row and column together with a space: ";
            cin >> row >> col;
        } while (row < 0 || row >= rows || col < 0 || col >= cols || explored_box[row][col]);
        explored_box[row][col] = true;
        if (num_g[row][col] == -1) {
            cout << "Unfortuantely, You Lose The Game!!" << endl;
            return;
        } else if (num_g[row][col] == 0) {
            uncover_cell(row, col);
        } else {
            num_moves++;
        }
    }
    cout << "Congrats!! You Grab The Winner Spot!!!!" << endl;
}
};
int main() {
    Minesweeper game;
    game.play();
    return 0;
}
