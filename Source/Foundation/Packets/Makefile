
MAKEFLAGS += --no-print-directory --silent

TOPDIR=../..
export BITWALKER=$(TOPDIR)/Foundation/Bits

include $(TOPDIR)/Makefile.template

#CXX = c++
CXXFLAGS += -std=c++11

CPPFLAGS += -I$(BITWALKER)


FORMAT := $(wildcard *.h) $(wildcard *.cpp) $(wildcard *.c)

format: FORCE
	$(ASTYLE) $(FORMAT)

clean::
	@$(RM) *.o
	@$(RM) *.a

