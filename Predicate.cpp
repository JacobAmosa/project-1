#include "Predicate.h"
#include "Parameter.h"
#include <sstream>

void Predicate::setIdName(const string idName) {
    Predicate::idName = idName;
}

void Predicate::setParameters(const vector<Parameter> parameters) {
    Predicate::parameters = parameters;
}

const string Predicate::getIdName() const {
    return idName;
}

const vector<Parameter> Predicate::getParameters() const {
    return parameters;
}

string Predicate::toString(){
    stringstream parameterString;
    parameterString << idName << "(";
    for (unsigned int i = 0; i < parameters.size(); ++i){
        parameterString << parameters[i].getParameter();
        if (i != parameters.size() - 1){
            parameterString << ",";
        }
    }
    parameterString << ")";
    return parameterString.str();
}