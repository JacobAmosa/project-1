#include "BadCommentAutomaton.h"

void BadCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#' &&
        input[index + 1] == '|') {
        index+= 2;
        inputRead+= 2;
        S1(input);
    }
    else {
        Serr();
    }
}

void BadCommentAutomaton::S1(const std::string& input) {
    bool blockEnd = false;              //blockEnd makes sure the block comment doesn't end.
        for (unsigned int i = 2; i < input.size(); ++i) {
            //Checking for new lines.
            if (input[i] == '\n') {
                newLines++;
            }
            //Checking for end of block comment
            if (input[i] == '|') {
                inputRead++;
                if (i + 1 < (int)input.size()) {
                    if (input[i + 1] == '#') {
                        blockEnd = true;
                        break;
                    }
                }
            }
            inputRead++;
        }
        if (blockEnd) {
            Serr();
        }
}