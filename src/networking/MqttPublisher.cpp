#include "Particle.h"
#include "MQTT.h"
#include "MqttPublisher.h"

void callback(char* topic, byte* payload, unsigned int length);

MQTT client("h7ce2c6e.ala.dedicated.aws.emqxcloud.com", 1883, callback);

void callback(char* topic, byte* payload, unsigned int length) {}

void MqttPublisher::publish(const String& topic, const String& messageBody) {
    String deviceId = System.deviceID();
    if (!client.isConnected()) {
        client.connect(deviceId.c_str(), "pigtracks-sensor", "abc123def456");
    }
    if (client.isConnected()) {
        client.loop();
        client.publish(topic.c_str(), messageBody.c_str());
    }
}
