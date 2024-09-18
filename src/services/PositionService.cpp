#include "PositionService.h"
#include "../models/Metadata.h"

Position PositionService::getPosition() {
    // TODO: Implement this method
    float latitude = 37.7749;
    float longitude = -122.4194;
    float altitude = 0.0;
    return Position({latitude, longitude, altitude});
}
