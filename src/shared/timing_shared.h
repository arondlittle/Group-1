#pragma once
#include <cstdint>
#include "rtos_api.h" //Semaphore file 

extern volatile uint32_t g_lastHeartbeatTick;
extern volatile int g_system_cycle_count;

//Declare Mutex Handle
extern SemaphoreHandle_t g_sharedResourceMutex;

// initialization
void InitSharedResources (); 
