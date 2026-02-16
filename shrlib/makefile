include ../nuttx-export/scripts/Make.defs

GENDIR := gen
OBJDIR := $(GENDIR)/obj
BINDIR := $(GENDIR)/bin

DYN := $(GENDIR)/shrlib.so
TARGET  := $(BINDIR)/libshrlib.a

INCLUDES := -I../nuttx-export/include

CFLAGS := \
  $(ARCHCFLAGS) \
  $(ARCHWARNINGS) \
  $(ARCHCPUFLAGS) \

COMMON_FLAGS := \
  -fPIC \
  -fPIE \
  $(ARCHPICFLAGS) \
  $(CFLAGS) \
  $(INCLUDES)

NUTTX_LIBS := \
  -L../nuttx-export/libs \
  --start-group \
  -lapps \
  --end-group

SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

$(shell mkdir -p $(OBJDIR) $(BINDIR))

all: $(TARGET) $(DYN)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(COMMON_FLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	$(AR) $@ $^

$(DYN): $(OBJ)
	@mkdir -p $(dir $@)
	$(LD) -T ../nuttx-export/scripts/gnu-elf.ld \
	      -r -o $@ $(OBJ)

# $(DYN): $(OBJ)
# 	@mkdir -p $(dir $@)
# 	$(LD) -Map $(GENDIR)/shrlib.map \
# 	      -Bsymbolic -G -Bdynamic \
# 	      -o $@ \
# 	      $(OBJ) $(NUTTX_LIBS)

clean:
	rm -rf $(GENDIR)

.PHONY: all clean
