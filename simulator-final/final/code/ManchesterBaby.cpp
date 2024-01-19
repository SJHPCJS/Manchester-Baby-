#include <vector>
#include "ManchesterBaby.h"
#include "util/FileReader.cpp"

string decToReversed32Bin(const string &decStr);

ManchesterBaby::ManchesterBaby(Store* store, Control* control, Accumulator* accumulator) {
    this->store = store;
    this->control = control;
    this->accumulator = accumulator;
}

void ManchesterBaby::executeCommand(int opcode, int operand) {
    switch (opcode) {
        case 0b000:
            cout << "executing JMP " << operand << endl;
            JMP(operand);
            break;
        case 0b001:
            cout << "executing JRP " << operand << endl;
            JRP(operand);
            break;
        case 0b010:
            cout << "executing LDN " << operand << endl;
            LDN(operand);
            break;
        case 0b011:
            cout << "executing STO " << operand << endl;
            STO(operand);
            break;
        case 0b100:
            cout << "executing SUB " << operand << endl;
            SUB(operand);
            break;
        case 0b101:
            cout << "executing RDI " << operand << endl;
            RDI(operand);
            break;
        case 0b110:
            cout << "executing CMP " << endl;
            CMP(operand);
            break;
        case 0b111:
            cout << "stopping program..." << endl;
            break;
        default:
            cout << "Invalid opcode!" << endl;
            break;
    }
}

void ManchesterBaby::JMP(int operand) {
    this->control->setCI(stoi(this->store->getRow(operand), nullptr,2));
}

void ManchesterBaby::JRP(int operand) {
    this->control->setCI(this->control->getCI()+stoi(this->store->getRow(operand), nullptr,2));
}

void ManchesterBaby::LDN(int operand) {
    this->accumulator->setData(-this->accumulator->reversedBin2Dec(this->store->getRow(operand)));
}

void ManchesterBaby::STO(int operand) {
    this->store->setRow(operand, this->accumulator->dec2ReversedBinString(this->accumulator->getData()));
}

void ManchesterBaby::SUB(int operand) {
    long long minuend = this->accumulator->getData();
    string subtrahendString = this->store->getRow(operand);
    long long subtrahend = this->accumulator->reversedBin2Dec(subtrahendString);

    long long result = minuend - subtrahend;

    this->accumulator->setData(result);
}

void ManchesterBaby::RDI(int operand) {
    long long n;
    cin >> n;

    this->store->setRow(operand,this->accumulator->dec2ReversedBinString(n));
}

void ManchesterBaby::CMP(int operand) {
    if (this->accumulator->getData() < 0) {
        this->control->increaseCI();
    }
}

void ManchesterBaby::loadProgram() {
    string input;
    cout << "Please enter the path of the program you want to load" << endl;
    cout << ">";
    cin >> input;

    FileReader fileReader(input);
    vector<string> codes = fileReader.readLines();

    int lineNum = 0;
    for (const auto &item: codes) {
        this->store->setRow(lineNum++,item);
    }

    cout << "Program was loaded successfully!" << endl;
    cout << "The following is the display of memory:" << endl;
    this->store->displayMemory();

    cout << "Do you want to run this program ? (y/n)" << endl;
    cin >> input;
    if (input != "y") return;

    int opcode, operand;
    string currentInstruction;
    do {
        this->control->increaseCI();
        this->control->setPI(this->control->getCI());
        currentInstruction = this->store->getRow(this->control->getPI());
        opcode = Decoder::getOpcode(currentInstruction);
        operand = Decoder::getOperand(currentInstruction);

        this->executeCommand(opcode,operand);

        displayContent();

        cout << "Execute Next Instruction ? (y/n)" << endl;
        string choice;
        cin.clear();
        cin >> choice;
        if (choice != "y") break;
    } while (opcode!=0b111);
}

void ManchesterBaby::displayContent() {
    cout << "=========================== Store ===========================" << endl;
    this->store->displayMemory();
    cout << "========================== Control ==========================" << endl;
    cout << "CI = " << this->control->getCI() << endl;
    cout << "PI = " << this->control->getPI() << endl;
    cout << "========================= Accumulator =========================" << endl;
    string accString = this->accumulator->dec2ReversedBinString(this->accumulator->getData());
    for (const auto &item: accString) {
        cout << item << " ";
    }
    cout << endl;
}
