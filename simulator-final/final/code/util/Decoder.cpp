#include "Decoder.h"

int Decoder::getOperand(const string& binaryInstruct) {
    int binaryOperand;

    string operandStr = binaryInstruct.substr(0,13);
    reverse(operandStr.begin(), operandStr.end());

    binaryOperand = stoi(operandStr, nullptr,2);
    return binaryOperand;
}

int Decoder::getOpcode(const string& binaryInstruct) {
    int binaryOpcode;

    string opcodeStr = binaryInstruct.substr(13,3);
    reverse(opcodeStr.begin(), opcodeStr.end());


    binaryOpcode = stoi(opcodeStr, nullptr,2);
    return binaryOpcode;
}