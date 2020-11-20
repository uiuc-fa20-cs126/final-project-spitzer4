//
// Created by Kaleigh Spitzer on 11/19/20.
//

#include "../../include/visualizer/database.h"

void database::setup() {
    setWindowSize(600, 800);
}

void database::draw() {
    ci::gl::clear();
    ci::Color(0, 0, 1);
    ci::Rectf rectf(100, 100, 500, 500);
    ci::gl::drawStrokedRect(rectf);
}

void database::update() {

}

CINDER_APP(database, ci::app::RendererGl)