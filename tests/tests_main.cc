//
// Created by Kaleigh Spitzer on 12/19/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../include/core/route.h"
#include "../include/core/load_data.h"

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

    SECTION("First route") {
        std::map<std::string, Route>::iterator it = route_id_to_route_map.find("GOLD ALT");
        REQUIRE(it->second.shortName == "10");
        REQUIRE(it->second.longName == "Gold 1 Alternate");
        REQUIRE(it->second.color == "c7994a");
        REQUIRE(it->second.trip_id == "[@2.0.84927215@][1455575717330]/90__10W_UHS_UMS_SCH");
    }

    SECTION("Randomly-indexed route") {
        std::map<std::string, Route>::iterator it = route_id_to_route_map.find("10W GOLD ALT");
        REQUIRE(it->second.shortName == "10");
        REQUIRE(it->second.longName == "Gold Alternate");
        REQUIRE(it->second.color == "c7994a");
        REQUIRE(it->second.trip_id == "[@36.0.28512748@][4][1175208157878]/0__10W_UHS_UMS_SCH");
    }

    SECTION("Last route") {
        std::map<std::string, Route>::iterator it = route_id_to_route_map.find("ORANGE ALT");
        REQUIRE(it->second.shortName == "6");
        REQUIRE(it->second.longName == "Orange Alternate");
        REQUIRE(it->second.color == "f99f2a");
        REQUIRE(it->second.trip_id == "[@4.0.3874463@][31][1598469809451]/0__6E_HUSch_PM_MF");
    }
}

TEST_CASE("Route map files are correctly matched to names")