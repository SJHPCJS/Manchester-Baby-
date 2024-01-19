#include "Control.h"

Control::Control() {
    this->CI = 0;
    this->PI = 0;
}

int Control::getCI() {
    return this->CI;
}

int Control::getPI() {
    return this->PI;
}

void Control::setCI(int CI) {
    this->CI = CI;
}

void Control::setPI(int PI) {
    this->PI = PI;
}

void Control::increaseCI() {
    this->CI++;
}

void Control::increasePI() {
    this->PI++;
}