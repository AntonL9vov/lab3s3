#pragma once
#ifndef KEYVALUEPAIR_H
#define KEYVALUEPAIR_H
#include <iostream>
#include <fstream>
#include <string>
//#include "iss.h"

template <typename F, typename S>
struct Pair {

    F first = 0;
    S second = 0;

    bool operator==(Pair<F, S>& other) const {
        return (this->first == other.first) && (this->second == other.second);
    }
    bool operator!=(Pair<F, S>& other) const {
        return (this->first != other.first) || (this->second != other.second);
    }
};




#endif // KEYVALUEPAIR_H
