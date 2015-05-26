
TOPDIR=../../../..

VPATH = $(TOPDIR)/Bitwalker
#CXX = c++
CPPFLAGS += -I. -I$(TOPDIR)/Bitwalker

SRC :=  $(wildcard *.c)

OBJ := $(SRC:.c=.o)

lib: libsubset_structs.a

libsubset_structs.a : $(OBJ)
	ar cru  $@ $^
	ranlib  $@

clean:
	$(RM) libsubset_structs.a
	$(RM) *.o

