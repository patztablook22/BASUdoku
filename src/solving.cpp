#include "game.hpp"
using namespace std;


bool Game::solve() {
    return solve_from(0, 0);
}

bool Game::solve_from(int row, int col) {
    if (field[row][col] != 0)
        return solve_next(row, col);
    
    for (uint8_t attempt = 1; attempt <= base(); attempt++) {
        field[row][col] = attempt;

        if(!check(row, col))
            continue;
        
        if (solve_next(row, col))
            return true;
    }
    field[row][col] = 0;
    return false;
}

bool Game::solve_next(int row, int col) {
    if (++col >= size()) {
        col = 0;
        row++;
    }
    
    if (row >= size())
        return true;

    return solve_from(row, col);
}

bool Game::check(int row, int col) {
    uint8_t val = field[row][col];

    // unique within the row
    for (int i = 0; i < size(); i++)
        if (field[row][i] == val && i != col)
            return false;
        
    // unique within the col
    for (int i = 0; i < size(); i++)
        if (field[i][col] == val && i != row)
            return false;
    
    // unique within the cell
    int cell_row = (row / cell_size) * cell_size;
    int cell_col = (col / cell_size) * cell_size;
    for (int i = cell_row; i < cell_row + cell_size; i++)
        for (int j = cell_col; j < cell_col + cell_size; j++)
            if (field[i][j] == val && !(i == row && j == col))
                return false;

    return true;
}