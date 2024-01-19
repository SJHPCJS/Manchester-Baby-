#ifndef MANCHESTERBABYSIMULATOR_STORE_H
#define MANCHESTERBABYSIMULATOR_STORE_H

#include <iostream>
using namespace std;

/* Store Class
 * This class contains 2d-array to represent Store and public method to get/set rows of memory.
 */

class Store {
private:
    static const int ROWS = 32;
    static const int COLS = 32;
    string memory[ROWS];
public:
    Store();
    string getRow(int row);
    void setRow(int row, const string& value);
    void displayMemory() const;
};

#endif //MANCHESTERBABYSIMULATOR_STORE_H
