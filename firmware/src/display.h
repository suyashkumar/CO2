//
// Created by Suyash Kumar on 12/9/23.
//

#ifndef CO2_DISPLAY_H
#define CO2_DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

class Display {
public:
    void Init();
    void Update(const float& co2_ppm, const float& temp_c);
private:
    Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire1);
};


#endif //CO2_DISPLAY_H
