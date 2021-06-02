#include "Database.h"
#include <map>
#include "Relation.h"
#include <iostream>
using namespace std;

void Database::setDatabase(string tableName, Relation relation) {
    database.insert({tableName, relation});
}

Relation& Database::findDatabase(string table){
    return database.at(table);
}

map<string, Relation> Database::getDatabase() {
    return database;
}
