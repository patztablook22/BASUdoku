#include "game.hpp"
using namespace std;


size_t Game::size() const {
    return field.size();
}

ostream& operator<<(ostream& os, Game& g) {
    os << "size: " << g.size() << "x" << g.size() << "; ";
    os << "cell: " << g.cell_size << "x" << g.cell_size << '\n';

    for (auto& v: g.field) {
        for (uint8_t i: v) {
            
            // use capital letters for numbers above 9
            if (i < 0)
                os << (int)i;
            else
                os << (char) (65 + i - 10);
            
            os << ' ';
        }
        os << '\n';
    }
    os << string(2 * g.size(), '=') << '\n';
    os << flush;

    return os;
}