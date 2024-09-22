#include "Particle.h"
#include "MetadataController.h"
#include "../services/PositionService.h"
#include "../services/CellSignalService.h"
#include "../services/BatteryService.h"
#include "../networking/DataPublisher.h"
#include "../models/Metadata.h"

MetadataController::MetadataController(const String& manufacturer, const String& deviceId)
    : manufacturer(manufacturer), deviceId(deviceId), metadataStreamEnabled(false) {}

void MetadataController::loop() {
    unsigned long currentTime = millis();

    if (metadataStreamEnabled) {
        if (currentTime - lastPublishTime > publishInterval) {
            unsigned long time = Time.now();
            publishMetadata(time);
            lastPublishTime = currentTime;
        }
    }
}

void MetadataController::publishMetadata(unsigned long time) {
    PositionService positionService;
    Position position = positionService.getPosition();

    CellSignalService cellSignalService;
    CellSignal cellSignal = cellSignalService.getCellSignal();

    BatteryService batteryService;
    Battery battery = batteryService.getBattery();

    Metadata metadata(time, position, cellSignal, battery);

    DataPublisher dataPublisher = DataPublisher(manufacturer, deviceId);
    dataPublisher.publishMetadata(metadata);
}
