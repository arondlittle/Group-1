#include "timing_utils.h"
#include "rtos_api.h"

uint32_t GetCurrentTick()
{
    // Retrieve the current tick count from the RTOS
    return xTaskGetTickCount();
}