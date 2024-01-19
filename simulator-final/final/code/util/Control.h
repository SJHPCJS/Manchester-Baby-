#ifndef MANCHESTERBABYSIMULATOR_CONTROL_H
#define MANCHESTERBABYSIMULATOR_CONTROL_H

/* Control Class
 * This class contains private field to save CI and PI
 * and public methods to get, set and increase CI and PI
 */

class Control {
private:
    int CI;
    int PI;

public:
    Control();
    int getCI();
    int getPI();
    void setCI(int CI);
    void setPI(int PI);
    void increaseCI();
    void increasePI();
};


#endif //MANCHESTERBABYSIMULATOR_CONTROL_H
