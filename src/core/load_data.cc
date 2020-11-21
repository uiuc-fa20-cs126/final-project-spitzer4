//
// Created by Kaleigh Spitzer on 11/9/20.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

size_t num_col = 4;
size_t num_row = 102;

void read_csv() {
    std::ifstream data("/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/data/routes.csv");
    std::string value;
    std::string value2;
    std::string int_value;

    std::string delim = ",";
    size_t i = 0;
    std::string token;

    std::vector<std::string> route_id;
    std::vector<std::string> route_short_name;
    std::vector<std::string> route_long_name;
    std::vector<std::string> route_color;

    size_t route_id_index = 0;
    size_t route_short_name_index = 1;
    size_t route_long_name_index = 2;
    size_t route_color_index = 3;

    getline(data, value, '\n');

    while (data.good()) {
        getline(data, value2, '\n');
        while ((i = value2.find(delim)) != std::string::npos) {
            token = value2.substr(0, i);
            std::cout << token << std::endl;
            value2.erase(0, i + delim.length());
        }
    }
    std::cout << value2 << std::endl;

//    while (data.good()) {
//        std::string currentline = getline(data, value);
//    }
//
//
//    getline(data, value, ',');
//    std::cout << value << " ";
//    getline(data, value, ',');
//    std::cout << value << " ";
//    getline(data, value, ',');
//    std::cout << value << " ";
//    getline(data, value, '\n');
//    std::cout << value << "\n";
//
//    while (data.peek() != '\n') {
//        getline(data, int_value, ',');
//        route_id.push_back(int_value);
//        getline(data, int_value, ',');
//        route_short_name.push_back(int_value);
//        getline(data, int_value, ',');
//        route_long_name.push_back(int_value);
//        getline(data, int_value, ',');
//        route_color.push_back(int_value);
//    }
//
//    for (size_t i = 0; i < route_id.size(); i++) {
//        std::cout << route_id[i] << " " << route_short_name[i] << " " << route_long_name[i] << " " << route_color[i] << std::endl;
//    }





//    std::string line;
//    std::string colname;
//    size_t val;
//    std::vector<std::pair<std::string, std::vector<int>>> result;
//    while (data.good()) {
//        getline(data, line);
//        std::stringstream ss(line);
//        while (getline(ss, colname, ',')) {
//            result.push_back({colname, std::vector<int> {}});
//        }
//    }
//
//    while (getline(data, line)) {
//        std::stringstream ss(line);
//        size_t col_num = 0;
//        while (ss >> val) {
//            result.at(col_num).second.push_back(val);
//            if (ss.peek() == ',') {
//                ss.ignore();
//            }
//            col_num++;
//        }
//    }
//    data.close();
//    return result;
}

//void open(std::istream& istream, char delim = ',') {
//    std::string line;
//    clear();
//    while (getline(istream, line)) {
//        size_t nCol = 0;
//        std::istringstream line_stream(line);
//        std::string cell;
//        while (getline(line_stream, cell, delim)) {
//            data_map[std::make_pair(nCol, num_row)] = trim(cell);
//            nCol++;
//        }
//        num_col = std::max(num_col, nCol);
//        num_row++;
//    }
//}

int main() {
    read_csv();
    return 0;
}