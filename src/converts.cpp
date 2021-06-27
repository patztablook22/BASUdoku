#include "game.hpp"


uint8_t Game::convert(char c) {
    if (c >= 48 && c <= 57)
        return c - 48;
    else
        return 10 + c - 65;
}

char Game::convert(uint8_t i) {
    if (i < 10)
        return 48 + i;
    else
        return 65 + i - 10;
}