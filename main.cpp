// Driver for Plagiarism Catcher
// EE 312 Spring 2019
// Created by Abdullah on 4/26/2020.
//Lab Partner: Sakib Abdur Rahman
// The driver accepts two command line arguments:
// 1) The directory to work on
// 2) The minimum number of shared n-word sequences that constitutes plagiarism.
//
// It outputs the resulting matches to stdout.
#include <iostream>
#include "Folder.h"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 4){
        cout << "Please supply a folder path, a sequence length and a minimum match threshold." << endl;
        exit(1);
    }
    string path = argv[1];
    int seq_length = atoi(argv[2]);
    int threshold = atoi(argv[3]);

    Folder folder(path, seq_length);
    for (int i = 0; i < folder.size(); i++) {
        for (int j = i+1; j<folder.getSimiliarities().size(); j++) {
            int similiarities = folder.getSimiliarities()[i][j];
            if (similiarities >= threshold){
                cout << similiarities << ": " << folder[i].getName() << ", " << folder[j].getName() << endl;
            }
        }
    }
    return 0;
}
