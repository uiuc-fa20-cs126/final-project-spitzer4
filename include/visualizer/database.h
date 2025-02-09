//
// Created by Kaleigh Spitzer on 11/19/20.
//
#ifndef FINAL_PROJECT2_DATABASE_H
#define FINAL_PROJECT2_DATABASE_H

#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/app/App.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/app/RendererGl.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/gl/gl.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/Text.h"
#include "/Users/kaleighspitzer/CLionProjects/Cinder/include/cinder/params/Params.h"
#include "../../include/core/load_data.h"

namespace visualizer {
    class database : public ci::app::App {
    public:
        void setup() override;

        void update() override;

        void draw() override;

        void button(std::map<std::string, Route>::iterator it);

        void map_button(std::string map_name);

    private:
        ci::TextBox textBox;
        ci::TextBox long_name_text;
        ci::TextBox short_name_text;
        ci::TextBox color_text;
        ci::TextBox trip_id_text;
        ci::params::InterfaceGlRef interfaceGl;
        ci::params::InterfaceGlRef interfaceMaps;
        ci::params::InterfaceGlRef mapImageLayer;

        ci::gl::Texture2dRef map;
        std::map<std::string, std::string> map_name_to_file;
    };
} // namespace visualizer

#endif //FINAL_PROJECT2_DATABASE_H
