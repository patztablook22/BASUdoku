#include "game.hpp"
#include <iostream>
using namespace std;

Game::Game(ifstream& is) {
    Field f;
    f.push_back(vector<uint8_t>());
    while (is) {
        char buff;
        is.get(buff);
        
        switch (buff) {
        case ' ':
            continue;
        case '\n':
            if (!f.back().empty())
            f.push_back(vector<uint8_t>());
            break;
        default:
            f.back().push_back(
                convert(buff)
            );
        }
    }
    if (f.back().empty())
        f.pop_back();
    init(f);
}

Game::Game(Field& f) {
    init(f);
}

void Game::init(Field& f) {
    // must be a square
    // and contains appropriate values
    size_t size = f.size();
    for (auto& v: f) {
        if (v.size() != size)
            throw invalid_argument("Must be a square");
        for (uint8_t i: v)
            if (i > size)
                throw invalid_argument("Number exceeds BASE");
    }
    
    // must be square of an integer
    size_t &i = cell_size;
    for (i = 1; i*i < size; i++);
    if (i*i != size)
        throw invalid_argument("Must be square of an integer");
    
    field = f;
}
