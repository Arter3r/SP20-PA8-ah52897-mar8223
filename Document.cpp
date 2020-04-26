//
// Created by Abdullah on 4/26/2020.
//

#include "Document.h"

Document::Document(string filename) {
    this->filename = filename;
    //populate sequences.
}

string Document::getName() {
    return filename;
}
