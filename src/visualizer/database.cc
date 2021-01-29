//
// Created by Kaleigh Spitzer on 11/19/20.
//

#include "../../include/visualizer/database.h"

std::map<std::string, Route> route_map;

void visualizer::database::setup() {
    cinder::app::AppBase::setWindowSize(600, 800);
    route_map = Data::CreateRouteMap();
    interfaceGl = ci::params::InterfaceGl::create(getWindow(), "Bus routes: ", ci::app::toPixels(glm::vec2(200, 400)));
    for (std::map<std::string, Route>::iterator it = route_map.begin(); it != route_map.end(); ++it) {
        interfaceGl->addButton(it->first, std::bind(&visualizer::database::button, this));
    }

}

void visualizer::database::draw() {
    ci::gl::clear();
//    ci::Rectf rectf(100, 100, 500, 500);
    ci::Color(0, 0, 1);
//    ci::gl::drawStrokedRect(rectf);
    interfaceGl->draw();
}

void visualizer::database::update() {

}

void visualizer::database::button() {
    interfaceGl->setOptions( "text", "label=`Clicked!`");
}
