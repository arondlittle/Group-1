#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	int RunAddition(int num1, int num2);
	void PrintTaskOccured();

    // ADD THIS LINE TO DECLARE THE TASK ENTRY POINT
    void vTaskA(void* pvParameters);
#ifdef __cplusplus
}
#endif
