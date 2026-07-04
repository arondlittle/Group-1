#include "TaskA.h"
#include <iostream>
#include <mutex>
#include "rtos_api.h"
#include "timing_shared.h"
#include "timing_utils.h"

void PrintTaskOccured() {
    std::cout << "Task A has occurred" << std::endl;
}

void vTaskA(void* pvParameters) {
    (void)pvParameters;
    int taskA_local_cycle = 0;

    for (;;) {
        {
            // Mutex ensures TaskA and TaskB don't talk to the terminal at the same time
            std::lock_guard<std::mutex> lock(g_sharedResourceMutex);

            taskA_local_cycle++;
            g_system_cycle_count++;
            g_lastHeartbeatTick = GetCurrentTick();

            std::cout << "[Task A] Cycle: " << taskA_local_cycle
                << " Tick=" << g_lastHeartbeatTick << std::endl;
            PrintTaskOccured();
        }

        if (taskA_local_cycle == 5) {
            vTaskDelay(4000);
        }
        vTaskDelay(1000);
    }
}
