#include "solarsystem_simulation.h"

using solarsystem::SolarSystemApp;

void prepareSettings(SolarSystemApp::Settings* settings) {
    settings->setResizable(false);
}

CINDER_APP(SolarSystemApp, ci::app::RendererGl, prepareSettings);