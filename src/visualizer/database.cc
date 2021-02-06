//
// Created by Kaleigh Spitzer on 11/19/20.
//

#include "../../include/visualizer/database.h"

std::map<std::string, Route> route_map;
std::string route_name;
std::string long_name;
std::string short_name;
std::string color;
std::string trip_id;

void visualizer::database::setup() {
    cinder::app::AppBase::setWindowSize(1000, 800);
    route_map = Data::CreateRouteMap();
    textBox = ci::TextBox();
    textBox.setSize({200, 200});
    textBox.setBackgroundColor(ci::ColorA("white"));
    textBox.setText("Route info:");

    long_name_text = ci::TextBox();
    long_name_text.setSize({200, 200});
    long_name_text.setBackgroundColor(ci::ColorA("white"));
//    textBox.setText("Route info:");

    short_name_text = ci::TextBox();
    short_name_text.setSize({200, 200});
    short_name_text.setBackgroundColor(ci::ColorA("white"));

    color_text = ci::TextBox();
    color_text.setSize({200, 200});
    color_text.setBackgroundColor(ci::ColorA("white"));

    trip_id_text = ci::TextBox();
    trip_id_text.setSize({200, 200});
    trip_id_text.setBackgroundColor(ci::ColorA("white"));

    interfaceGl = ci::params::InterfaceGl::create(getWindow(), "Bus routes: ", ci::app::toPixels(glm::vec2(200, 800)));
    for (std::map<std::string, Route>::iterator it = route_map.begin(); it != route_map.end(); ++it) {
        route_name = it->first;
        long_name = it->second.longName;
        short_name = it->second.shortName;
        color = it->second.color;
        trip_id = it->second.trip_id;
        interfaceGl->addButton(route_name, std::bind(&visualizer::database::button, this));
    }
}

void visualizer::database::draw() {
    ci::gl::clear();
    interfaceGl->draw();
    ci::gl::drawString(textBox.getText(), {400, 100}, ci::ColorA(0, 1, 0), ci::Font("Helvetica", 20));
    ci::gl::drawString(long_name_text.getText(), {400, 200}, ci::ColorA(0, 1, 0), ci::Font("Helvetica", 20));
    ci::gl::drawString(short_name_text.getText(), {400, 300}, ci::ColorA(0, 1, 0), ci::Font("Helvetica", 20));
    ci::gl::drawString(color_text.getText(), {400, 400}, ci::ColorA(0, 1, 0), ci::Font("Helvetica", 20));
    ci::gl::drawString(trip_id_text.getText(), {400, 500}, ci::ColorA(0, 1, 0), ci::Font("Helvetica", 20));

}

void visualizer::database::update() {
}

void visualizer::database::button() {
    ci::gl::clear();

    long_name_text.setText("Long name: " + long_name);
    ci::gl::drawString(long_name_text.getText(), {400, 100}, ci::ColorA(0, 1, 0), ci::Font("Helvetica", 20));

    short_name_text.setText("Short name: " + short_name);
    ci::gl::drawString(short_name_text.getText(), {400, 200}, ci::ColorA(0, 1, 0), ci::Font("Helvetica", 20));

    color_text.setText("Color: " + color);
    ci::gl::drawString(color_text.getText(), {400, 300}, ci::ColorA(0, 1, 0), ci::Font("Helvetica", 20));

    trip_id_text.setText("Trip ID: " + trip_id);
    ci::gl::drawString(trip_id_text.getText(), {400, 400}, ci::ColorA(0, 1, 0), ci::Font("Helvetica", 20));
}

void visualizer::database::mouseDown(ci::app::MouseEvent event) {

}


