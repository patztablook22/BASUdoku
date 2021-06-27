#pragma once

#include <ostream>
#include <fstream>
#include <vector>

using Field = std::vector<std::vector<uint8_t>>;

class Game {
    Field field;
    size_t cell_size;

    public:
        Game(Field&);
        Game(std::ifstream&);
        size_t size() const;
        friend std::ostream& operator<<(std::ostream&, Game&);
        bool solve();
        
    private:
        bool solve_from(int, int);
        
};