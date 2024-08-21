#include "Particle.h"
#include "GeophoneController.h"

PRODUCT_VERSION(1);

SerialLogHandler logHandler(LOG_LEVEL_INFO);

String manufacturer = "PigTracks";
String deviceId = System.deviceID();

GeophoneController geophoneController(manufacturer, deviceId);

void setup() {
  geophoneController.setup();
}

void loop() {
  geophoneController.loop();
}
