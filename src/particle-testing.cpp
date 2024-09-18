#include "Particle.h"
#include "controllers/GeophoneController.h"
#include "controllers/MetadataController.h"

PRODUCT_VERSION(1);

SerialLogHandler logHandler(LOG_LEVEL_INFO);

String manufacturer = "PigTracks";
String deviceId = System.deviceID();

GeophoneController geophoneController(manufacturer, deviceId);
MetadataController metadataController(manufacturer, deviceId);

void setup() {
}

void loop() {
  metadataController.loop();
  geophoneController.loop();
}
