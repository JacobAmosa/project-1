#include "Interpreter.h"
#include "Predicate.h"
#include "Parameter.h"
#include "Relation.h"
#include "Header.h"
#include "DatalogProgram.h"
#include <vector>
#include <sstream>
using namespace std;

Interpreter::Interpreter(DatalogProgram allVectors) {
    vectors = allVectors;
    vector<string> tableHeader;
    Relation relation;

    //Looping through SCHEME vectors to retrieve relation names and headers.
    for (unsigned int i = 0; i < vectors.getSchemes().size(); ++i){
        unsigned int j = 0;
        //changing all the parameters to type string.
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
        unsigned int j = 0;
        //changing all the parameters to type string.
        while (vectors.getFacts()[i].getParameters().size() > j) {
            tuples.push_back((vectors.getFacts()[i].getParameters()[j]).getParameter());
            j++;
        }
        tuple->setValues(tuples);
        relationsMap.findDatabase(vectors.getFacts()[i].getIdName()).addTuple(*tuple);
        delete tuple;
        tuples.clear();
    }

    //Evaluating each Rule predicate before getting passed to queries.
    unsigned int  preCount;
    unsigned int postCount;
    unsigned int loopCount = 0;
    cout << "Rule Evaluation" << endl;
    do {
        preCount = 0;
        postCount = 0;
        for (pair<const string, Relation>& x: relationsMap.getDatabase()){
            preCount += x.second.getTupleSet().size();
        }
        for (unsigned int i = 0; i < vectors.getRules().size(); ++i) {
            cout << vectors.getRules()[i].toString() << endl;
            Relation rulesRelation;
            for (unsigned int j = 0; j < vectors.getRules()[i].getBodyPredicates().size(); ++j) {
                //rulesRelation = relationsMap.findDatabase(vectors.getRules()[i].getBodyPredicates()[j].getIdName());
                //only calling join function when there is more than one body predicate.
                if (j > 0) {
                    rulesRelation = rulesRelation.join(evaluatePredicate(vectors.getRules()[i].getBodyPredicates()[j]));
                } else {
                    rulesRelation = evaluatePredicate(vectors.getRules()[i].getBodyPredicates()[j]);
                }
            }

            //Looping through rulesRelation to find matching columns and call project function.
            vector<int> matchingIndex;
            for (unsigned int j = 0; j < vectors.getRules()[i].getHeadPredicate().getParameters().size(); ++j) {
                for (unsigned int k = 0; k < rulesRelation.getHeader().getAttributes().size(); ++k) {
                    if (vectors.getRules()[i].getHeadPredicate().getParameters()[j].getParameter() ==
                        rulesRelation.getHeader().getAttributes()[k]) {
                        matchingIndex.push_back(k);
                    }
                }
            }
            rulesRelation = rulesRelation.project(matchingIndex);
            relationsMap.findDatabase(vectors.getRules()[i].getHeadPredicate().getIdName()).unite(rulesRelation);
            rulesRelation.clearRelation();
            matchingIndex.clear();
        }
        for (pair<const string, Relation>& x: relationsMap.getDatabase()){
            postCount += x.second.getTupleSet().size();
        }
        loopCount++;
    }
    while(preCount != postCount);
    cout << endl << "Schemes populated after " << loopCount << " passes through the Rules." << endl << endl;

    //Evaluating each query and calling evaluatePredicate for each individual predicate.
    cout << "Query Evaluation" << endl;
    for (unsigned int i = 0; i < vectors.getQueries().size(); ++i){
        cout << vectors.getQueries()[i].toString() << "? ";
        relation = evaluatePredicate(vectors.getQueries()[i]);
        if (relation.getTupleSet().size() > 0){
            cout << "Yes(" << relation.getTupleSet().size() << ")" << endl;
            relation.toString();
        }
        else{
            cout << "No" << endl;
        }
        projectColumns.clear();
        variable.clear();
        unseenVariables.clear();
        relation.clearRelation();
    }
}

Relation Interpreter::evaluatePredicate(Predicate p) {
    Relation newRelation = relationsMap.findDatabase(p.getIdName());
    vector<string> queries;
    //changing all the parameters to type string.
    for (unsigned int i = 0; i < p.getParameters().size(); ++i){
        queries.push_back(p.getParameters()[i].getParameter());
    }
    //Going through each of the conditions to determine the relation function call.
    for (unsigned int i = 0; i < queries.size(); ++i){
        if (queries[i].substr(0,1) == "'"){
            newRelation = newRelation.select1(i, queries[i]);
        }
        else{
            if (unseenVariables.find(queries[i]) == unseenVariables.end()){
                unseenVariables.insert({queries[i], i});
                projectColumns.push_back(i);
                variable.push_back(queries[i]);
            }
            else {
                int matchingIndex = 0;
                for (unsigned int j = 0; j < variable.size(); ++j){
                    if (queries[i] == variable[j]){
                        matchingIndex = projectColumns[j];
                        break;
                    }
                }
                newRelation = newRelation.select2(i, matchingIndex);
            }
        }
    }
    newRelation = newRelation.project(projectColumns);
    newRelation.rename(variable);
    variable.clear();
    projectColumns.clear();
    unseenVariables.clear();
    return newRelation;

}



