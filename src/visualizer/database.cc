//
// Created by Kaleigh Spitzer on 11/19/20.
//

#include "../../include/visualizer/database.h"

std::map<std::string, Route> route_map;
std::string route_name = "";
std::string long_name = "";
std::string short_name = "";
std::string color = "";
std::string trip_id = "";

void visualizer::database::setup() {
    cinder::app::AppBase::setWindowSize(1200, 800);
    route_map = Data::CreateRouteMap();
    textBox = ci::TextBox();
    textBox.setSize({200, 200});
    textBox.setBackgroundColor(ci::ColorA("white"));
    textBox.setText("Route info:");

    long_name_text = ci::TextBox();
    long_name_text.setSize({200, 200});
    long_name_text.setBackgroundColor(ci::ColorA("white"));

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
    interfaceMaps = ci::params::InterfaceGl::create(getWindow(), "Maps: ", ci::app::toPixels(glm::vec2(200, 100)));
    mapImageLayer = ci::params::InterfaceGl::create(getWindow(), "Map", ci::app::toPixels(glm::vec2(800, 600)));
    interfaceMaps->setPosition(glm::vec2(950, 50));
    std::vector<std::string> map_names = {"Weekday Daytime", "Weekday Evening", "Saturday Daytime", "Saturday Evening", "Sunday Daytime", "Sunday Evening"};
    std::vector<std::string> map_files = {"/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/final-project-spitzer4/data/weekday-daytime.png",
                                          "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/final-project-spitzer4/data/weekday-evening.png",
                                          "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/final-project-spitzer4/data/saturday-daytime.png",
                                          "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/final-project-spitzer4/data/saturday-evening.png",
                                          "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/final-project-spitzer4/data/sunday-daytime.png",
                                          "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/final-project-spitzer4/data/sunday-evening.png"};
//    std::map<std::string, std::string> map_name_to_file;
    int count = 0;
    for (std::string name : map_names) {
        map_name_to_file.insert(std::pair<std::string, std::string>(name, map_files.at(count)));
        count++;
        interfaceMaps->addButton(name, [&, name]() {
            map_button(name);
        });
    }
    for (std::map<std::string, Route>::iterator it = route_map.begin(); it != route_map.end(); it++) {
        route_name = it->first;
        long_name = it->second.longName;
        short_name = it->second.shortName;
        color = it->second.color;
        trip_id = it->second.trip_id;
        interfaceGl->addButton(route_name, [&, it]() {
            button(it);
        });
    }
}

void visualizer::database::draw() {
    ci::gl::clear();
    interfaceGl->draw();
    ci::gl::drawString(textBox.getText(), {400, 100}, ci::ColorA(1, 1, 1), ci::Font("Helvetica", 20));
    ci::gl::drawString(long_name_text.getText(), {400, 200}, ci::ColorA(1, 1, 1), ci::Font("Helvetica", 20));
    ci::gl::drawString(short_name_text.getText(), {400, 300}, ci::ColorA(1, 1, 1), ci::Font("Helvetica", 20));
    ci::gl::drawString(color_text.getText(), {400, 400}, ci::ColorA(1, 1, 1), ci::Font("Helvetica", 20));
    ci::gl::drawString(trip_id_text.getText(), {400, 500}, ci::ColorA(1, 1, 1), ci::Font("Helvetica", 20));
    ci::gl::draw(map);
}

void visualizer::database::update() {

}

void visualizer::database::button(std::map<std::string, Route>::iterator it) {
    ci::gl::clear();
    Route route = it->second;
    long_name_text.setText("Long name: " + route.longName);
    ci::gl::drawString(long_name_text.getText(), {400, 100}, ci::ColorA(1, 1, 1), ci::Font("Helvetica", 20));
    short_name_text.setText("Short name: " + route.shortName);
    ci::gl::drawString(short_name_text.getText(), {400, 200}, ci::ColorA(1, 1, 1), ci::Font("Helvetica", 20));
    color_text.setText("Color: " + route.color);
    ci::gl::drawString(color_text.getText(), {400, 300}, ci::ColorA(1, 1, 1), ci::Font("Helvetica", 20));
    trip_id_text.setText("Trip ID: " + route.trip_id);
    ci::gl::drawString(trip_id_text.getText(), {400, 400}, ci::ColorA(1, 1, 1), ci::Font("Helvetica", 20));
    draw();
}

void visualizer::database::map_button(std::string map_name) {
    ci::gl::clear();
    std::string image_path = map_name_to_file.at(map_name);
    ci::Surface surface = ci::loadImage(image_path);
    mapImageLayer->addParam();
    //    ci::gl::Texture2dRef map = ci::gl::Texture2d::create(surface);
    map = ci::gl::Texture2d::create(surface);
    //    ci::gl::draw(map);
    draw();
}

void visualizer::database::mouseDown(ci::app::MouseEvent event) {

}


