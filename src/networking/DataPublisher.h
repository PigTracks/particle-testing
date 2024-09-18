#pragma once

#include "Particle.h"
#include "../models/DataPoint.h"
#include "../models/Metadata.h"

class DataPublisher {
public:
  DataPublisher(const String& manufacturer, const String& deviceId);
  void publishData(std::vector<DataPoint> accumulatedData);
  void publishMetadata(Metadata metadata);
private:
  String manufacturer;
  String deviceId;

  String createDataJson(std::vector<DataPoint> accumulatedData);
  String createMetadataJson(Metadata metadata);
};
