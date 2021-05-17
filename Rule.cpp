#include "Rule.h"
#include "Parameter.h"
#include <sstream>
#include <string>
using namespace std;

Predicate Rule::getHeadPredicate() {
    return headPredicate;
}

void Rule::setHeadPredicate(Predicate headPredicate) {
    Rule::headPredicate = headPredicate;
}

vector<Predicate> Rule::getBodyPredicates() {
    return bodyPredicates;
}

void Rule::setBodyPredicates(vector<Predicate> bodyPredicates) {
    Rule::bodyPredicates = bodyPredicates;
}

string Rule::toString(){
    stringstream out;
    out << headPredicate.toString() << " :- ";
    for (unsigned int i = 0; i < bodyPredicates.size(); ++i){
        out << bodyPredicates[i].toString();
        if (i != bodyPredicates.size() - 1){
            out << ",";
        }
    }
    out << ".";

    return out.str();

}
