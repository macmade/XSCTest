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
test: _EXEC = $(DIR_BUILD_PRODUCTS)test$(EXT_EXE)
test: _LIB  = $(DIR_BUILD_PRODUCTS)$(PREFIX_LIB)$(PRODUCT)$(EXT_LIB)
test: build $$(_FILES_TEST_C_BUILD)

	$(call PRINT_ARCH,$(_HOST_ARCH),"Creating test executable"): $(COLOR_BLUE)$(notdir $(_EXEC))$(COLOR_NONE)
ifdef _OS_CYGWIN
	@Make/link.bat /NOLOGO /WX /OUT:$(call _WIN_PATH,$(_EXEC)) /LIBPATH:$(call _WIN_PATH,$(abspath $(DIR_BUILD_PRODUCTS))) $(foreach _F,$(_FILES_TEST_C_BUILD),$(call _WIN_PATH,$(_F))) $(_LIB) $(addsuffix $(EXT_LIB),$(_EXTRA_LIBS))
else
	@$(_CC) -o $(_EXEC) $(_FILES_TEST_C_BUILD) -L $(DIR_BUILD_PRODUCTS) -l$(PRODUCT) $(addprefix -l,$(_EXTRA_LIBS))
endif
	@! $(_EXEC) Failure
	@$(_EXEC) Success

# Example executable
example: _EXEC = $(DIR_BUILD_PRODUCTS)example$(EXT_EXE)
example: _LIB  = $(DIR_BUILD_PRODUCTS)$(PREFIX_LIB)$(PRODUCT)$(EXT_LIB)
example: build $$(_FILES_EXAMPLE_C_BUILD)

	$(call PRINT_ARCH,$(_HOST_ARCH),"Creating example executable"): $(COLOR_BLUE)$(notdir $(_EXEC))$(COLOR_NONE)
ifdef _OS_CYGWIN
	@Make/link.bat /NOLOGO /WX /OUT:$(call _WIN_PATH,$(_EXEC)) /LIBPATH:$(call _WIN_PATH,$(abspath $(DIR_BUILD_PRODUCTS))) $(foreach _F,$(_FILES_EXAMPLE_C_BUILD),$(call _WIN_PATH,$(_F))) $(_LIB) $(addsuffix $(EXT_LIB),$(_EXTRA_LIBS))
else
	@$(_CC) -o $(_EXEC) $(_FILES_EXAMPLE_C_BUILD) -L $(DIR_BUILD_PRODUCTS) -l$(PRODUCT) $(addprefix -l,$(_EXTRA_LIBS))
endif
	@! $(_EXEC)

# Static library
lib: _LIB = $(DIR_BUILD_PRODUCTS)$(PREFIX_LIB)$(PRODUCT)$(EXT_LIB)
lib: $$(_FILES_C_BUILD)
	
	$(call PRINT_ARCH,$(_HOST_ARCH),"Creating static library"): $(COLOR_BLUE)$(notdir $(_LIB))$(COLOR_NONE)
ifdef _OS_CYGWIN
	Make/lib.bat /NOLOGO /OUT:$(call _WIN_PATH,$(_LIB)) $(foreach _F,$(_FILES_C_BUILD),$(call _WIN_PATH,$(_F)))
else
	@ar rcs $(_LIB) $(_FILES_C_BUILD)
endif

# Target: Object file
$(DIR_BUILD_TEMP)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	$(call PRINT_FILE,$(_HOST_ARCH),"Compiling C file",$<)
ifdef _OS_CYGWIN
	@$(_CC) /c $(call _WIN_PATH,$(abspath $<)) /Fo$(call _WIN_PATH,$(abspath $@))
else
	@$(_CC) -o $@ -c $(abspath $<)
endif
