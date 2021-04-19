//
// Created by Kaleigh Spitzer on 11/9/20.
//

#include "../../include/core/load_data.h"

std::string kRoutesFilePath = "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/final-project-spitzer4/data/routes.csv";
std::string kTripsFilePath = "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/final-project-spitzer4/data/trips.csv";

std::map<std::string, Route> route_id_to_route_map;

/**
 * Reads in and collects data from the trips.csv file.
 * @return a map of the route ID and corresponding trip ID.
 */
std::map<std::string, std::string> Data::CreateTripMap() {
    std::map<std::string, std::string> route_id_to_trip_id_map;

    std::ifstream data(kTripsFilePath);
    std::string first_line;
    std::string line;

    std::string delim = ",";
    size_t k = 0;
    std::string token;

    std::vector<std::string> line_values;

    std::string route_id;
    std::string trip_id;

    size_t route_id_index2 = 0;

    getline(data, first_line, '\n');

    while (data.good()) {
        getline(data, line, '\n');

        while ((k = line.find(delim)) != std::string::npos) {
            token = line.substr(0, k);
            line_values.push_back(token);
            line.erase(0, k + delim.length());
        }

        route_id = line_values.at(route_id_index2);
        trip_id = line;
        line_values.clear();

        route_id_to_trip_id_map.insert(std::make_pair(route_id, trip_id));
    }
    return route_id_to_trip_id_map;
}

/**
 * Reads in and collects data from the routes.csv file.
 * @return a map of a route ID to the corresponding route attributes.
 */
std::map<std::string, Route> Data::CreateRouteMap() {
    std::map<std::string, std::string> trips_map = Data::CreateTripMap();

    std::ifstream data(kRoutesFilePath);
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

    return route_id_to_route_map;
}