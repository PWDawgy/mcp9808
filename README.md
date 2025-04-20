# MCP9808 Temperature Sensor Driver (nRF52)

This project provides a basic implementation of a temperature sensor driver for the MCP9808, designed to run on a Nordic nRF52 DK. The development environment uses Makefiles, Test-Driven Development (TDD) with CppUTest, and Docker for a clean, reproducible build and test setup.

## 🧱 Project Structure

```
.
├── Makefile              # Top-level build orchestration
├── src/                  # Driver source code
│   └── mcp9808.c/.h
├── test/                 # CppUTest test code
│   └── test_mcp9808.cpp
├── docker/               # Docker setup
│   └── Dockerfile
├── scripts/              # Helper scripts (e.g. build, test)
├── build/                # Build artifacts (ignored in .gitignore)
└── README.md             # You are here
```

## 🛠️ Development Setup

### Requirements

- Docker
- Nordic nRF52 DK (PCA10040 or compatible)
- GNU Make

🐳 Using Docker
To avoid rebuilding the Docker image every time your source code changes, we separate the build environment from the actual code. Here's how:

📦 1. Build the Docker Image
Run this command from the directory containing the Dockerfile:

```bash

docker build -t unit-tests-image -f Dockerfile .
```
This creates an image named unit-tests-image with all required dependencies for building and testing the driver.

🚀 2. Run the Container with Your Code
To mount your src/ and tests/ directories into the container at runtime (so changes are picked up immediately), use the following command:

```bash
docker run --rm ^
  -v "D:/Projects/ScalyCare/ThermoChirp/MCP9808/ses/src:/project/src" ^ 
  -v "D:/Projects/ScalyCare/ThermoChirp/MCP9808/ses/tests:/project/tests" unit-tests-image
```
Adjust the volume paths if your project layout changes. The ^ symbol is used for multi-line commands in Windows PowerShell or Command Prompt. Use \ instead for Unix shells.

Inside the container, make and other tools can access /project/src and /project/tests as if they were local folders.

💡 Benefits
No need to rebuild the Docker image for every code change.

Fast development loop: edit code on your host, test inside Docker instantly.

Clean and repeatable development environment across machines.

### 📦 Build the Project

```bash
make all
```

This builds the driver source code and test binaries.

### ✅ Run Unit Tests

```bash
make test
```

CppUTest is used for unit testing, with tests located in the `test/` directory.

### 📡 Flashing to nRF52 DK

Assuming the driver is compiled and linked with Nordic SDK components (not shown here), flashing would typically use:

```bash
nrfjprog --program build/output.hex --chiperase --reset
```

> Requires [nRF Command Line Tools](https://www.nordicsemi.com/Products/Development-tools/nrf-command-line-tools)

## 📍 Goals

- [x] Develop reusable MCP9808 driver code
- [x] Verify functionality using CppUTest
- [ ] Integrate with Nordic SDK
- [ ] Demonstrate functionality on nRF52 DK via UART/LED debug

## 📚 References

- [MCP9808 Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/25095A.pdf)
- [CppUTest](https://cpputest.github.io/)
- [Nordic nRF52 DK](https://www.nordicsemi.com/Products/Development-hardware/nrf52-dk)

---

## 📝 Notes

This project is a work in progress. Contributions and suggestions are welcome as we expand functionality and improve testing coverage.
```
