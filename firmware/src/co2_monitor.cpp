#include "co2_monitor.h"
#include "Adafruit_SCD30.h"
#include "Wire.h"

#define MEASUREMENT_INTERVAL_SECS 6

void sendSerialData(const float& co2_ppm, const float& temp_c) {
    char buffer[100];
    sprintf(buffer, "{\"co2_ppm\": %f, \"temp_c\": %f}", co2_ppm, temp_c);
    Serial.println(buffer);
}

void CO2Monitor::Setup() {
    delay(1000);
    Serial.begin(115200);

    Wire1.setPins(SDA1, SCL1); // Necessary for QT PY ESP32, which has multiple I2C busses.
    if (!scd30.begin(0x61, &Wire1, 0)) {
        Serial.println("Failed to find SCD30 chip");
        while(1){ delay(10);}
    }

    if (!scd30.setMeasurementInterval(MEASUREMENT_INTERVAL_SECS)){
        Serial.println("Failed to set measurement interval");
        while(1){ delay(10);}
    }

    display.Init();
}

void CO2Monitor::HandleLoop() {
    if (scd30.dataReady()) {
        if (!scd30.read()) {
            Serial.println("Error reading data");
            return;
        }
        display.Update(scd30.CO2, scd30.temperature);
        sendSerialData(scd30.CO2, scd30.temperature);
    }
}
