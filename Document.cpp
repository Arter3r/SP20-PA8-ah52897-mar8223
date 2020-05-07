//
// Created by Abdullah on 4/26/2020.
//

#include <fstream>
#include <algorithm>
#include "Document.h"

struct Node{
    string value;
    Node* next;
    Node* previous;
} typedef;
typedef Node* Head;
typedef Node* Tail;
void cleanString(string& s);
void stringify(Head head, string &result);

Document::Document(string filename, int seq_length) : SEQUENCE_LENGTH(seq_length) {
    this->filename = filename;
    //populate sequences.
    ifstream inFile;
    inFile.open(filename.c_str());
    string s;
    Head head = NULL;
    Tail tail = NULL;
    for(int i = 0; i< SEQUENCE_LENGTH; i++){
        if(inFile>>s){
            cleanString(s);
            //Create Node
            Node* latestWord = new Node;
            latestWord->value = s;
            latestWord->next = NULL;
            latestWord->previous = tail;
            if(head == NULL){
                head = latestWord;
                tail = NULL;
            } else if(tail == NULL){
                head->next = latestWord;
                tail = latestWord;
                tail->previous = head;
            }else {
                //Add word to end of list
                tail->next = latestWord;
                tail = latestWord;
            }
        } else {
            //file not long enough. Not valid.
            return;
        }
    }
    string key = "";
    stringify(head, key);
    sequences[key] += 1;

    while (inFile>>s) {
        cleanString(s);
        //Create Node
        Node* latestWord = new Node;
        latestWord->value = s;
        latestWord->next = NULL;
        latestWord->previous = tail;
        //Add word to end of list
        tail->next = latestWord;
        tail = latestWord;
        //Delete current head
        Head prevHead = head;
        head = prevHead->next;
        head->previous = NULL;
        delete prevHead;
        string key = "";
        stringify(head, key);
        sequences[key] += 1;
    }
    //Clear linked list
    for(int i = 0; i < SEQUENCE_LENGTH; i++){
        //Delete current head
        Head prevHead = head;
        head = prevHead->next;
        if(head != NULL)
            head->previous = NULL;
        delete prevHead;
    }
}

string Document::getName() const {
    return filename;
}

map<string, int>& Document::getSequences() {
    return sequences;
}

void stringify(const Head head, string& result) {
    auto headCopy = head;
    while(headCopy != NULL){
        result += headCopy->value;
        headCopy = headCopy->next;
        if(headCopy!=NULL)
            result += " ";
    }
}

void cleanString(string& s){
    s.erase(std::remove_if(s.begin(), s.end(),
        [](char const& c) -> bool {return !std::isalnum(c);}),
            s.end()); //Remove all non-alphanumeric characters from string.
    for (auto & c: s) c = toupper(c);
}