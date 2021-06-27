#include <iostream>
#include <fstream>
#include "game.hpp"

using namespace std;


int main(int argc, char** argv) {
    if (argc != 2) {        
        cerr << "provide one file with task" << endl;
        return EXIT_FAILURE;
    }
    ifstream task(argv[1]);
    Game g(task);
    cout << g;
    return EXIT_SUCCESS;
}