#pragma once

#include "Particle.h"

class MqttPublisher {
public:
  static void publish(const String& topic, const String& messageBody);
};
