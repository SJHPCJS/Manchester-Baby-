#include "FileReader.h"
#include <cstdio>

FileReader::FileReader(FILE* file) {
    this->file = file;
}

FileReader::FileReader(const string& path) {
    FILE* fp = fopen(path.c_str(),"r");
    this->file = fp;
}

FileReader::~FileReader() {
    fclose(this->file);
}

string FileReader::readLine() {
    string line;
    if (this->file) {
        char buf[256];
        if(fgets(buf, 256, file) != nullptr) {
            line = buf;
        }
        // 删除换行符
        size_t n = line.find('\n');
        if (n != string::npos) {
            line.erase(n);
        }
    }
    return line;
}

vector<string> FileReader::readLines() {
    vector<string> lines;

    if (!file) {
        return lines;
    }

    while (!feof(this->file)) {
        string line = readLine();
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    return lines;
}