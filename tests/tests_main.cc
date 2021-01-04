//
// Created by Kaleigh Spitzer on 12/19/20.
//

#define CATCH_CONFIG_MAIN
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/cmake-build-debug/_deps/catch2-src/single_include/catch2/catch.hpp"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/include/core/load_data.h"

TEST_CASE("Number of routes is correct") {
    std::map<std::string, Route> route_id_to_route_map = Data::CreateRouteMap();
    REQUIRE(route_id_to_route_map.size() == 102);
}

TEST_CASE("None of the file headings are read in") {
    std::map<std::string, Route> route_id_to_route_map = Data::CreateRouteMap();
    std::map<std::string, Route>::iterator it = route_id_to_route_map.find("route_id");
    REQUIRE(it == route_id_to_route_map.end());
}

TEST_CASE("Route ID attributes are correct") {
    std::map<std::string, Route> route_id_to_route_map = Data::CreateRouteMap();
    std::map<std::string, Route>::iterator it = route_id_to_route_map.find("10W GOLD ALT");
    REQUIRE(it->second.shortName == "10");
    REQUIRE(it->second.longName == "Gold Alternate");
    REQUIRE(it->second.color == "c7994a\r");
    REQUIRE(it->second.trip_id == "[@36.0.28512748@][4][1175208157878]/0__10W_UHS_UMS_SCH\r");
}