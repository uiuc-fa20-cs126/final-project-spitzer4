//
// Created by Kaleigh Spitzer on 11/9/20.
//

#include <fstream>
#include <sstream>
#include <iostream>

void loadData(std::string fileName) {
    std::ifstream data("routes.csv");
    std::string line;
    while (data.good()) {
        getline(data, line, ',');
        std::cout << std::string(line) << std::endl;
    }
}