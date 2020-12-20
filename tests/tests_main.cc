//
// Created by Kaleigh Spitzer on 12/19/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/my-projects/final-project2/include/core/load_data.h"

TEST_CASE("Number of routes is correct") {
    std::map<std::string, Route> route_id_to_route_map;
    Data::main();
    REQUIRE(route_id_to_route_map.size() == 102);
}