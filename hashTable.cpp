#include "hashTable.h"

hashTable::hashTable(int size) : size(size), table(size) {}

//void hashTable::insert(treeNode& Node) {
//    Node.get_point();
//    int index = hash(Node);
//    table[index].push_back(student);
//}
//
//int hashTable::search(const string& name) {
//    int index = hash(name);
//    for (const auto& student : table[index]) {
//        if (student.name == name) {
//            return student.roll_number;
//        }
//    }
//    return -1; // Name not found
//}