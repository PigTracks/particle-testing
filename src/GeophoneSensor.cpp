#include "GeophoneSensor.h"
#include "Particle.h"
#include "DataPoint.h"

DataPoint GeophoneSensor::getDataPoint() {
    unsigned long time = Time.now();

    auto rawVoltage = analogRead(A6);
    float value = (float)rawVoltage;

    return DataPoint{value, time};
}
