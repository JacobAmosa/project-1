#ifndef PROJECT_1_BADSTRINGAUTOMATON_H
#define PROJECT_1_BADSTRINGAUTOMATON_H

#include "Automaton.h"

class BadStringAutomaton : public Automaton
{
private:
    void S0(const std::string& input);

public:

    BadStringAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S1(const std::string& input);

};


#endif //PROJECT_1_BADSTRINGAUTOMATON_H
