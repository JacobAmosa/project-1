#include "Interpreter.h"
#include "Predicate.h"
#include "Parameter.h"
#include "Relation.h"
#include "Rule.h"
#include "Header.h"
#include "DatalogProgram.h"
#include <vector>
#include <sstream>
using namespace std;

Interpreter::Interpreter(DatalogProgram allVectors) {
    vectors = allVectors;
    vector<string> tableHeader;

    //Looping through SCHEME vectors to retrieve relation names and headers.
    for (unsigned int i = 0; i < vectors.getSchemes().size(); ++i){
        int j = 0;
        while (vectors.getSchemes()[i].getParameters().size() > j) {
            tableHeader.push_back((vectors.getSchemes()[i].getParameters()[j]).getParameter());
            j++;
        }
        Header* header = new Header(tableHeader);
        Relation* relation = new Relation(vectors.getSchemes()[i].getIdName(), header->getAttributes());
        relationsMap.setDatabase(vectors.getSchemes()[i].getIdName(), *relation);
        tableHeader.clear();
    }

    //Looping through FACT vectors to retrieve tuples for specific tables.
    vector<string> tuples;
    for (unsigned int i = 0; i < vectors.getFacts().size(); ++i){
        Tuple* tuple = new Tuple();
        int j = 0;
        while (vectors.getFacts()[i].getParameters().size() > j) {
            tuples.push_back((vectors.getFacts()[i].getParameters()[j]).getParameter());
            j++;
        }
        tuple->setValues(tuples);
        relationsMap.findDatabase(vectors.getFacts()[i].getIdName()).addTuple(*tuple);
        delete tuple;
        tuples.clear();
    }

    //Printing out each tuple with its corresponding header.
    for (auto& x: relationsMap.getDatabase()) {
        x.second.toString();
    }


}

string Interpreter::toString() {

}

