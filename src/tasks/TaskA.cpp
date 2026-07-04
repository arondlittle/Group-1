#include "TaskA.h"
#include <iostream>
#include "rtos_api.h"      // the RTOS header
#include "timing_shared.h" // shared state for coordination
#include "timing_utils.h"  // utility functions

// shared state for coordination
volatile int g_system_cycle_count = 0;
// track last heartbeat tick (define here to ensure symbol is available)
extern volatile uint32_t g_lastHeartbeatTick;
// Helper functions
int RunAddition(int num1, int num2)
{
    return num1 + num2;
}

void PrintTaskOccured()
{
    std::cout << "Task A has occurred" << std::endl;
}

void vTaskA(void *pvParameters)
{
    int taskA_local_cycle = 0;
    for (;;)
    {
        taskA_local_cycle++;
        g_system_cycle_count++;

        g_lastHeartbeatTick = GetCurrentTick(); // Update the last heartbeat tick

        std::cout << "[aTask A] Cycle: "
                  << taskA_local_cycle
                  << "Tick=" << g_lastHeartbeatTick
                  << std::endl;

        PrintTaskOccured();
        if (taskA_local_cycle == 5)
        {
            std::cout << "[Task A] Simulating long delay...\n";
            vTaskDelay(4000);
        }

        // Yield for 1000ms
        vTaskDelay(1000);
    }
}
