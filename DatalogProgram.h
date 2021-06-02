#ifndef PROJECT_1_DATALOGPROGRAM_H
#define PROJECT_1_DATALOGPROGRAM_H
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "Predicate.h"
#include "Rule.h"
using namespace std;

class DatalogProgram {
private:

public:
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Predicate> queries;
    vector<Rule> rules;
    set<string> domain;
    void setDomain(set<string> domain);
    vector<Predicate> getSchemes();
    vector<Predicate> getFacts();
    vector<Predicate> getQueries();
    vector<Rule> getRules();
    void toString();

};


#endif //PROJECT_1_DATALOGPROGRAM_H
