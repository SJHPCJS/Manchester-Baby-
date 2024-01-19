#include <iostream>
#include <fstream>
#include "util/AssembleUtil.cpp"

using namespace std;

int writeLinesToFile(const vector<string> &lines, const string &filePath);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Invalid number of parameters." << endl;
        return 3;
    }
    try {
        map<string, string> labelMap = AssembleUtil::getLabelMap(argv[1]);

        FileReader fileReader(argv[1]);
        vector<string> code = fileReader.readLines();
        vector<string> mcCodeBuffer;
        mcCodeBuffer.reserve(code.size());
        for (const auto &item: code) {
            string tmp = AssembleUtil::processInstructionLine(item, labelMap);
            if (!tmp.empty()) {
                mcCodeBuffer.push_back(tmp);
            }
        }

        return writeLinesToFile(mcCodeBuffer, argv[2]);
    } catch (...) {
        return 1;
    }
}

int writeLinesToFile(const vector<string> &lines, const string &filePath) {

    ofstream file(filePath);

    if (!file.is_open()) {
        cerr << "Failed to write machine code to file " << filePath << endl;
        return 2;
    }

    for (const auto &line: lines) {
        file << line << "\n";
    }

    file.close();

    cout << "Assembled " << lines.size() << " lines to file \'" << filePath << "\' successfully" << endl;
    return 0;
}
