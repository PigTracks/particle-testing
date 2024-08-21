#include "GeophoneController.h"
#include "Particle.h"
#include "GeophoneSensor.h"
#include "DataPoint.h"

GeophoneController::GeophoneController(const String& manufacturer, const String& deviceId)
    : manufacturer(manufacturer), deviceId(deviceId), geophoneStreamEnabled(false), lastDataGenerationTime(0), lastPublishTime(0) {}

void GeophoneController::setup() {
    Particle.function("geophoneControl", &GeophoneController::controlGeophoneStream, this);
}

void GeophoneController::loop() {
    unsigned long currentTime = millis();

    if (geophoneStreamEnabled) {
        if (currentTime - lastDataGenerationTime > dataGenerationInterval) {
            getSensorData();
            lastDataGenerationTime = currentTime;
        }

        if (currentTime - lastPublishTime > publishInterval) {
            publishData();
            lastPublishTime = currentTime;
        }
    }
}

void GeophoneController::getSensorData() {
    GeophoneSensor sensor;
    DataPoint dataPoint = sensor.getDataPoint();
    accumulatedData.push_back(dataPoint);
}

void GeophoneController::publishData() {
    // TODO: Make this more efficient by batching data points into a single Particle.publish call
    for (const auto& dataPoint : accumulatedData) {
        String lineProtocolString = String::format("geophoneData,manufacturer=%s,deviceId=%s value=%f %lld\n", manufacturer.c_str(), deviceId.c_str(), dataPoint.data, dataPoint.timestamp);
        Particle.publish("influx_data", lineProtocolString, PRIVATE);
    }
    accumulatedData.clear();
}

int GeophoneController::controlGeophoneStream(String command) {
    if (command == "on") {
        geophoneStreamEnabled = true;
        return 1;
    } else if (command == "off") {
        geophoneStreamEnabled = false;
        return 1;
    }
    return -1;
}
