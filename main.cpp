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
    Folder myFolder("./big_doc_set");
//    cout << myFolder.size() << endl;
//    for (int i = 0; i < myFolder.size(); i++) {
//        cout << myFolder[i].getName() << endl;
//        for (int j = i+1; j<myFolder.getSimiliarities().size(); j++)
//            cout << myFolder.getSimiliarities()[i][j] << ' ';
//        cout << endl << endl;
//    }
    //cout << endl << "In " << myFolder[0].getName() << ": " << endl;
    //for (auto i = myFolder[0].getSequences().begin(); i != myFolder[0].getSequences().end(); ++i){
    //    string key = i->first;
    //    int value = i->second;
    //    cout << "\"" << key << "\" occurs " << value << " times" << endl;
    //}
    return 0;
}