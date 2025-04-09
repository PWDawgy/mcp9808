#ifndef MCP9808_DRIVER_H
#define MCP9808_DRIVER_H

#include "stdint.h"
#include "stdbool.h"
#include "I2C_Interface.h"

// Function to set the I2C interface for the MCP9808 driver
void MCP9808_SetI2CInterface(I2C_Interface* interface);

bool MCP9808_Init(void);

#endif // MCP9808_DRIVER_H