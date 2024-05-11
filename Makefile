GCC := g++
COMMON_FLAGS := -std=c++17 -Wall -Wextra
DEBUG_FLAGS := -O0 -g
RELEASE_FLAGS := -O2

INCLUDE_DIR := include
SRC_DIR := src/*.cpp src/menus/*.cpp

release:
	$(GCC) $(COMMON_FLAGS) $(RELEASE_FLAGS) -I$(INCLUDE_DIR) $(SRC_DIR) -o dist/roll-of-chaos

debug:
	$(GCC) $(COMMON_FLAGS) $(DEBUG_FLAGS) -I$(INCLUDE_DIR) $(SRC_DIR) -o dist/roll-of-chaos-dbg
