#ifndef PROJECT_1_INTERPRETER_H
#define PROJECT_1_INTERPRETER_H
#include "Predicate.h"
#include "Rule.h"
#include "Relation.h"
#include "DatalogProgram.h"
#include "Database.h"

class Interpreter {
private:
    DatalogProgram vectors;
    Database relationsMap;

public:
    Interpreter(DatalogProgram allVectors);
    string toString();

};

#endif //PROJECT_1_INTERPRETER_H
