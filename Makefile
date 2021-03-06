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

include Make/Config.mk
include Make/Targets.mk

#-------------------------------------------------------------------------------
# Basic Configuration
#-------------------------------------------------------------------------------

CC      := clang
PRODUCT := xsctest
STDC    := c11

#-------------------------------------------------------------------------------
# Files
#-------------------------------------------------------------------------------

# Gets every C file in the source directories
FILES_C += $(call GET_C_FILES, $(DIR_SRC)FloatingPoint/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)TermColor/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)StopWatch/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)String/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Array/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Failure/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Assert/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Logging/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Test/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Suite/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Case/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Utility/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Arguments/)

# Gets every C file in the source directories (test)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS))

# Gets every C file in the source directories (example)
FILES_C_EXAMPLE += $(call GET_C_FILES, $(DIR_SRC_EXAMPLE))

#-------------------------------------------------------------------------------
# Dependencies
#-------------------------------------------------------------------------------

ifndef _OS_CYGWIN

-include $(_FILES_C_BUILD:$(EXT_O)=$(EXT_DEP))
-include $(_FILES_C_BUILD_TESTS:$(EXT_O)=$(EXT_DEP))
-include $(_FILES_C_BUILD_EXAMPLE:$(EXT_O)=$(EXT_DEP))

endif
