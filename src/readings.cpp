#include "game.hpp"
using namespace std;


size_t Game::size() const {
    return field.size();
}

size_t Game::base() const {
    return size();
}

ostream& operator<<(ostream& os, Game& g) {
    // os << "size: " << g.size() << "x" << g.size() << "; ";
    // os << "cell: " << g.cell_size << "x" << g.cell_size << '\n';

    for (auto& v: g.field) {
        for (uint8_t i: v)
            os << Game::convert(i) << ' ';
        os << '\n';
    }
    // os << string(2 * g.size(), '=') << '\n';
    os << flush;

    return os;
}