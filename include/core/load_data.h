//
// Created by Kaleigh Spitzer on 11/19/20.
//

#ifndef FINAL_PROJECT_LOAD_DATA_H
#define FINAL_PROJECT_LOAD_DATA_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include "../../include/core/route.h"

class Data {
    public:
//        static int main();
        static std::map<std::string, std::string> CreateTripMap();
        static std::map<std::string, Route> CreateRouteMap();
    private:
};

#endif //FINAL_PROJECT_LOAD_DATA_H
