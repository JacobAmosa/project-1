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
    //Checking for new lines.
    if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S1(input);
    }
    //check for end of file.
    else if ((int)input.size() == index){

    }
    //Checking for end of block comment
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else{
        inputRead++;
        index++;
        S1(input);
    }
}

void BadCommentAutomaton::S2(const std::string& input) {
    if(input[index] == '#'){
        Serr();
    }
    else if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S1(input);
    }
    //check for end of file.
    else if ((int)input.size() == index){
        return;
    }
    else {
        inputRead++;
        index++;
        S1(input);
    }

}