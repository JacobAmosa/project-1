#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    bool closing = false;
    for (int i = 0; i < input.size() - 1; ++i){
        if (input[index] == '\'') {
            inputRead++;
            closing = true;
            break;
        }
        inputRead++;
        index++;
    }
    if (closing == false){
        Serr();
    }
}