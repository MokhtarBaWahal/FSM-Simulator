// StateFactory.h
#pragma once
#include "State.h"
#include <string>
class StateFactory {
public:
    static State* createState(const std::string& type);
};
