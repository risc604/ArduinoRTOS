#pragma once

#include "Arduino_RTOS.h"
#include "semphr.h"
#include "queue.h"

// This one is mine. lol
#include "FreeRTOS_Utils.h"

#if ARDUINO >= 100
#include <Arduino.h>
#endif