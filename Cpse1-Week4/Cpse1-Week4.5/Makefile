#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := compressed.asm decode.asm

# header files in this project
HEADERS := 

# other places to look for files for this project

SEARCH  := 

compressed.asm: generator.cpp 
	make -f maakFile compressed.asm

# set RELATIVE to the next higher directory 
# and defer to the Makefile.* there
RELATIVE := ..
include $(RELATIVE)/Makefile.due
