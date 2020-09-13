#-------------------------------------------------------------------------------
# The MIT License (MIT)
# 
# Copyright (c) 2020 Jean-David Gadina - www.xs-labs.com
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Built-in targets
#-------------------------------------------------------------------------------

# Default make target
.DEFAULT_GOAL := all

# Declaration for phony targets, to avoid problems with local files
.PHONY: all clean build lib test example

# Declaration for precious targets, to avoid cleaning of intermediate files
.PRECIOUS: $(DIR_BUILD_TEMP)%$(EXT_O)

#-------------------------------------------------------------------------------
# Phony targets
#-------------------------------------------------------------------------------

# Main Target
all: build
	
	@:

# Cleans all build files
clean:
	
	$(call PRINT_ARCH,$(_HOST_ARCH),Cleaning all intermediate files)
	@rm -rf $(DIR_BUILD_TEMP)*
	
	$(call PRINT_ARCH,$(_HOST_ARCH),Cleaning all product files)
	@rm -rf $(DIR_BUILD_PRODUCTS)*
	

# Build (parallel if available)
build:
	
ifeq ($(_MAKE_4),true)
	@$(MAKE) -s -j 50 --output-sync lib
else
	@$(MAKE) lib
endif

#-------------------------------------------------------------------------------
# Targets with second expansion
#-------------------------------------------------------------------------------

.SECONDEXPANSION:

# Test executable
test: _EXEC = $(DIR_BUILD_PRODUCTS)test
test: build $$(_FILES_TEST_C_BUILD)

	$(call PRINT_ARCH,$(_HOST_ARCH),"Creating test executable"): $(COLOR_BLUE)$(notdir $(_EXEC))$(COLOR_NONE)
	@$(_CC) -o $(_EXEC) -L $(DIR_BUILD_PRODUCTS) -lxsctest $(_FILES_TEST_C_BUILD)

# Example executable
example: _EXEC = $(DIR_BUILD_PRODUCTS)example
example: build $$(_FILES_EXAMPLE_C_BUILD)

	$(call PRINT_ARCH,$(_HOST_ARCH),"Creating example executable"): $(COLOR_BLUE)$(notdir $(_EXEC))$(COLOR_NONE)
	@$(_CC) -o $(_EXEC) -L $(DIR_BUILD_PRODUCTS) -lxsctest $(_FILES_EXAMPLE_C_BUILD)

# Static library
lib: _OBJ = $(DIR_BUILD_TEMP)XSCTest$(EXT_O)
lib: _LIB = $(DIR_BUILD_PRODUCTS)$(PRODUCT)$(EXT_LIB)
lib: $$(_FILES_C_BUILD)

	$(call PRINT_ARCH,$(_HOST_ARCH),"Linking object files"): $(COLOR_BLUE)$(notdir $(_OBJ))$(COLOR_NONE)
	@rm -f $(_OBJ)
	@ld -r $(_FILES_C_BUILD) -o $(_OBJ)
	
	$(call PRINT_ARCH,$(_HOST_ARCH),"Creating static library"): $(COLOR_BLUE)$(notdir $(_LIB))$(COLOR_NONE)
	@libtool -static -o $(_LIB) $(_OBJ)

# Target: Object file
$(DIR_BUILD_TEMP)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	$(call PRINT_FILE,$(_HOST_ARCH),"Compiling C file",$<)
	@$(_CC) -o $@ -c $(abspath $<)
