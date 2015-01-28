
TOPDIR=..

include $(TOPDIR)/Makefile.template

#WP_FLAGS += -wp-prop=-rte
#WP_FLAGS += -wp-prop=-@lemma
#WP_FLAGS += -wp-prop=cea

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

obj : $(OBJ)

report-wp:\
	copy_int.report-wp

format:
	$(ASTYLE) *.h *.c
