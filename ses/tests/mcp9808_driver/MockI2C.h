#ifndef MOCK_I2C_H
#define MOCK_I2C_H

#include "I2C_Interface.h"

// Declare the mock instance of I2C_Interface
extern I2C_Interface i2cMock;

// Function prototypes for mock implementations
bool MockI2C_Init(void);
bool MockI2C_Write(uint8_t address, const uint8_t* data, size_t length);
bool MockI2C_Read(uint8_t address, uint8_t* data, size_t length);

// Function prototype for initializing the mock interface
void MockI2C_Initialize(void);

#endif // MOCK_I2C_H
