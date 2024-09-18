#include "Particle.h"
#include "MetadataController.h"
#include "../services/PositionService.h"
#include "../services/CellSignalService.h"
#include "../services/BatteryService.h"
#include "../services/GeophoneService.h"
#include "../services/TemperatureService.h"
#include "../networking/DataPublisher.h"
#include "../models/Metadata.h"

MetadataController::MetadataController(const String& manufacturer, const String& deviceId)
    : manufacturer(manufacturer), deviceId(deviceId) {}

void MetadataController::loop() {
    unsigned long currentTime = millis();

    if (currentTime - lastPublishTime > publishInterval) {
        publishMetadata(currentTime);
        lastPublishTime = currentTime;
    }
}

void MetadataController::publishMetadata(unsigned long time) {
    PositionService positionService;
    Position position = positionService.getPosition();

    CellSignalService cellSignalService;
    CellSignal cellSignal = cellSignalService.getCellSignal();

    BatteryService batteryService;
    Battery battery = batteryService.getBattery();

    GeophoneService geophoneService;
    Geophone geophone = geophoneService.getGeophone();

    TemperatureService temperatureService;
    float temperature = temperatureService.getTemperature();

    Metadata metadata(time, position, cellSignal, battery, geophone, temperature);

    DataPublisher dataPublisher = DataPublisher(manufacturer, deviceId);
    dataPublisher.publishMetadata(metadata);
}
