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
};

struct Geophone {
    bool enabled;
};

struct Metadata {
    int64_t timestamp;
    Position position;
    CellSignal cellSignal;
    Battery battery;
    Geophone geophone;
    float temperature;

    Metadata(int64_t timestamp, Position position, CellSignal cellSignal, Battery battery, Geophone geophone, float temperature)
        : timestamp(timestamp), position(position), cellSignal(cellSignal), battery(battery), geophone(geophone), temperature(temperature) {}
};
