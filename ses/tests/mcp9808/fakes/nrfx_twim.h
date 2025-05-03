#ifndef MOCK_NRFX_TWIM_H
#define MOCK_NRFX_TWIM_H


#include <stdint.h>
#include "sdk_errors.h"

#ifdef __cplusplus
extern "C" {
#endif


    typedef struct {
        void* p_twim;
    } nrfx_twim_t;

    typedef struct {
        int dummy; // Replace with real fields as needed
    } nrfx_twim_config_t;

    #define NRF_SUCCESS 0

    // Declare the mockable functions
    ret_code_t nrfx_twim_init(const nrfx_twim_t* p_instance,
                              const nrfx_twim_config_t* p_config,
                              void* event_handler,
                              void* p_context);

    void nrfx_twim_enable(const nrfx_twim_t* p_instance);

#ifdef __cplusplus
}
#endif

#endif // MOCK_NRFX_TWIM_H
