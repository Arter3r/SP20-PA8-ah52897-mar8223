// Folder Class for Plagiarism Checker
// EE 312 Spring 2019
// Created by Abdullah on 4/26/2020.
//
// This folder class contains all the methods related to
// exploring a system folder required by the plagiarism catcher.
// It must be constructed using a linux directory path as constructor input.

#ifndef PLAGIARISMCATCHER_FOLDER_H
#define PLAGIARISMCATCHER_FOLDER_H

#include <iostream>
#include <string>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include "Document.h"

using namespace std;

class Folder {
private:
    string directory;
    vector<Document> files;
public:
    Folder(string path);
    Document& getDocument(string filename);
    Document& operator[](int index);
    Document& operator[](string filename);
    int size();

};


#endif //PLAGIARISMCATCHER_FOLDER_H
