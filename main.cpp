#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include "DatalogProgram.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    //Reading in a file and converting it to a string.
    string fileArgument = argv[1];
    ifstream file(fileArgument);
    string fileContent((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());

    //Calling lexer class to create tokens from file
    lexer->Run(fileContent);
    //creating a new parser object to retrieve tokens from lexer.
    Parser* parser = new Parser(lexer->getTokens());
    //Creating an interpreter object and giving it the four different vectors.
    new Interpreter(parser->getDatalogProgram());

    delete lexer;

    return 0;
}