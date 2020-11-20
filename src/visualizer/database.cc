//
// Created by Kaleigh Spitzer on 11/19/20.
//

#include "../../include/visualizer/database.h"

void database::setup() {
    setWindowSize(600, 800);
}

void database::draw() {
    ci::Color(0, 0, 1);
    ci::Rectf rectf(0, 0, 20, 20);
    ci::gl::drawStrokedRect(rectf);
}

void database::update() {

}