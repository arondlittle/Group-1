#include "TaskB.h"
#include <iostream>
#include "rtos_api.h"
#include "timing_shared.h" // shared state for coordination
#include "timing_utils.h"  // utility functions

// Gain access to the shared state managed by Task A
extern volatile int g_system_cycle_count;

void vTaskB(void *pvParameters)
{
    (void)pvParameters; // Prevent unused parameter warning

    for (;;)
    {
        uint32_t now = GetCurrentTick();

        if ((now - g_lastHeartbeatTick) > 2000)
        {
            std::cout << "[WATCHDOG] Warning: Task A heartbeat overdue!"
                      << "Now=" << now
                      << " Last=" << g_lastHeartbeatTick
                      << " Delta=" << (now - g_lastHeartbeatTick)
                      << std::endl;
        }
        else
        {
            std::cout << "[WATCHDOG] Task A heartbeat is healthy. Last tick: "
                      << g_lastHeartbeatTick
                      << std::endl;
        }
        if (g_system_cycle_count >= 3)
        {
            std::cout << "[Task B] ALERT: System cycle threshold reached! Resetting counter.\n";
            g_system_cycle_count = 0; // Reset the counter
        }
        else
        {
            std::cout << "[Task B] Monitoring... Shared variable is currently: "
                      << g_system_cycle_count << "\n";
        }
        vTaskDelay(500); // Yield for 500ms
    }
}