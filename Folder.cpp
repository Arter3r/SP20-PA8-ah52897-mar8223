//
// Created by Abdullah on 4/26/2020.
//

#include "Folder.h"

Folder::Folder(string path) {
    directory = path;
    DIR *dp;
    struct dirent *file;
    if((dp  = opendir(path.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << path << endl;
        raise(errno);
    }

    while ((file = readdir(dp)) != NULL) {
        if(string(file->d_name) != ".." && string(file->d_name) != ".")
            files.push_back(string(file->d_name));
    }
    closedir(dp);
}

int Folder::size() {
    return files.size();
}

Document& Folder::operator[](int index) {
    return files[index];
}
