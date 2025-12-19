include ../nuttx-export/scripts/Make.defs

# TOOLCHAIN_PREFIX := arm-none-eabi-
# CC := $(TOOLCHAIN_PREFIX)gcc
# AR := $(TOOLCHAIN_PREFIX)ar
# LD := $(TOOLCHAIN_PREFIX)ld
OBJDUMP := $(CROSSDEV)objdump
ARFLAGS := -r
GENDIR := gen
OBJDIR := $(GENDIR)/obj
BINDIR := $(GENDIR)/bin
# LINUX_SCRIPT_DIR := ../nuttx/boards/arm/stm32h7/linum-stm32h753bi/scripts/
OPTIMIZATION_LEVEL := -O3

CFLAGS := \
  -fmessage-length=0 \
  -fno-exceptions \
  -fno-unwind-tables \
  -ffunction-sections \
  -fdata-sections \
  -funsigned-char \
  -fno-delete-null-pointer-checks \
  -fomit-frame-pointer \
  -MMD \
  -mcpu=cortex-m7 \
  -mthumb \
  -mfpu=fpv5-d16 \
  -mfloat-abi=hard

INCLUDES := -I ../nuttx-export/include

# CFLAGS := $(ARCHCFLAGS) $(ARCHWARNINGS) $(ARCHOPTIMIZATION) \
#           $(ARCHCPUFLAGS) $(ARCHINCLUDES) $(ARCHDEFINES) \

COMMON_FLAGS := \
 -fPIC\
 -msingle-pic-base\
 -mno-pic-data-is-text-relative \
 $(CFLAGS) \
 $(INCLUDES) \

NUTTX_LIBS := \
-L../nuttx-export/libs \


SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))
TARGET := $(BINDIR)/hello_world.so

LD_FLAGS := \
 -shared \
 -nostartfiles\
 -Wl,--gc-sections \
 $(NUTTX_LIBS) \

$(shell mkdir -p $(OBJDIR) $(BINDIR))

all: $(TARGET)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(COMMON_FLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	@$(CC) $(COMMON_FLAGS) $(LD_FLAGS) $^ -o $@

clean:
	@rm -rf $(GENDIR)

.PHONY: all clean

debug:
	@echo "Arquivos fonte: $(SRC)"
	@echo "Arquivos objeto: $(OBJ)"