#pragma once

#include <cstdint>
#include "../models/DataPoint.h"

class GeophoneSensor {
public:
    DataPoint getDataPoint();
};
