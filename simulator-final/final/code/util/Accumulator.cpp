#include "Accumulator.h"

using namespace std;

long long Accumulator::getData() {
    return this->data;
}

void Accumulator::setData(long long data) {
    this->data = data;
}

long long Accumulator::reversedBin2Dec(const string &data) {
    long long ret = 0;
    for (int i = 0; i < 31; i++) {
        ret += (stoi(to_string(data[i]))-48)*(long long)pow(2,i);
    }
    if (data[31]=='1') {
        ret = -ret;
    }
    return ret;
}

string Accumulator::dec2ReversedBinString(long long decNum) {
    bool isNegative = (decNum<0);
    if (isNegative) {
        decNum = -decNum;
    }
    string binStr;
    for (int i = 0; i < 32; i++) {
        binStr = to_string(decNum % 2) + binStr;
        decNum /= 2;
    }

    reverse(binStr.begin(), binStr.end());
    if (isNegative) {
        binStr[31] = '1';
    }

    return binStr;
}
