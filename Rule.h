#ifndef PROJECT_1_RULE_H
#define PROJECT_1_RULE_H
#include "Predicate.h"
#include "Parameter.h"
#include <string>
using namespace std;

class Rule {
private:
    Predicate headPredicate;
    vector<Predicate> bodyPredicates;
public:
    Predicate getHeadPredicate();
    void setHeadPredicate(Predicate headPredicate);
    vector<Predicate> getBodyPredicates();
    void setBodyPredicates(vector<Predicate> bodyPredicates);
    string toString();

};

#endif //PROJECT_1_RULE_H
