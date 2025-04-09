#include "mcp9808.h"
#include <stdio.h>    

// Static variable to hold the injected I2C interface
static I2C_Interface* i2cInterface = NULL;

void MCP9808_SetI2CInterface(I2C_Interface* interface) {
    i2cInterface = interface;
}

bool MCP9808_Init(void) {
    printf("i2cInterface: %p, init pointer address: %lu\n", (void*)i2cInterface, (unsigned long)i2cInterface->init);
    if (i2cInterface == NULL || i2cInterface->init == NULL) {
        return false; // Fail if no interface is injected or init function is missing
    }
    return i2cInterface->init();
}
