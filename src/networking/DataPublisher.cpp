#include <cstdint>
#include "Particle.h"
#include "DataPublisher.h"
#include "./MqttPublisher.h"

DataPublisher::DataPublisher(const String& manufacturer, const String& deviceId)
    : manufacturer(manufacturer), deviceId(deviceId) {}

void DataPublisher::publishData(std::vector<DataPoint> accumulatedData) {
    String topic = manufacturer + "/" + deviceId + "/data";
    String messageBody = createDataJson(accumulatedData);
    MqttPublisher::publish(topic, messageBody);
}

void DataPublisher::publishMetadata(Metadata metadata) {
    String topic = manufacturer + "/" + deviceId + "/metadata";
    String messageBody = createMetadataJson(metadata);
    MqttPublisher::publish(topic, messageBody);
}

String DataPublisher::createDataJson(std::vector<DataPoint> accumulatedData) {
    char buffer[1024] = {0}; // Initialize buffer with zeros to ensure null-termination
    JSONBufferWriter writer(buffer, sizeof(buffer));
    writer.beginArray();

    for (const auto& dataPoint : accumulatedData) {
        writer.beginObject();
        writer.name("timestamp").value(dataPoint.timestamp);
        writer.name("data").value(dataPoint.data);
        writer.endObject();
    }

    writer.endArray();
    return writer.buffer();
}

String DataPublisher::createMetadataJson(Metadata metadata) {
    char buffer[1024] = {0}; // Initialize buffer with zeros to ensure null-termination
    JSONBufferWriter writer(buffer, sizeof(buffer));
    writer.beginObject();
        writer.name("timestamp").value(metadata.timestamp);
        writer.name("position").beginObject();
            writer.name("latitude").value(metadata.position.latitude);
            writer.name("longitude").value(metadata.position.longitude);
            writer.name("altitude").value(metadata.position.altitude);
        writer.endObject();
            writer.name("cellSignal").beginObject();
            writer.name("strength").value(metadata.cellSignal.strength);
            writer.name("quality").value(metadata.cellSignal.quality);
        writer.endObject();
            writer.name("battery").beginObject();
            writer.name("voltage").value(metadata.battery.voltage);
            writer.name("percentage").value(metadata.battery.percentage);
        writer.endObject();
    writer.endObject();
    return String(buffer);
}
