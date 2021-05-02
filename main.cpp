#include "Lexer.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    // TODO
    ifstream testFile("test.txt");

    if (testfile) {
        cout << "IT WORKED" << endl;e
    }
    delete lexer;

    return 0;
}