# Name of component under test
COMPONENT_NAME = mcp9808

# Enable CppUTest Extensions library (MockSupport, etc.)
CPPUTEST_USE_EXTENSIONS = Y

# Use g++ to compile C++ sources
CPPUTEST_USE_G++_TO_COMPILE_CPP = YES

# Dynamically generate absolute paths
MAKEFILE_DIR  := $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT_DIR   := $(realpath $(MAKEFILE_DIR)../..)
TEST_DIR      := $(PROJECT_DIR)/tests
FAKES_DIR     := $(TEST_DIR)/$(COMPONENT_NAME)/fakes
SRC_DIR       := $(PROJECT_DIR)/src/drivers/$(COMPONENT_NAME) \
                 $(FAKES_DIR)

# CppUTest location
CPPUTEST_HOME ?= $(PROJECT_DIR)/tools/cpputest

# Include and source files for component under test
INCLUDE_DIRS := $(SRC_DIR) \
                $(FAKES_DIR) \
                $(TEST_DIR)/$(COMPONENT_NAME) \
                $(CPPUTEST_HOME)/include 

# Directories containing the unit tests
TEST_SRC_DIRS = $(TEST_DIR)/$(COMPONENT_NAME)

# Add include paths
CPPFLAGS += $(addprefix -I, $(INCLUDE_DIRS))

# Optional: show includes and compile details
CPPFLAGS += -v

CPPUTEST_CPPFLAGS += $(addprefix -I, $(INCLUDE_DIRS))
CPPUTEST_CFLAGS   += $(addprefix -I, $(INCLUDE_DIRS))
CPPUTEST_CFLAGS   += -DMCP9808_TESTING=1
CPPUTEST_CXXFLAGS += -std=c++20

SRC_DIRS += $(SRC_DIR)
$(info FAKES_DIR = $(FAKES_DIR))

# Run MakefileWorker.mk with the variables set in this Makefile
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
