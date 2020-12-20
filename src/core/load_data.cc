//
// Created by Kaleigh Spitzer on 11/9/20.
//

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/include/core/trip.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/include/core/load_data.h"

std::string routes_file_path = "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/data/routes.csv";
std::string trips_file_path = "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/data/trips.csv";

std::map<std::string, Route> route_id_to_route_map;

std::map<std::string, std::string> Data::create_trip_map() {
    std::map<std::string, std::string> route_id_to_trip_id_map;

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

        route_id_to_trip_id_map.insert(std::make_pair(route_id2, trip_id));
    }

    return route_id_to_trip_id_map;
}

std::map<std::string, Route> Data::create_route_map() {
    std::map<std::string, std::string> trips_map = Data::create_trip_map();

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
    std::string trip_id;

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

        for (std::map<std::string, std::string>::iterator it = trips_map.begin(); it != trips_map.end(); ++it) {
            if (it->first == route_id) {
                trip_id = it->second;
            }
        }

        Route route(route_id, route_short_name, route_long_name, route_color, trip_id);
        route_id_to_route_map.insert(std::make_pair(route_id, route));
    }
    for (std::map<std::string, Route>::const_iterator it = route_id_to_route_map.begin(); it != route_id_to_route_map.end(); ++it) {
        std::cout << it->first << " " << it->second.id << " " << it->second.longName << " " << it->second.shortName << " " << it->second.color << "\n" << it->second.trip_id << "\n";
    }

    return route_id_to_route_map;
}

int Data::main() {
    Data::create_route_map();
    return 0;
}