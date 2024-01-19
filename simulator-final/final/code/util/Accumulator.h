#ifndef MANCHESTERBABYSIMULATOR_ACCUMULATOR_H
#define MANCHESTERBABYSIMULATOR_ACCUMULATOR_H
#include <string>

class Accumulator {
private:
    long long data;
public:
    long long getData();
    void setData(long long data);
    long long reversedBin2Dec(const string &data);
    string dec2ReversedBinString(long long decNum);
};


#endif //MANCHESTERBABYSIMULATOR_ACCUMULATOR_H
