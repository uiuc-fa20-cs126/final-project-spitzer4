//
// Created by Kaleigh Spitzer on 12/6/20.
//

#ifndef FINAL_PROJECT_ROUTE_H
#define FINAL_PROJECT_ROUTE_H

#include<string>

class Route {
public:
    Route();
    std::string id;
    std::string shortName;
    std::string longName;
    std::string color;

    void setId(std::string id) {
        this->id = id;
    }

    std::string getId() {
        return id;
    }

    void setShortName(std::string shortName) {
        this->shortName = shortName;
    }

    std::string getShortName() {
        return shortName;
    }

    void setLongName(std::string longName) {
        this->longName = longName;
    }

    std::string getLongName() {
        return longName;
    }

    void setColor(std::string color) {
        this->color = color;
    }

    std::string getColor() {
        return color;
    }

};
#endif //FINAL_PROJECT_ROUTE_H
