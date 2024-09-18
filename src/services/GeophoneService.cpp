#include "GeophoneService.h"
#include "../models/Metadata.h"

Geophone GeophoneService::getGeophone() {
  // TODO: Implement this method
  bool enabled = true;
  return Geophone({enabled});
}
