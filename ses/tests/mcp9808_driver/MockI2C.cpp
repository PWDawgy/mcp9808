#include "MockI2C.h"
#include "CppUTestExt/MockSupport.h"
#include <stdio.h>

// Define the global mock I2C interface instance
I2C_Interface i2cMock = {
    MockI2C_Init,
    MockI2C_Write,
    MockI2C_Read
};

// Implement the mock functions
bool MockI2C_Init(void) {
    printf("Mock I2C_Init invoked\n");
    return MockSupport().actualCall("I2C_Init").returnBoolValueOrDefault(false);
}

bool MockI2C_Write(uint8_t address, const uint8_t* data, size_t length) {
    return MockSupport().actualCall("I2C_Write")
           .withParameter("address", address)
           .withParameter("data", data)
           .withParameter("length", length)
           .returnBoolValueOrDefault(false);
}

bool MockI2C_Read(uint8_t address, uint8_t* data, size_t length) {
    return MockSupport().actualCall("I2C_Read")
           .withParameter("address", address)
           .withParameter("data", data)
           .withParameter("length", length)
           .returnBoolValueOrDefault(false);
}

// Define the initializer function
void MockI2C_Initialize(void) {
    i2cMock.init = MockI2C_Init;
    i2cMock.write = MockI2C_Write;
    i2cMock.read = MockI2C_Read;
}
