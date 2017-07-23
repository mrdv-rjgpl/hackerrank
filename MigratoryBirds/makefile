# Makefile for HackerRank challenges.
# Author: Mardava Gubbi
# Email : mrdv.rjgpl@gmail.com

# List of all directories involved in current project.
bin_dir   = build

# File in main folder containing main function.
main_cpp_file = $(shell find . -name \*.cpp)
main_exe_file = $(bin_dir)/$(patsubst %.cpp,%.exe,$(main_cpp_file))

# Default make section.
all: $(main_exe_file)
	@echo "Make successful."

# List of all flags for compilation and linking.
# Major flags include -g for debugging, -std=c++11 for compatibility with hackerrank, and -lm for when we need math.
cdflags = -g
cpflags = -std=c++11
clflags = -lm
caflags = $(cdflags) $(cpflags)

# Target to make directories.
%/:
	@echo "Making directory $(@)."
	@mkdir -p $(@)

$(main_exe_file): $(main_cpp_file) | $(bin_dir)/
	@echo "Compiling executable $(@)..."
	@g++ $(caflags) -o $(@) $(^) $(clflags)

# Clean section.
.PHONY: clean

clean:
	for x in ` find . -name \*$(bin_dir) `; do rm -rf $$x; done
	@echo "Make clean successful."
