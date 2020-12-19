//
// Created by Kaleigh Spitzer on 12/6/20.
//

#ifndef FINAL_PROJECT_ROUTE_H
#define FINAL_PROJECT_ROUTE_H

#include<string>

class Route {
public:
    std::string id;
    std::string shortName;
    std::string longName;
    std::string color;
    std::string trip_id;

    Route(std::string id, std::string shortName, std::string longName, std::string color, std::string trip_id) {
        this->id = id;
        this->shortName = shortName;
        this->longName = longName;
        this->color = color;
        this->trip_id = trip_id;
    };

    std::string getId();

};
#endif //FINAL_PROJECT_ROUTE_H
