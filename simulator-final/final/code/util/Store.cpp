#include "Store.h"

Store::Store() {
    for (auto & i : this->memory) {
        i = "00000000000000000000000000000000";
    }
}

void Store::displayMemory() const {
    for (const auto & i : memory) {
        for (const auto & j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

}

string Store::getRow(int row) {
    if (row >= 0 && row < ROWS) {
        return memory[row];
    } else {
        // Handle out-of-bounds error (you may choose to throw an exception or return nullptr)
        std::cerr << "Error: Attempt to access out-of-bounds memory row." << std::endl;
        return "";
    }
}

void Store::setRow(int row, const string& value) {
    if (row >= 0 && row < ROWS) {
        memory[row] = value;
    } else {
        // Handle out-of-bounds error or nullptr (you may choose to throw an exception or ignore the operation)
        std::cerr << "Error: Attempt to set row at out-of-bounds memory location or with nullptr values." << std::endl;
    }
}
