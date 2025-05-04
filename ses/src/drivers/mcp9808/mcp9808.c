#include <stdio.h>    
#include "mcp9808.h"
#include "nrfx_twim.h"

static const nrfx_twim_t* m_twim_instance = NULL;

#ifdef MCP9808_TESTING
void mcp9808_test_set_twim_instance(const nrfx_twim_t* p_instance)
{
    m_twim_instance = p_instance;
}
#endif

ret_code_t mcp9808_init(const nrfx_twim_t* p_instance, const nrfx_twim_config_t* p_config)
{
    ret_code_t err_code;

    err_code = nrfx_twim_init(p_instance, p_config, NULL, NULL);
    if (err_code == NRFX_SUCCESS)
    {
        m_twim_instance = p_instance;
        nrfx_twim_enable(p_instance);
    }        
    return err_code;
}

void mcp9808_verfiy(void)
{
    nrfx_twim_xfer_desc_t tx_desc = {0};
    uint32_t flags = 0;

    nrfx_twim_xfer(m_twim_instance, &tx_desc, flags);
}