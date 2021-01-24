#include "/Users/kaleighspitzer/CLionProjects/Cinder/my-projects/final-project-spitzer4/include/visualizer/database.h"

using visualizer::database;


void prepareSettings(database::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(database, ci::app::RendererGl, prepareSettings);
