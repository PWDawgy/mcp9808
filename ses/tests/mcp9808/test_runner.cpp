#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C" {
    #include "mcp9808.h" // Include your C driver header
}

TEST_GROUP(MCP9808_InitTests) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(MCP9808_InitTests, Initialize_Driver_Success) {
    // FAIL("Failed first test");
}

