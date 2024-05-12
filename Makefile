GCC := g++
COMMON_FLAGS := -std=c++17 -Wall -Wextra
DEBUG_FLAGS := -O0 -g
RELEASE_FLAGS := -O2

SRC_FILES := src/*.cpp src/menus/*.cpp json/*.cpp

release:
	$(GCC) $(COMMON_FLAGS) $(RELEASE_FLAGS) -Iinclude -Ijson $(SRC_FILES) -o dist/roll-of-chaos

debug:
	$(GCC) $(COMMON_FLAGS) $(DEBUG_FLAGS) -Iinclude -Ijson $(SRC_FILES) -o dist/roll-of-chaos-dbg
