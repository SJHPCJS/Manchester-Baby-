#include "AssembleUtil.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include "FileReader.cpp"

using namespace std;

string AssembleUtil::translateInstruction(const string &instruction) {
    istringstream iss(instruction);
    string opcode;
    string operandString;

    iss >> opcode;
    iss >> operandString;
    string binaryOpcodeString;

    if (opcode == "JMP") {
        binaryOpcodeString = "000";
    } else if (opcode == "JRP") {
        binaryOpcodeString = "001";
    } else if (opcode == "LDN") {
        binaryOpcodeString = "010";
    } else if (opcode == "STO") {
        binaryOpcodeString = "011";
    } else if (opcode == "SUB") {
        binaryOpcodeString = "100";
    } else if (opcode == "RDI") {
        binaryOpcodeString = "101";
    } else if (opcode == "CMP") {
        binaryOpcodeString = "110";
    } else if (opcode == "STP") {
        return "00000000000001110000000000000000";
    } else if (opcode == "VAR") {
        return decToReversed32Bin(operandString);
    }
    string binaryOperandString = decTo5Bin(operandString);
    string machineCode(32, '0');
    for (int i = binaryOperandString.size() - 1; i >= 0; i--) {
        machineCode[4 - i] = binaryOperandString[i];
    }
    for (int j = binaryOpcodeString.size() - 1; j >= 0; j--) {
        machineCode[15 - j] = binaryOpcodeString[j];
    }

    return machineCode;
}

string AssembleUtil::processInstructionLine(const string &instruction, map<string, string> labelMap) {
    istringstream iss(instruction);
    string label;
    string opcode;
    string operandString;
    try {
        size_t colonPos = instruction.find(':');
        if (colonPos != string::npos) {
            getline(iss >> ws, label, ':');
            getline(iss >> ws, opcode, ' ');
            getline(iss >> ws, operandString, ';');
        } else {
            getline(iss >> ws, opcode, ' ');
            getline(iss >> ws, operandString, ';');
        }
        while (!operandString.empty() && isspace(operandString.back())) {
            operandString.pop_back();
        }

        if (opcode == ";") return "";
        if (labelMap.count(operandString) > 0) {
            operandString = labelMap[operandString];
        }

        string result_instruction = opcode + " " + operandString;

        return translateInstruction(result_instruction);
    } catch (...) {
        cerr << "Caught exception when interpreting instruction \'" << instruction << "\'" << endl;
        throw;
    }
}

map<string, string> AssembleUtil::getLabelMap(const string &codePath) {
    map<string, string> labelMap;

    FileReader fileReader(codePath);
    vector<string> code = fileReader.readLines();
    int lineNum = 0;
    try {
        for (const auto &item: code) {
            istringstream iss(item);
            string label;
            string opcode;
            string operandString;
            size_t colonPos = item.find(':');
            if (colonPos != string::npos) {
                getline(iss >> ws, label, ':');
                getline(iss >> ws, opcode, ' ');
                getline(iss >> ws, operandString, ';');
            } else {
                getline(iss >> ws, opcode, ' ');
                getline(iss >> ws, operandString, ';');
            }
            while (!operandString.empty() && isspace(operandString.back())) {
                operandString.pop_back();
            }
            if (opcode == ";") {
                continue;
            }
            if (!label.empty()) {
                labelMap.insert(make_pair(label, to_string(lineNum)));
            }
            lineNum++;
        }
    } catch (exception& e) {
        cerr << "Caught exception when doing label mapping on line " << lineNum << endl;
        throw;
    }
    return labelMap;
}

string AssembleUtil::decTo5Bin(const string &decStr) {
    int decNum = stoi(decStr);

    string binStr;
    for (int i = 0; i < 5; i++) {
        binStr = to_string(decNum % 2) + binStr;
        decNum /= 2;
    }

    return binStr;
}

string AssembleUtil::decToReversed32Bin(const string &decStr) {
    int decNum = stoi(decStr);

    string binStr;
    for (int i = 0; i < 32; i++) {
        binStr = to_string(decNum % 2) + binStr;
        decNum /= 2;
    }
    reverse(binStr.begin(), binStr.end());

    return binStr;
}