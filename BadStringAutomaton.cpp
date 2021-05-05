#include "BadStringAutomaton.h"

void BadStringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        index++;
        inputRead++;
        S1(input);
    }
    else {
        Serr();
    }
}

void BadStringAutomaton::S1(const std::string& input) {
    bool StringEnd = false;              //StringEnd makes sure the string doesn't end.
    for (int i = 1; i < input.size(); ++i) {
        //Checking for new lines.
        if (input[i] == '\n') {
            newLines++;
        }
        //Checking for end of string
        if (input[i] == '\'') {
            StringEnd = true;
            break;
        }
        inputRead++;
    }
    if (StringEnd) {
        Serr();
    }
}