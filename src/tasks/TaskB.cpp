#include "TaskB.h"
#include <iostream>
#include "rtos_api.h"

// Gain access to the shared state managed by Task A
extern volatile int g_system_cycle_count;

void vTaskB(void *pvParameters) {
    (void)pvParameters; // Prevent unused parameter warning
    
    for (;;) {
        // Coordination check
        if (g_system_cycle_count >= 3) {
            std::cout << "[Task B] ALERT: System cycle threshold reached! Resetting counter.\n";
            g_system_cycle_count = 0;
        } else {
            std::cout << "[Task B] Monitoring... Shared variable is currently: " 
                      << g_system_cycle_count << "\n";
        }
        
        // Execution Control: Run at a faster rate (500ms) to ensure interleaved capture
        vTaskDelay(500);
    }
}
