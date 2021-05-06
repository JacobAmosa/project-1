#include "BadStringAutomaton.h"

void BadStringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void BadStringAutomaton::S1(const std::string& input) {
    //Checking for new lines.
    if (input[index] == '\n'){
        newLines++;
        inputRead++;
        index++;
    }
    //making sure there's a closing string.
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    //Sends error if reach the end of file.
    else if(input[index - 1] == EOF){

    }
    else{
        inputRead++;
        index++;
        S1(input);
    }
}

void BadStringAutomaton::S2(const std::string& input){
    if (input[index] == '\''){
        inputRead++;
        index++;
        S1(input);
    }
    else{
        Serr();
    }

}