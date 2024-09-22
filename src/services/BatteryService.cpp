#include "Particle.h"
#include "BatteryService.h"
#include "../models/Metadata.h"

Battery BatteryService::getBattery() {
    FuelGauge fuel;
    float voltage = fuel.getVCell();
    float percentage = fuel.getNormalizedSoC();
    return Battery({voltage, percentage});
}
