#include "GeophoneSensor.h"
#include "Particle.h"
#include "DataPoint.h"

DataPoint GeophoneSensor::getDataPoint() {
    unsigned long time = Time.now();
    float value = 50;

    return DataPoint{value, time};
}
