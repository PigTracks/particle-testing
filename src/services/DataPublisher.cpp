#include "DataPublisher.h"
#include "MQTT.h"
#include <cstdint>

void callback(char* topic, byte* payload, unsigned int length);

MQTT client("r18135e0.ala.dedicated.aws.emqxcloud.com", 1883, callback);

void callback(char* topic, byte* payload, unsigned int length) {}

DataPublisher::DataPublisher(const String& manufacturer, const String& deviceId)
    : manufacturer(manufacturer), deviceId(deviceId) {
    client.connect(deviceId.c_str(), "pigtracks-sensor", "abc123def456");
}

void DataPublisher::publish(std::vector<DataPoint> accumulatedData) {
    if (client.isConnected()) {
        std::string dataStr;
        for (auto it = accumulatedData.begin(); it != accumulatedData.end(); ++it) {
            dataStr += std::to_string(it->timestamp) + ":" + std::to_string(it->data);
            if (it + 1 != accumulatedData.end()) {
                dataStr += ",";
            }
        }
        String topic = manufacturer + "/" + deviceId;
        client.publish(topic.c_str(), dataStr.c_str());
    }
}
