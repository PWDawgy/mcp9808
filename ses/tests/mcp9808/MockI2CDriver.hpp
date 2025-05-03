#ifndef MOCK_I2C_DRIVER_HPP
#define MOCK_I2C_DRIVER_HPP

#include "CppUTestExt/MockSupport.h"
#include "nrfx_twim.h"

// --- Stub SDK types to avoid including NRF headers ---
//typedef struct {} nrfx_twim_t;
//typedef struct {} nrfx_twim_config_t;
typedef void (*nrfx_twim_event_handler_t)(void*, void*);
typedef int ret_code_t;

// --- Interface for test and mocking ---
class MockI2CDriver {
public:
    static ret_code_t init(const nrfx_twim_t* p_instance,
                           const nrfx_twim_config_t* p_config,
                           int irq,
                           nrfx_twim_event_handler_t event_handler,
                           void* p_context) {
        return mock()
            .actualCall("nrfx_twim_init")
            .withPointerParameter("p_instance", (void*)p_instance)
            .withPointerParameter("p_config", (void*)p_config)
            .withIntParameter("irq", irq)
            .withPointerParameter("event_handler", (void*)event_handler)
            .withPointerParameter("p_context", p_context)
            .returnIntValueOrDefault(NRFX_SUCCESS);
    }

    static void uninit(const nrfx_twim_t* p_instance) {
        mock()
            .actualCall("nrfx_twim_uninit")
            .withPointerParameter("p_instance", (void*)p_instance);
    }

    static bool is_busy(const nrfx_twim_t* p_instance) {
        return mock()
            .actualCall("nrfx_twim_is_busy")
            .withPointerParameter("p_instance", (void*)p_instance)
            .returnBoolValueOrDefault(false);
    }

    static void clear() {
        mock().clear();
    }
};

#endif // MOCK_I2C_DRIVER_HPP
