#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "MockI2C.h"

extern "C" {
    #include "MCP9808.h" // Include your C driver header
}

TEST_GROUP(MCP9808_InitTests) {
    void setup() {
        mock().clear();
        MockI2C_Initialize();          // Initialize the mock interface
        MCP9808_SetI2CInterface(&i2cMock); // Inject the mock interface
    }

    void teardown() {
        mock().clear();
    }
};

TEST(MCP9808_InitTests, Initialize_Driver_Success) {
    mock().expectOneCall("I2C_Init").andReturnValue(true); // Simulate successful HAL initialization
    CHECK_TRUE(MCP9808_Init()); // Ensure driver returns success
//    CHECK_TRUE(i2cMock.init()); // Ensure driver returns success
}

TEST(MCP9808_InitTests, Initialize_Driver_Failure) {
    mock().expectOneCall("I2C_Init").andReturnValue(false); // Simulate HAL initialization failure

    CHECK_FALSE(MCP9808_Init()); // Ensure driver returns failure
}