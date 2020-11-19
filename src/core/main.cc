//
// Created by Kaleigh Spitzer on 11/9/20.
//

#include <fstream>
#include <sstream>
#include <iostream>

int main() {
    std::ifstream data("routes.csv");
    std::string line;

    while (data.good()) {
        getline(data, line, ',');
        std::cout << std::string(line) << std::endl;
    }
}

