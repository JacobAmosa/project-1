#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        index++;
        inputRead++;
        commentType = "line";
        if(input[index] == '|'){
            commentType = "block";
            if(input[index + 1] == '|'){
                Serr();
            }
        }
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    bool blockEnd = false;              //blockEnd makes sure the block comment has a closing "|#".
    if (commentType == "line") {
        for (int i = 1; i < input.size(); ++i){
            if(input[i + 1]){
                inputRead++;
            }
        }
        inputRead++;
    }
    if (commentType == "block") {
        for (int i = 2; i < input.size(); ++i){
            if (input[i] == '|' && input[i+1] == '#'){
                inputRead += 2;
                blockEnd = true;
            }
            if (input[i]) {
                inputRead++;
            }
        }
        if (blockEnd == false){
            Serr();
        }
    }
}