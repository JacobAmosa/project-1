#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        index++;
        inputRead++;
        commentType = "line";
        if(input[index] == '|'){
            commentType = "block";
            index++;
            inputRead++;
        }
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
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
       if (input[index] == '|'){
           inputRead++;
           index++;
           S2(input);
       }
       else if (input[index] == EOF){
           Serr();
       }
       else if(input[index] == '\n'){
           index++;
           newLines++;
           inputRead++;
           S1(input);
       }
       else{
           inputRead++;
           index++;
           S1(input);
       }
    }
}

void CommentAutomaton::S2(const std::string& input) {
    if (input[index + 1] == EOF){
        Serr();
    }
    else if(input[index] == '#'){
        inputRead++;
    }
    else{
        inputRead++;
        index++;
        S1(input);
    }
}




