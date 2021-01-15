//
// Created by Kaleigh Spitzer on 11/19/20.
//
#ifndef FINAL_PROJECT2_DATABASE_H
#define FINAL_PROJECT2_DATABASE_H

#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/app/App.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/app/RendererGl.h"
#include "/Users/kaleighspitzer/CLionProjects/~Cinder/include/cinder/gl/gl.h"

class database : public ci::app::App {
public:
    void setup();
    void update();
    void draw();
};

#endif //FINAL_PROJECT2_DATABASE_H
