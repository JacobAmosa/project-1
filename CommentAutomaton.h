#ifndef PROJECT_1_COMMENTAUTOMATON_H
#define PROJECT_1_COMMENTAUTOMATON_H

#include "Automaton.h"

class CommentAutomaton : public Automaton
{
private:
    void S0(const std::string& input);

public:
    string commentType = "";

    CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S1(const std::string& input);

};


#endif //PROJECT_1_COMMENTAUTOMATON_H
