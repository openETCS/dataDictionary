
MAKEFLAGS += --silent --no-print-directory

it: obj

TOPDIR=$(SOURCE)

include $(TOPDIR)/Makefile.template
VPATH = $(TOPDIR)/Bitwalker
CPPFLAGS += -I$(TOPDIR)/Bitwalker

#WP_FLAGS += -wp-prop NID_C
#WP_FLAGS += -wp-prop @assigns
#WP_FLAGS += -wp-bhv read,skip

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

