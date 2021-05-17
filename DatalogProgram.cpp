#include "DatalogProgram.h"

void DatalogProgram::toString() {

    cout << "Schemes" << "(" << schemes.size() << "):" <<  endl;
    for (unsigned int i = 0; i < schemes.size(); ++i) {
        cout << schemes[i].toString() << endl;
    }

    cout << "Facts" << "(" << facts.size() << "):" <<  endl;
    for (unsigned int i = 0; i < facts.size(); ++i) {
        cout << facts[i].toString() << "." << endl;
    }

    cout << "Rules" << "(" << rules.size() << "):" <<  endl;
    for (unsigned int i = 0; i < rules.size(); ++i) {
        cout << rules[i].toString() << endl;
    }

    cout << "Queries" << "(" << queries.size() << "):" <<  endl;
    for (unsigned int i = 0; i < queries.size(); ++i) {
        cout << queries[i].toString() << "?" << endl;
    }

    cout << "Domain" << "(" << domain.size() << "):" <<  endl;
    for (auto it = domain.begin(); it != domain.end(); ++it){
        cout << *it << endl;
    }
}

void DatalogProgram::setDomain(set<string> domain) {
    DatalogProgram::domain = domain;
}

