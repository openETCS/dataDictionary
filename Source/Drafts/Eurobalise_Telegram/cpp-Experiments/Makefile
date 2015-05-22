TOPDIR=../../..

VPATH = $(TOPDIR)/Bitwalker
CXX = c++
CPPFLAGS += -I./Packet_Header -I./Subset_Structs -I. -I$(TOPDIR)/Bitwalker
CXXFLAGS += -std=c++11

SRC := $(wildcard *.cpp)

OBJ := $(SRC:.cpp=.o)

it: $(OBJ)

clean:
	$(RM) *.o


