#include "IdAutomaton.h"

void IdAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string& input) {
    for (int i = 0; i < input.size() - 1; ++i){
        if (isalpha(input[index]) || isalnum(input[index])) {
            inputRead++;
            index++;
        }
        else {
            break;
        }
    }
}