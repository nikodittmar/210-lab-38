// COMSC 210 | Lab 38 | Niko Dittmar
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

    int choice = 0;
    string value, newValue;

    while (choice != 5) {
        cout << "\nBinary Search Tree Editor\n";
        cout << "[1] Add record\n";
        cout << "[2] Delete record\n";
        cout << "[3] Search for record\n";
        cout << "[4] Edit record\n";
        cout << "[5] Quit\n";
        cout << "Enter your choice --> ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the record to add --> ";
                cin.ignore();
                getline(cin, value);
                bst.insertNode(value);
                cout << "Record added.\n";
                break;

            case 2:
                cout << "Enter the record to delete: ";
                cin.ignore();
                getline(cin, value);
                if (bst.searchNode(value)) {
                    bst.remove(value);
                    cout << "Record deleted.\n";
                } else {
                    cout << "Record not found.\n";
                }
                break;

            case 3:
                cout << "Enter the record to search: ";
                cin.ignore();
                getline(cin, value);
                if (bst.searchNode(value)) {
                    cout << "Record exists.\n";
                } else {
                    cout << "Record not found.\n";
                }
                break;

            case 4:
                cout << "Enter the record to edit: ";
                cin.ignore();
                getline(cin, value);
                if (bst.searchNode(value)) {
                    cout << "Enter the new record: ";
                    getline(cin, newValue);
                    bst.remove(value);
                    bst.insertNode(newValue);
                    cout << "Record updated.\n";
                } else {
                    cout << "Record not found.\n";
                }
                break;

            case 5:
                cout << "Quitting." << endl;
                break;

            default:
                cout << "Invalid choice. Choose again --> " << endl;
        }
    }

    return 0;
}
