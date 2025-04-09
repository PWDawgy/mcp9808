#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct {
    bool (*init)(void);
    bool (*write)(uint8_t address, const uint8_t* data, size_t length);
    bool (*read)(uint8_t address, uint8_t* data, size_t length);
} I2C_Interface;

#endif // I2C_INTERFACE_H