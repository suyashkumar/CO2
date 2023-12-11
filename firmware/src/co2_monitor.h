#ifndef CO2_CO2_MONITOR_H
#define CO2_CO2_MONITOR_H

#include "display.h"
#include "Adafruit_SCD30.h"

class CO2Monitor {
public:
    void Setup();
    void HandleLoop();
private:
    Adafruit_SCD30 scd30;
    Display display;
};


#endif //CO2_CO2_MONITOR_H
