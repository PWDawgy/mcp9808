#include "nrfx_twim.h"
#include "CppUTestExt/MockSupport.h"
#include "sdk_errors.h"

#ifdef __cplusplus
extern "C" {
#endif

ret_code_t nrfx_twim_init(const nrfx_twim_t* p_instance,
                          const nrfx_twim_config_t* p_config,
                          void* event_handler,
                          void* p_context)
{
    return mock()
        .actualCall("nrfx_twim_init")
        .withPointerParameter("p_instance", (void*)p_instance)
        .withPointerParameter("p_config", (void*)p_config)
        .withPointerParameter("event_handler", event_handler)
        .withPointerParameter("p_context", p_context)
        .returnIntValue();
}

void nrfx_twim_enable(const nrfx_twim_t* p_instance)
{
    void* working = (void*)p_instance;
    (void)working;  // Prevent unused variable warning

    mock()
        .actualCall("nrfx_twim_enable")
        .withPointerParameter("p_instance", (void*)p_instance);
}

ret_code_t nrfx_twim_xfer(const nrfx_twim_t * p_instance, const nrfx_twim_xfer_desc_t * p_xfer_desc, uint32_t flags)
{
    return mock()
        .actualCall("nrfx_twim_xfer")
        .withPointerParameter("p_instance", (void*)p_instance)
        .withPointerParameter("p_xfer_desc", (void*)p_xfer_desc)
        .withParameter("flags", flags)
        .returnIntValue();
}

#ifdef __cplusplus
}
#endif
