#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        index++;
        inputRead++;
        commentType = "line";
        if(input[index] == '|'){
            commentType = "block";
            index++;
        }
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    bool blockEnd = false;              //blockEnd makes sure the block comment has a closing "|#".
    newLines = 0;
    if (commentType == "line") {
        for (int i = 1; i < input.size(); ++i) {
            if (input[i + 1] == '\n') {
                break;
            } else {
                inputRead++;
            }
        }
        inputRead++;
    }
    if (commentType == "block") {
        for (int i = 2; i < input.size(); ++i) {
            //Checking for new lines.
            if (input[i] == '\n') {
                newLines++;
            }
            //Checking for end of block comment
            if (input[i] == '|') {
                inputRead++;
                if (i + 1 < input.size()) {
                    if (input[i + 1] == '#') {
                        inputRead ++;
                        blockEnd = true;
                        break;
                    }
                }
            }
            inputRead++;
        }
        if (!blockEnd) {
            Serr();
        }
    }
}