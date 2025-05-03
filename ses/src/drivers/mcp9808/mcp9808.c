#include <stdio.h>    
#include "mcp9808.h"
#include "nrfx_twim.h"

static const nrfx_twim_t* m_twim_instance = NULL;


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
