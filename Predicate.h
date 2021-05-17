#ifndef PROJECT_1_PREDICATE_H
#define PROJECT_1_PREDICATE_H
#include <string>
#include <vector>
#include "Parameter.h"
using namespace std;

class Predicate {
private:

public:
    string idName;
    vector<Parameter> parameters;
    string toString();
    void setIdName(const string idName);
    void setParameters(const vector<Parameter> parameters);
    const string getIdName() const;
    const vector<Parameter> getParameters() const;

};


#endif //PROJECT_1_PREDICATE_H
