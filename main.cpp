// Driver for Plagiarism Catcher
// EE 312 Spring 2019
// Created by Abdullah on 4/26/2020.
//
// The driver accepts two command line arguments:
// 1) The directory to work on
// 2) The minimum number of shared n-word sequences that constitutes plagiarism.
//
// It outputs the resulting matches to stdout.
#include <iostream>
#include "Folder.h"

using namespace std;

int main(int argc, char* argv[]) {
    Folder myFolder("./sm_doc_set");
    cout << myFolder.size() << endl;
    for (int i = 0; i < myFolder.size(); i++) {
        cout << myFolder[i].getName() << endl;
    }
    return 0;
}