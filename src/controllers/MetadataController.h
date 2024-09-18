#pragma once

#include "Particle.h"

class MetadataController {
public:
    MetadataController(const String& manufacturer, const String& deviceId);
    void loop();
private:
    String manufacturer;
    String deviceId;
    unsigned long lastPublishTime;
    const unsigned long publishInterval = 30000;

    void publishMetadata(unsigned long time);
};
