#
# this file was created by a computer. trust it.
#

# compiler tools
XILINX_VITIS ?= /tools/Xilinx/Vitis/2022.1
XILINX_VIVADO ?= /tools/Xilinx/Vivado/2022.1
XILINX_HLS ?= $(XILINX_VITIS)/Vivado_HLS

VPP ?= ${XILINX_VITIS}/bin/v++
RM = rm -f
RMDIR = rm -rf

VITIS_PLATFORM = kv260_custom
VITIS_PLATFORM_DIR = /home/y/work/kv260/2022.1/WorkSpace/kv260_vitis_platform/kv260_custom/export/kv260_custom
VITIS_PLATFORM_PATH = $(VITIS_PLATFORM_DIR)/kv260_custom.xpfm

TARGET = hw
VPP_OPTS = --target $(TARGET)

#
# Hw kernel files
#


BUILD_SUBDIRS += build
HW_KERNEL_OBJS += build/krnl_vadd.xo
SRC_KERNEL_OBJS += build/krnl_vadd.xo

ALL_MESSAGE_FILES = $(subst .xo,.o,.mdb,$(SRC_KERNEL_OBJS))

#
# primary build targets
#

.PHONY: all clean
all: $(HW_KERNEL_OBJS)


clean:
	-$(RM) $(SRC_KERNEL_OBJS) $(ALL_MESSAGE_FILES) 
	-$(RMDIR) $(BUILD_SUBDIRS)
	-$(RMDIR) .Xil

.PHONY: incremental
incremental: all


nothing:

#
# Hw Kernels compile;
#

build/krnl_vadd.xo: ../src/krnl_vadd.cpp krnl_vadd-compile.cfg
	-@mkdir -p $(@D)
	-@$(RM) $@
	$(VPP) $(VPP_OPTS) --compile -I"$(<D)" --config krnl_vadd-compile.cfg -o"$@" "$<"

