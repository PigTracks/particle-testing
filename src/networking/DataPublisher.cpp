#include <cstdint>
#include "Particle.h"
#include "DataPublisher.h"

void DataPublisher::publishData(std::vector<DataPoint> accumulatedData) {
    String topic = manufacturer + "/" + deviceId + "/data";
    String messageBody = createDataJson(accumulatedData);
    Particle.publish(topic, messageBody);
}

void DataPublisher::publishMetadata(Metadata metadata) {
    String topic = manufacturer + "/" + deviceId + "/metadata";
    String messageBody = createMetadataJson(metadata);
    Particle.publish(topic, messageBody);
}

String DataPublisher::createDataJson(std::vector<DataPoint> accumulatedData) {
    return "{}";
}

String DataPublisher::createMetadataJson(Metadata metadata) {
    return "{}";
}
