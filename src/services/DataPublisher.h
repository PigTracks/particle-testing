#pragma once

#include <string>
#include "Particle.h"
#include "DataPoint.h"

class DataPublisher {
public:
  DataPublisher(const String& manufacturer, const String& deviceId);
  void publish(std::vector<DataPoint> accumulatedData);
private:
  String manufacturer;
  String deviceId;
};
