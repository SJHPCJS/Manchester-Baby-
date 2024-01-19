#ifndef MANCHESTERBABYSIMULATOR_MANCHESTERBABY_H
#define MANCHESTERBABYSIMULATOR_MANCHESTERBABY_H

#include <iostream>
#include <cmath>
#include "util/Decoder.cpp"
#include "util/Store.cpp"
#include "util/Control.cpp"
#include "util/Accumulator.cpp"
using namespace std;

class ManchesterBaby {
public:
    ManchesterBaby(Store* store, Control* control, Accumulator* accumulator);
    void executeCommand(int operand, int opcode);
    void loadProgram();
private:
    Store* store;
    Control* control;
    Accumulator* accumulator;
    //set CI to content of Store location
    void JMP(int operand);
    //add content of Store location to CI
    void JRP(int operand);
    //load negative from store
    void LDN(int operand);
    //copy Accumulator to Store location
    void STO(int operand);
    //subtract content of Store location from Accumulator
    void SUB(int operand);
    //read a number from input buffer into store
    void RDI(int operand);
    //increment CI if Accumulator value negative, otherwise do nothing
    void CMP(int operand);

    void displayContent();
};


#endif //MANCHESTERBABYSIMULATOR_MANCHESTERBABY_H
