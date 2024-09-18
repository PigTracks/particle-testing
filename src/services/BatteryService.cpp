#include "BatteryService.h"
#include "../models/Metadata.h"

Battery BatteryService::getBattery() {
    // TODO: Implement this method
    float voltage = 3.7;
    return Battery({voltage});
}
