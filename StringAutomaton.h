#ifndef PROJECT_1_STRINGAUTOMATON_H
#define PROJECT_1_STRINGAUTOMATON_H
#include <fstream>

#include "Automaton.h"

class StringAutomaton : public Automaton
{
private:
    int file;
    void S0(const std::string& input);

public:
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S1(const std::string& input);
    void S2(const std::string& input);


};


#endif //PROJECT_1_STRINGAUTOMATON_H
