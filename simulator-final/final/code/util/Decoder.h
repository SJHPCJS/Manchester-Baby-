#ifndef MANCHESTERBABYSIMULATOR_DECODER_H
#define MANCHESTERBABYSIMULATOR_DECODER_H

#include <string>
#include <algorithm>

/* Decoder Class
 * This class contains public method to get operand and opcode from
 * binary instruction
 */
using namespace std;

class Decoder {
public:
    //get the opcode from binary instruction
    static int getOpcode(const string& binaryInstruct);
    //get the operand from binary instruction
    static int getOperand(const string& binaryInstruct);
};


#endif //MANCHESTERBABYSIMULATOR_DECODER_H
