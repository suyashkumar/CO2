#include "display.h"
#include "Wire.h"

void Display::Init() {
    display.begin(0x3C, true);
    display.setRotation(1);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0,0);
}

void Display::Update(const float &co2_ppm, const float &temp_c) {
    display.setCursor(0,0);
    display.clearDisplay();

    display.println("CO2: ");
    char co2_buf[7];
    sprintf(co2_buf, "%.1f", co2_ppm);
    display.print(co2_buf);
    display.println(" ppm");
    display.println();

    display.print("T: ");
    display.print(temp_c);
    display.println(" C");
    display.display();
}