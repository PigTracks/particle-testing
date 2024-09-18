#include "CellSignalService.h"
#include "../models/Metadata.h"

CellSignal CellSignalService::getCellSignal() {
    // TODO: Implement this method
    float strength = -100.0;
    float quality = 0.0;
    return CellSignal({strength, quality});
}
