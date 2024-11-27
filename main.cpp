#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

int main() {
    StringBinaryTree bst;

    ifstream file("codes.txt");
    if (!file) return 1;

    string next;
    while (getline(file, next)) bst.insertNode(next);

    file.close();

    bst.displayInOrder();

    return 0;
}
