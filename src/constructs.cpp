#include "game.hpp"
using namespace std;


Game::Game(Field& f) {
    // must be a square
    size_t size = f.size();
    for (auto& v: f)
        if (v.size() != size)
            throw invalid_argument("Must be a square");
    
    // must be square of an integer
    size_t &i = cell_size;
    for (i = 1; i*i < size; i++);
    if (i*i != size)
        throw invalid_argument("Must be square of an integer");
    
    field = f;
}