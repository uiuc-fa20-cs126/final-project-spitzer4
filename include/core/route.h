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

    Route(std::string id, std::string shortName, std::string longName, std::string color) {
        this->id = id;
        this->shortName = shortName;
        this->longName = longName;
        this->color = color;
    };
    std::string getId();

};
#endif //FINAL_PROJECT_ROUTE_H
