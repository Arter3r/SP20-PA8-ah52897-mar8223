//
// Created by Abdullah on 4/26/2020.
//

#include <csignal>
#include "Folder.h"

Folder::Folder(string path, int seq_length) {
    directory = path;
    DIR *dp;
    struct dirent *file;
    if((dp  = opendir(path.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << path << endl;
        raise(errno);
    }

    while ((file = readdir(dp)) != NULL) {
        if(string(file->d_name) != ".." && string(file->d_name) != ".")
            files.push_back(Document((path + "/" + string(file->d_name)), seq_length));
    }
    closedir(dp);
    similiarities.resize(files.size(), vector<int>(files.size()));
    fillSimiliarities();
}

int Folder::size() {
    return files.size();
}

Document& Folder::operator[](int index) {
    return files[index];
}

void Folder::fillSimiliarities() {
    for(int i = 0; i < files.size()-1; i++){
        for(int j = i+1; j < files.size(); j++){
            int similiarSequences = 0;
            for(auto& wordCount:files[i].getSequences()){
                auto& other = files[j].getSequences();
                auto otherWordCount = other.find(wordCount.first);
                if(otherWordCount != other.end())
                    similiarSequences += min(wordCount.second, otherWordCount->second);
            }
            similiarities[i][j] = similiarSequences;
        }
    }
}

vector<vector<int>>& Folder::getSimiliarities() {
    return similiarities;
}
