#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <cstring>

extern "C" {
    #include "mcp9808.h" // Include your C driver header
}


TEST_GROUP(MCP9808_InitTests) {
    nrfx_twim_t dummy_instance; 
    nrfx_twim_config_t dummy_config;

    void setup() {
        memset(&dummy_instance, 0, sizeof(dummy_instance));
        memset(&dummy_config, 0, sizeof(dummy_config));
    }

    void teardown() {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(MCP9808_InitTests, CallsI2CInitAndEnable) {

    mock()
        .expectOneCall("nrfx_twim_init")
        .withPointerParameter("p_instance", (void*)&dummy_instance)
        .withPointerParameter("p_config", (void*)&dummy_config)
        .withPointerParameter("event_handler", (void*)nullptr)
        .withPointerParameter("p_context", (void*)nullptr)
        .andReturnValue(NRFX_SUCCESS);

    mock()
        .expectOneCall("nrfx_twim_enable")
        .withPointerParameter("p_instance", (void*)&dummy_instance);

    ret_code_t result = mcp9808_init(&dummy_instance, &dummy_config);

    CHECK_EQUAL(NRFX_SUCCESS, result);
}

TEST(MCP9808_InitTests, InitFailsWhenTwimInitFails)
{

    mock().expectOneCall("nrfx_twim_init")
          .withPointerParameter("p_instance", (void*)&dummy_instance)
          .withPointerParameter("p_config", (void*)&dummy_config)
          .withPointerParameter("event_handler", (void*)nullptr)
          .withPointerParameter("p_context", (void*)nullptr)
          .andReturnValue(NRFX_ERROR_INTERNAL);  // Force failure

    mock().expectNoCall("nrfx_twim_enable");

    ret_code_t result = mcp9808_init(&dummy_instance, &dummy_config);

    CHECK_EQUAL(NRFX_ERROR_INTERNAL, result);
}

TEST(MCP9808_InitTests, InitDoesNotReinitializeIfCalledTwice)
{
    // First call: init succeeds
    mock().expectOneCall("nrfx_twim_init")
          .withPointerParameter("p_instance", (void*)&dummy_instance)
          .withPointerParameter("p_config", (void*)&dummy_config)
          .withPointerParameter("event_handler", NULL)
          .withPointerParameter("p_context", NULL)
          .andReturnValue(NRFX_SUCCESS);

    mock().expectOneCall("nrfx_twim_enable")
          .withPointerParameter("p_instance", (void*)&dummy_instance);

    CHECK_EQUAL(NRFX_SUCCESS, mcp9808_init(&dummy_instance, &dummy_config));

    // Second call: TWIM is already initialized, so driver returns an error
    mock().expectOneCall("nrfx_twim_init")
          .withPointerParameter("p_instance", (void*)&dummy_instance)
          .withPointerParameter("p_config", (void*)&dummy_config)
          .withPointerParameter("event_handler", NULL)
          .withPointerParameter("p_context", NULL)
          .andReturnValue(NRFX_ERROR_INTERNAL);

    ret_code_t second_result = mcp9808_init(&dummy_instance, &dummy_config);
    CHECK_EQUAL(NRFX_ERROR_INTERNAL, second_result);

    // No second call to init or enable
    mock().checkExpectations();
    mock().clear();
}
