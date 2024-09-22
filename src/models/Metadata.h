#pragma once

#include <cstdint>

struct Position {
    float latitude;
    float longitude;
    float altitude;
};

struct CellSignal {
    float strength;
    float quality;
};

struct Battery {
    float voltage;
    float percentage;
};

struct Metadata {
    int64_t timestamp;
    Position position;
    CellSignal cellSignal;
    Battery battery;

    Metadata(int64_t timestamp, Position position, CellSignal cellSignal, Battery battery)
        : timestamp(timestamp), position(position), cellSignal(cellSignal), battery(battery) {}
};
