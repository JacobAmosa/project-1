#include "Lexer.h"
#include <vector>
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "AddAutomaton.h"
#include "QmarkAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "AddAutomaton.h"
#include "QueriesAutomaton.h"
#include "IdAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "BadCommentAutomaton.h"
#include "BadStringAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new QmarkAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new BadCommentAutomaton());
    automata.push_back(new BadStringAutomaton());
}

void Lexer::Run(std::string& input) {
    //checks for F.S.A that returns highest number
    int maxRead;
    Automaton* maxAutomaton;
    lineNumber = 1;
    //Iterating through each character of the input.
    while (input.size() > 0) {
        maxRead = 0;
        maxAutomaton = automata[0];
        //skipping white space and checking for EOF.
        while (!input.empty() && isspace(input[0])){
            //Checking for new lines.
            if (input[0] == '\n'){
                lineNumber++;
            }
            input.erase(0, 1);
        }
        if (input.empty()){
            break;
        }
        //Going through each F.S.A and checking if it matches (will return 1 if matches) Parallel portion.
        for(Automaton* automaton: automata){
            int inputRead = automaton->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automaton;
            }
        }
        //After finding the right F.S.A,creates a new token and adds it to the token vector.
        //REMOVING all the comment tokens for the parser.
        if (maxAutomaton != automata[16] && maxAutomaton != automata[17]){
            if (maxRead > 0){
                Token* newToken = maxAutomaton->CreateToken(input.substr(0,maxRead), lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                tokens.push_back(newToken);
            }
            else {
                maxRead = 1;
                tokens.push_back(new Token(TokenType::UNDEFINED, input.substr(0,maxRead), lineNumber));
            }
        }
        input.erase(0, maxRead);
    }
    tokens.push_back(new Token(TokenType::EOF_TYPE, "", lineNumber));
    //toString();
}

//Function that prints out all of the tokens.
void Lexer::toString() {
    int total = 0;
    for (unsigned int i = 0; i < tokens.size(); ++i) {
        cout << tokens[i]->toString() << endl;
        total++;
    }
    cout << "Total Tokens = " << total;
}

//Sends a pointer vector of tokens to the parser class.
vector<Token*> Lexer::getTokens(){
    return tokens;
}
