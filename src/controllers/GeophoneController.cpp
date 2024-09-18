#include "Particle.h"
#include "GeophoneController.h"
#include "../sensors/GeophoneSensor.h"
#include "../networking/DataPublisher.h"
#include "../models/DataPoint.h"

GeophoneController::GeophoneController(const String& manufacturer, const String& deviceId)
    : manufacturer(manufacturer), deviceId(deviceId), geophoneStreamEnabled(true), lastDataGenerationTime(0), lastPublishTime(0) {}

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
    DataPublisher dataPublisher = DataPublisher(manufacturer, deviceId);
    dataPublisher.publishData(accumulatedData);
    accumulatedData.clear();
}
