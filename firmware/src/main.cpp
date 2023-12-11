
#include "co2_monitor.h"

CO2Monitor monitor;

void setup() {
    monitor.Setup();
}

void loop() {
    monitor.HandleLoop();
}
