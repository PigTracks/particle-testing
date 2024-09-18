#pragma once

#include "Particle.h"
#include "../models/DataPoint.h"

class GeophoneController {
public:
    GeophoneController(const String& manufacturer, const String& deviceId);
    void loop();
private:
    String manufacturer;
    String deviceId;
    bool geophoneStreamEnabled;
    unsigned long lastDataGenerationTime;
    unsigned long lastPublishTime;
    const unsigned long dataGenerationInterval = 500;
    const unsigned long publishInterval = 5000;
    std::vector<DataPoint> accumulatedData;

    void getSensorData();
    void publishData();
    int controlGeophoneStream(String command);
};
