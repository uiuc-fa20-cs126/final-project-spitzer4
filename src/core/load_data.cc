//
// Created by Kaleigh Spitzer on 11/9/20.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

std::vector<std::pair<std::string, std::vector<int>>> read_csv() {
    std::ifstream data("/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/data/routes.csv");
    std::string line;
    std::string colname;
    size_t val;
    std::vector<std::pair<std::string, std::vector<int>>> result;
    while (data.good()) {
        getline(data, line);
        std::stringstream ss(line);
        while (getline(ss, colname, ',')) {
            result.push_back({colname, std::vector<int> {}});
        }
    }

    while (getline(data, line)) {
        std::stringstream ss(line);
        size_t col_num = 0;
        while (ss >> val) {
            result.at(col_num).second.push_back(val);
            if (ss.peek() == ',') {
                ss.ignore();
            }
            col_num++;
        }
    }
    data.close();
    return result;
}

int main() {
    read_csv();
    return 0;
}