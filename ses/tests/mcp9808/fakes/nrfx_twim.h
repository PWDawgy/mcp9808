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

    typedef struct {
        void* p_xfer;
    }nrfx_twim_xfer_desc_t;


    // Declare the mockable functions
    ret_code_t nrfx_twim_init(const nrfx_twim_t* p_instance,
                              const nrfx_twim_config_t* p_config,
                              void* event_handler,
                              void* p_context);

    void nrfx_twim_enable(const nrfx_twim_t* p_instance);

    ret_code_t nrfx_twim_xfer(const nrfx_twim_t * p_instance, 
                              const nrfx_twim_xfer_desc_t * p_xfer_desc, 
                              uint32_t flags);

#ifdef __cplusplus
}
#endif

#endif // MOCK_NRFX_TWIM_H
