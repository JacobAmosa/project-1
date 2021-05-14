#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();

public:
    Lexer();
    ~Lexer();
    int lineNumber;

    void Run(std::string& input);
    void toString();
    vector<Token*> getTokens();

};

#endif // LEXER_H

