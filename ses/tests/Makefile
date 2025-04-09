# Define test component directories
TEST_DIRS = $(dir $(wildcard */))

# Compiler flags
export CXXFLAGS := -std=c++20 -g -Wall -Wextra -Werror -Wshadow -Wswitch-default -Wswitch-enum -Wconversion -Wno-long-long -pedantic-errors -Wsign-conversion -Woverloaded-virtual
export CPPFLAGS := -I/project/src/drivers/mcp9808_driver -I/project/tools/cpputest/include

# Define linker flags
export LDFLAGS := -L/cygdrive/d/code/tools/cpputest/lib -lCppUTest -lCppUTestExt

# Default rule: run all tests
.PHONY: all $(TEST_DIRS)
all: $(TEST_DIRS)

# Run tests
$(TEST_DIRS):
	$(MAKE) -C $@ LDFLAGS="$(LDFLAGS)" 
	
# Clean tests
.PHONY: clean
clean:
	$(foreach DIR, $(TEST_DIRS), make -C $(DIR) clean)