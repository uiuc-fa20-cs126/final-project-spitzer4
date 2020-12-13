//
// Created by Kaleigh Spitzer on 12/12/20.
//

#ifndef FINAL_PROJECT_TRIP_H
#define FINAL_PROJECT_TRIP_H

#include <string>

class Trip {
public:
    std::string route_id;
    std::string trip_id;
    Trip(std::string newRouteId, std::string newTripId) {
        this->route_id = newRouteId;
        this->trip_id = newTripId;
    }

private:

};

#endif //FINAL_PROJECT_TRIP_H
