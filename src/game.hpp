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
        size_t base() const;
        friend std::ostream& operator<<(std::ostream&, Game&);
        bool solve();
        
    private:
        void init(Field&);

        bool solve_from(int, int);
        bool solve_next(int, int);
        bool check(int, int);
        
        static uint8_t convert(char);
        static char    convert(uint8_t);
};