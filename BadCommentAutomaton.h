#ifndef PROJECT_1_BADCOMMENTAUTOMATON_H
#define PROJECT_1_BADCOMMENTAUTOMATON_H

#include "Automaton.h"

class BadCommentAutomaton : public Automaton
{
private:
    void S0(const std::string& input);

public:

    BadCommentAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S1(const std::string& input);

};


#endif //PROJECT_1_BADCOMMENTAUTOMATON_H
