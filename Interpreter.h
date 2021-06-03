#ifndef PROJECT_1_INTERPRETER_H
#define PROJECT_1_INTERPRETER_H
#include "Predicate.h"
#include "Rule.h"
#include "Relation.h"
#include "DatalogProgram.h"
#include "Database.h"
#include <string>
#include <map>

class Interpreter {
private:
    DatalogProgram vectors;
    Database relationsMap;
    vector<int> projectColumns;
    vector<string> variable;
    map<string, int> unseenVariables;

public:
    Interpreter(DatalogProgram allVectors);
    string toString();
    Relation evaluatePredicate(Predicate p);

};

#endif //PROJECT_1_INTERPRETER_H
