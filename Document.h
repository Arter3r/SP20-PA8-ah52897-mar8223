// Document Class for Plagiarism Checker
// EE 312 Spring 2019
// Created by Abdullah on 4/26/2020.
//
// This document class contains all the methods related to
// opening a file and creating its in-program representation.
// It must be constructed using a file name as an input to the constructor.

#ifndef PLAGIARISMCATCHER_DOCUMENT_H
#define PLAGIARISMCATCHER_DOCUMENT_H

#include <string>
#include <map>

using namespace std;

class Document {
private:
    string filename;
    map<string, int> sequences;
public:
    const int SEQUENCE_LENGTH;
    Document();
    Document(string filename, int seq_length);
    Document& copy(Document& other);
    Document& operator=(Document& rhs);
    map<string, int>& getSequences();

    string getName() const;
    void fillSequences();

};


#endif //PLAGIARISMCATCHER_DOCUMENT_H
