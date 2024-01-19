#ifndef MANCHESTERBABYSIMULATOR_ASSEMBLEUTIL_H
#define MANCHESTERBABYSIMULATOR_ASSEMBLEUTIL_H

#include <string>
#include <map>

using namespace std;

/* Assemble Class
 * This class contains public methods to translate assemble language to machine code
 */

class AssembleUtil {
public:
    static map<string,string> getLabelMap(const string& codePath);
    static string translateInstruction(const string& instruction);
    static string processInstructionLine(const string& instruction, map<string,string>labelMap);
private:
    static string decTo5Bin(const string& decStr);
    static string decToReversed32Bin(const string& decStr);
};


#endif //MANCHESTERBABYSIMULATOR_ASSEMBLEUTIL_H
