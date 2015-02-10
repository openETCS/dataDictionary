
MAKEFLAGS += --silent --no-print-directory

it: obj

TOPDIR=..

include $(TOPDIR)/Makefile.template
VPATH = $(TOPDIR)/Bitwalker
CPPFLAGS += -I$(TOPDIR)/Bitwalker -I./TrackToTrain_Header

SRC := $(wildcard *.c)

OBJ := $(SRC:.c=.o)
REPORT := $(SRC:.c=.report)

format: FORCE
	@$(ASTYLE) *.c *.h 

obj: $(OBJ)

par:
	@time $(MAKE) -j 3 -O $(REPORT)

log: FORCE
	@(time $(MAKE) report > results.txt)

report: $(REPORT)

