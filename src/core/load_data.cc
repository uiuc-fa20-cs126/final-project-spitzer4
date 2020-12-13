//
// Created by Kaleigh Spitzer on 11/9/20.
//

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/include/core/trip.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/include/core/load_data.h"

std::string routes_file_path = "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/data/routes.csv";
std::string trips_file_path = "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/data/trips.csv";

std::map<std::string, std::vector<std::string>> route_map;

//std::map<std::string, std::unique_ptr<Route>> route_id_to_object_map;
std::map<std::string, Route> route_id_to_route_map;

void create_routes_map() {
    std::ifstream data(routes_file_path);
    std::string first_line;
    std::string line;

    std::string delim = ",";
    size_t i = 0;
    std::string token;

    std::string route_id;
    std::string route_short_name;
    std::string route_long_name;
    std::string route_color;

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

        route_id = line_values.at(route_id_index);
        route_short_name = line_values.at(route_short_name_index);
        route_long_name = line_values.at(route_long_name_index);
        route_color = line;
        line_values.clear();

        Route route(route_id, route_short_name, route_long_name, route_color);
        route_id_to_route_map.insert(std::make_pair(route_id, route));
    }

//    for (std::map<std::string, Route>::const_iterator it = route_id_to_route_map.begin(); it != route_id_to_route_map.end(); ++it) {
//        std::cout << it->first << " " << it->second.id << " " << it->second.longName << " " << it->second.shortName << " " << it->second.color << "\n";
//    }

    // -------------- TRIP FILE DATA ---------------
    std::map<std::string, Trip> route_id_to_trip_map;

    std::ifstream data2(trips_file_path);
    std::string first_line2;
    std::string line2;

    std::string delim2 = ",";
    size_t k = 0;
    std::string token2;

    std::vector<std::string> line_values2;

    std::string route_id2;
    std::string trip_id;

    size_t route_id_index2 = 0;

    getline(data2, first_line2, '\n');

    while (data2.good()) {
        getline(data2, line2, '\n');

        while ((k = line2.find(delim2)) != std::string::npos) {
            token2 = line2.substr(0, k);
            line_values2.push_back(token2);
            line2.erase(0, k + delim2.length());
        }

        route_id2 = line_values2.at(route_id_index2);
        trip_id = line2;
        line_values2.clear();

        Trip trip(route_id2, trip_id);
        route_id_to_trip_map.insert(std::make_pair(route_id2, trip));
    }

    for (std::map<std::string, Trip>::const_iterator it2 = route_id_to_trip_map.begin(); it2 != route_id_to_trip_map.end(); ++it2) {
        std::cout << it2->first << " " << it2->second.trip_id << "\n";
    }

//    for (size_t i = 0; i < route_id2.size(); i++) {
////        trips_map.find(route_id2[i]) = {trip_id[i]};
//        trips_map.insert(std::make_pair(route_id2[i], trip_id[i]));
//    }

//    for (std::map<std::string, std::string>::const_iterator it1 = trips_map.begin(); it1 != trips_map.end(); ++it1) {
//        std::cout << it1->first << " " << it1->second << "\n";
//    }

//    std::map<std::string, std::vector<std::string>> id_to_matching_trip_ids;
//    std::vector<std::string> list_of_matching_trip_ids;
//
//    for (std::multimap<std::string, std::string>::iterator values = trips_map.begin(); values != trips_map.end(); ++values) {
//        for (size_t j = 0; j < route_id2.size(); j++) {
//            if (values -> first == route_id2[j]) {
//                list_of_matching_trip_ids.push_back(values -> second);
//                id_to_matching_trip_ids.insert(std::make_pair(route_id2[j], list_of_matching_trip_ids));
//            }
////            id_to_matching_trip_ids.insert(std::make_pair(route_id2[j], list_of_matching_trip_ids));
//        }
//    }

//    for (std::map<std::string, std::vector<std::string>>::const_iterator it2 = id_to_matching_trip_ids.begin(); it2 != id_to_matching_trip_ids.end(); ++it2) {
//        auto current_route_id = route_map.find(it2->first);
//        route_map.insert(current_route_id, it2->second);
//        for (size_t m = 0; m < route_id.size(); m++) {
//            if (it2->first == route_id[m]) {
//                route_map[route_id[m]] = {route_short_name[m], route_long_name[m], route_color[m], it2->second};
//            }
//        }
//    }

//    for (std::map<std::string, std::vector<std::string>>::const_iterator it = id_to_matching_trip_ids.begin(); it != id_to_matching_trip_ids.end(); ++it) {
//        for (size_t l = 0; l < it->second.size(); l++) {
//            std::cout << it->first << it->second.at(l) << "\n";
//        }
//    }
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