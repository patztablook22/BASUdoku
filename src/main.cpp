#include <iostream>
#include <fstream>
#include "game.hpp"

using namespace std;


int main(int argc, char** argv) {
    if (argc != 2) {        
        cerr << "provide one file with task" << endl;
        return EXIT_FAILURE;
    }

    try {
        ifstream task(argv[1]);
        Game g(task);

        if (!g.solve()) cout << "not ";
        cout << "solved:" << '\n';
        cout << g;

    } catch (exception& e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
