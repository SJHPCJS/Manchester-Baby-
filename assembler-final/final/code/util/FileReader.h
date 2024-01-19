#ifndef MANCHESTERBABYSIMULATOR_FILEREADER_H
#define MANCHESTERBABYSIMULATOR_FILEREADER_H
#include <string>
#include <vector>

/* FileReader Class
 * This class contains private field to save a file pointer
 * and public methods to read contents from that file
 */

using namespace std;

class FileReader {
public:
    explicit FileReader(FILE* file);
    explicit FileReader(const string& path);
    ~FileReader();
    string readLine();
    vector<string> readLines();
private:
    FILE* file;
};


#endif //MANCHESTERBABYSIMULATOR_FILEREADER_H
