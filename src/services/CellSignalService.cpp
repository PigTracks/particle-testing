#include "Particle.h"
#include "CellSignalService.h"
#include "../models/Metadata.h"

CellSignal CellSignalService::getCellSignal() {
    CellularSignal signal = Cellular.RSSI();
    float strength = signal.getStrength();
    float quality = signal.getQuality();
    return CellSignal({strength, quality});
}
