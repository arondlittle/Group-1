/*
 * ============================================================
 * CESC 450 – Real-Time Embedded Systems Course Project
 * src/main.cpp
 *
 * PURPOSE:
 * This file serves as the central coordination point for the project.
 * It is responsible for:
 *
 *  - System initialization (host-based for this course)
 *  - RTOS startup
 *  - Creating and configuring tasks
 *
 * This file is extended incrementally across Modules 3–7.
 *
 * IMPORTANT GUIDELINES FOR STUDENTS:
 *  - Do NOT place all application logic in this file
 *  - Task implementations belong in src/tasks/
 *  - Timing logic belongs in src/timing/
 *  - IPC logic belongs in src/ipc/
 *  - Shared data and synchronization belong in src/shared/
 *
 * main.cpp should remain readable and focused on system setup.
 * ============================================================
 */
//MODULE 3 TASk B addition 
#include <iostream>
#include "rtos_api.h"
#include "TaskA.h"
#include "TaskB.h"

int main()
{
    std::cout << "=====================================================\n";
    std::cout << "CESC 450 Module 3 - Concurrent Avionics RTOS Active\n";
    std::cout << "=====================================================\n\n";

    // Create Task A (Telemetry Simulation)
    if (!xTaskCreate(vTaskA, "Task_A", 256, nullptr, 1, nullptr))
    {
        std::cerr << "CRITICAL: Failed to create Task A\n";
        return 1;
    }

    // Create Task B (System Monitor)
    if (!xTaskCreate(vTaskB, "Task_B", 256, nullptr, 1, nullptr))
    {
        std::cerr << "CRITICAL: Failed to create Task B\n";
        return 1;
    }

    std::cout << "Starting background RTOS scheduler...\n\n";
    vTaskStartScheduler();

    // The host shim runs until execution stops or tasks finish
    std::cout << "\nScheduler exited gracefully.\n";
    return 0;
}


// -----------------------------------------------------------------------------
// Module 2: Baseline demo tasks (host RTOS shim)
// These are intentionally simple and observable. In Module 3+, tasks should move
// into src/tasks/ and main.cpp should only create/configure them.
// -----------------------------------------------------------------------------


//*static void HeartbeatTask(void * /*params*/)
/**{
  for (int i = 0; i < 10; ++i)
  {
    std::cout << "[Heartbeat] tick=" << xTaskGetTickCount()
              << " (i=" << i << ")\n";
    vTaskDelay(200);
  }
}

static void WorkerTask(void *params)
{
  const char *name = static_cast<const char *>(params);

  for (int i = 0; i < 5; ++i)
  {
    std::cout << "[Worker:" << (name ? name : "unknown") << "] doing work step "
              << i << ", tick=" << xTaskGetTickCount() << "\n";
    vTaskDelay(350);
    taskYIELD();
  }
}

// -----------------------------------------------------------------------------
// Entry Point
// -----------------------------------------------------------------------------

int main()
{
  
   * TODO (Module 2):
   * - Verify RTOS environment setup (build + run)
   * - Confirm baseline task execution and observable output
   *
   * TODO (Module 3):
   * - Create RTOS tasks defined in src/tasks/
   * - Assign initial priorities and demonstrate coordination

//MODULE 3 TASk B addition 
#include <cstdint>
#include <iostream>

#include "rtos_api.h"
#include "TaskA.h"
#include "TaskB.h"

int main() {
    std::cout << "CESC 450 Module 3 - RTOS Task Coordination\n";
    std::cout << "Starting scheduler...\n";

    // Create Task A (Priority 1)
    if (!xTaskCreate(vTaskA, "TaskA", 1024, NULL, 1, NULL)) {
        std::cerr << "Failed to create Task A\n";
        return 1;
    }

    // Create Task B (Priority 1)
    if (!xTaskCreate(vTaskB, "TaskB", 1024, NULL, 1, NULL)) {
        std::cerr << "Failed to create Task B\n";
        return 1;
    }

    // Start the RTOS scheduler
    vTaskStartScheduler();

    // The scheduler never returns; if we get here, something went wrong.
    return 0;
}

   *
   * TODO (Module 4+):
   * - Initialize timing services
   * - Start watchdog or monitoring mechanisms
   * - Add synchronization, IPC, and event-driven behavior
   */

  //std::cout << "CESC 450 Module 2 - Host RTOS Baseline (shim)\n";
  //std::cout << "Goal: verify build/run, RTOS-style API wiring, and GitHub baseline.\n\n";

  // Create baseline tasks (Module 2 demo)
  //TaskHandle_t hb = nullptr;
  //TaskHandle_t w1 = nullptr;

  //if (!xTaskCreate(HeartbeatTask, "Heartbeat", 256, nullptr, 2, &hb))
  //{
    //std::cerr << "Failed to create HeartbeatTask\n";
    //return 1;
  //}

  //const char *workerName = "A";
  //if (!xTaskCreate(WorkerTask, "WorkerA", 256, (void *)workerName, 1, &w1))
  //{
    //std::cerr << "Failed to create WorkerTask\n";
    //return 1;
  //}

  //std::cout << "Starting scheduler...\n";
  //vTaskStartScheduler();

  // In a real RTOS this often never returns. In this host shim it returns when
  // the demo tasks complete.
//  std::cout << "\nScheduler exited (all tasks completed). Baseline OK.\n";

  //int num1;
 // int num2;


/*  std::cout << "\n\n=====================================================\n";
  std::cout << "\t\tTask A : \n";
  std::cout << "Enter number 1 : ";
  //std::cin >> num1; scheduler update 
  std::cout << "Enter number 2: ";
  //std::cin >> num2; schduler update 
  std::cout << "Result: " << RunAddition(num1, num2)<<std::endl;
  vTaskDelay(2000);
  PrintTaskOccured();
  return 0;
}
*/
