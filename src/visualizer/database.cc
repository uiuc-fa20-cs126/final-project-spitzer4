//
// Created by Kaleigh Spitzer on 11/19/20.
//

#include "../../include/visualizer/database.h"

void visualizer::database::setup() {
    setWindowSize(600, 800);
}

void visualizer::database::draw() {
    ci::gl::clear();
    ci::Color(0, 0, 1);
    ci::Rectf rectf(100, 100, 500, 500);
    ci::gl::drawStrokedRect(rectf);

    std::map<std::string, Route> route_map = Data::CreateRouteMap();
    for (std::map<std::string, Route>::iterator it = route_map.begin(); it != route_map.end(); ++it) {
        std::string line = it->first + + " " + it->second.longName + " " + it->second.shortName + " " + it->second.color + " " + it->second.trip_id;
        ci::gl::drawString(line, glm::vec2(700.0f,-150.0f), ci::Color(0, 0, 0), ci::Font("Arial", 90));
    }
}

void visualizer::database::update() {
}

CINDER_APP(visualizer::database, ci::app::RendererGl)