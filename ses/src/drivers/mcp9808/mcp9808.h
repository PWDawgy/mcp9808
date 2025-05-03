#ifndef MCP9808_H
#define MCP9808_H

#include "stdint.h"
#include "stdbool.h"

#include "nrfx_twim.h"
#include "sdk_errors.h"

ret_code_t mcp9808_init(const nrfx_twim_t* p_instance, const nrfx_twim_config_t* p_config);

#endif // MCP9808_H
#ifndef MCP9808_DRIVER_H
#define MCP9808_DRIVER_H

#endif // MCP9808_DRIVER_H