//
// Created by Kaleigh Spitzer on 11/9/20.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>

std::string routes_file_path = "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/data/routes.csv";
std::string trips_file_path = "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/data/trips.csv";

std::map<std::string, std::vector<std::string>> route_map;

void create_routes_map() {
    std::ifstream data(routes_file_path);
    std::string first_line;
    std::string line;

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

    std::vector<std::string> line_values;

    getline(data, first_line, '\n');

    while (data.good()) {
        getline(data, line, '\n');

        while ((i = line.find(delim)) != std::string::npos) {
            token = line.substr(0, i);
            line_values.push_back(token);
            line.erase(0, i + delim.length());
        }

        route_id.push_back(line_values.at(route_id_index));
        route_short_name.push_back(line_values.at(route_short_name_index));
        route_long_name.push_back(line_values.at(route_long_name_index));
        route_color.push_back(line);
        line_values.clear();
    }

    for (size_t j = 0; j < route_id.size(); j++) {
        route_map[route_id[j]] = {route_short_name[j], route_long_name[j], route_color[j]};
    }

//    for (std::map<std::string, std::vector<std::string>>::const_iterator it = route_map.begin(); it != route_map.end(); ++it) {
//            for (size_t i = 0; i < it->second.size(); i++) {
//                std::cout << it->first << it->second.at(i) << "\n";
//            }
//    }

    //return route_map;

    // -------------- TRIP FILE DATA ---------------
    std::multimap<std::string, std::string> trips_map;

    std::ifstream data2(trips_file_path);
    std::string first_line2;
    std::string line2;

    std::string delim2 = ",";
    size_t k = 0;
    std::string token2;

    std::vector<std::string> line_values2;

    std::vector<std::string> route_id2;
    std::vector<std::string> trip_id;

    size_t route_id_index2 = 0;

    getline(data2, first_line2, '\n');

    while (data2.good()) {
        getline(data2, line2, '\n');

        while ((k = line2.find(delim)) != std::string::npos) {
            token2 = line2.substr(0, k);
            line_values2.push_back(token2);
            line2.erase(0, k + delim2.length());
        }

        route_id2.push_back(line_values2.at(route_id_index2));
        trip_id.push_back(line);
        line_values2.clear();
    }

    for (size_t i = 0; i < route_id2.size(); i++) {
        trips_map.insert(std::make_pair(route_id2[i], trip_id[i]));
    }

    for (std::map<std::string, std::string>::const_iterator it1 = trips_map.begin(); it1 != trips_map.end(); ++it1) {
        std::cout << it1->first << " " << it1->second << "\n";
    }

    std::map<std::string, std::vector<std::string>> id_to_matching_trip_ids;
    std::vector<std::string> list_of_matching_trip_ids;

    for (std::multimap<std::string, std::string>::iterator values = trips_map.begin(); values != trips_map.end(); ++values) {
        for (size_t j = 0; j < route_id2.size(); j++) {
            if (values -> first == route_id2[j]) {
                list_of_matching_trip_ids.push_back(values -> second);
            }
            id_to_matching_trip_ids.insert(std::make_pair(route_id2[j], list_of_matching_trip_ids));
        }
    }
    for (std::map<std::string, std::vector<std::string>>::const_iterator it = id_to_matching_trip_ids.begin(); it != id_to_matching_trip_ids.end(); ++it) {
        for (size_t l = 0; l < it->second.size(); l++) {
            std::cout << it->first << it->second.at(l) << "\n";
        }
    }
}

//std::multimap<std::string, std::string> create_trips_map() {
//    std::multimap<std::string, std::string> trips_map;
//
//    std::ifstream data(trips_file_path);
//    std::string first_line;
//    std::string line;
//
//    std::string delim = ",";
//    size_t i = 0;
//    std::string token;
//
//    std::vector<std::string> line_values;
//
//    std::vector<std::string> route_id;
//    std::vector<std::string> trip_id;
//
//    size_t route_id_index = 0;
//
//    getline(data, first_line, '\n');
//
//    while (data.good()) {
//        getline(data, line, '\n');
//
//        while ((i = line.find(delim)) != std::string::npos) {
//            token = line.substr(0, i);
//            line_values.push_back(token);
//            line.erase(0, i + delim.length());
//        }
//
//        route_id.push_back(line_values.at(route_id_index));
//        trip_id.push_back(line);
//        line_values.clear();
//    }
//
//    for (size_t i = 0; i < route_id.size(); i++) {
//        trips_map.insert(std::make_pair(route_id[i], trip_id[i]));
//    }
//
//    for (std::multimap<std::string, std::string>::iterator values = trips_map.begin(); values != trips_map.end(); ++values) {
//        for (size_t j = 0; j < route_id.size(); j++) {
//            if (values -> first == route_id[i]) {
//
//            }
//        }
//    }

//    for (size_t j = 0; j < route_id.size(); j++) {
//        trips_map[route_id[j]] = {trip_id[j]};
//    }
//  }



int main() {
    create_routes_map();
    return 0;
}