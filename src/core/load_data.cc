//
// Created by Kaleigh Spitzer on 11/9/20.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>

std::map<std::string, std::vector<std::string>> read_csv() {
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

    std::vector<std::string> line_values;

    std::map<std::string, std::vector<std::string>> route_map;

    getline(data, value, '\n');

    while (data.good()) {
        getline(data, value2, '\n');

        while ((i = value2.find(delim)) != std::string::npos) {
            token = value2.substr(0, i);
            line_values.push_back(token);
            value2.erase(0, i + delim.length());
        }

        route_id.push_back(line_values.at(route_id_index));
        route_short_name.push_back(line_values.at(route_short_name_index));
        route_long_name.push_back(line_values.at(route_long_name_index));
        route_color.push_back(value2);
        line_values.clear();
    }

    for (size_t j = 0; j < route_id.size(); j++) {
        route_map[route_id[j]] = {route_short_name[j], route_long_name[j], route_color[j]};
    }

    return route_map;
}


int main() {
    read_csv();
    return 0;
}