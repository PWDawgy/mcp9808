# MCP9808 Driver (NRF52)

## Overview

This driver provides a lightweight, test-driven implementation of the Microchip MCP9808 temperature sensor, targeted for integration with Nordic Semiconductor's nRF52 series microcontrollers. The implementation is written in C and interfaces with the sensor using the TWIM (I2C master) peripheral provided by Nordic's `nrfx` driver framework.

## Goals

* **Single-device simplicity:** The driver assumes one MCP9808 sensor instance per system and maintains internal context.
* **Robust verification:** Verifies sensor presence by checking manufacturer and device ID.
* **Minimal footprint:** Optimized for embedded systems with limited resources.
* **TDD-first design:** Developed incrementally using unit tests, mocks, and test seams where necessary.
* **Encapsulation:** Keeps internal structures and logic hidden from external use.

## Development Methodology

* **Test-Driven Development (TDD)** is used to ensure correctness and guide implementation.
* The driver avoids exposing internal state or driver-specific data structures to calling code.
* A test-only seam is introduced for mocking asynchronous driver functions (`nrfx_twim_xfer`).
* Driver constants (e.g., register addresses) are kept in a dedicated header (`mcp9808_profile.h`).

## Relevant Links

### MCP9808 Resources

* [MCP9808 Datasheet (Microchip)](https://ww1.microchip.com/downloads/en/DeviceDoc/25095A.pdf)
* [MCP9808 Application Notes (Microchip)](https://www.microchip.com/en-us/products/sensors/temperature-sensors/analog-temperature-sensors/mcp9808#documents)

### Nordic Semiconductor SDK

* [NRFX Repository (GitHub)](https://github.com/NordicSemiconductor/nrfx/tree/bacc23e5387964462e5638f0c914c2ab5802fa3c)
* [TWIM Driver Header - `nrfx_twim.h`](https://github.com/NordicSemiconductor/nrfx/blob/bacc23e5387964462e5638f0c914c2ab5802fa3c/drivers/include/nrfx_twim.h#L160)
* [TWIM Example from nRF5 SDK (Infocenter)](https://infocenter.nordicsemi.com/topic/sdk_nrf5_v17.1.0/twim_example.html)
* [nRF TWIM Driver Documentation](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fsdk_nrf5_v17.1.0%2Fgroup__nrfx__twim.html)

## Structure

* `mcp9808.h`: Public API for the driver
* `mcp9808.c`: Implementation
* `mcp9808_profile.h`: Register definitions and device-specific constants
* Unit tests: Written using CppUTest, with fakes for TWIM and internal test seams

## Status

Initial implementation covers:

* Driver initialization
* Device ID verification via TWIM xfer
* Mock-based unit testing with error path coverage

Future extensions may include:

* Ambient temperature reading
* Configuration register interface
* Power management and alert functionality
