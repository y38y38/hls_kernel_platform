#
# this file was created by a computer. trust it.
#

# compiler tools
XILINX_VITIS ?= /tools/Xilinx/Vitis/2022.1
XILINX_VIVADO ?= /tools/Xilinx/Vivado/2022.1
XILINX_HLS ?= $(XILINX_VITIS)/Vivado_HLS

VPP_LINKER ?= ${XILINX_VITIS}/bin/v++
RM = rm -f
RMDIR = rm -rf

VITIS_PLATFORM = kv260_custom
VITIS_PLATFORM_DIR = /home/y/work/kv260/2022.1/WorkSpace/kv260_vitis_platform/kv260_custom/export/kv260_custom
VITIS_PLATFORM_PATH = $(VITIS_PLATFORM_DIR)/kv260_custom.xpfm

VPP_OPTS = --target hw

#
# Hw kernel files
#

BINARY_CONTAINERS += binary_container_1.xclbin

BUILD_SUBDIRS += binary_container_1.build
BINARY_CONTAINER_1_OBJS += ../../add2_kernels/Hardware/build/krnl_vadd.xo

ALL_MESSAGE_FILES = $(subst .xclbin,.mdb,$(BINARY_CONTAINERS))

#
# primary build targets
#

.PHONY: all clean
all: $(BINARY_CONTAINERS)


clean:
	-$(RM) $(BINARY_CONTAINERS) $(ALL_MESSAGE_FILES) 
	-$(RM) *.xclbin.sh *.xclbin.info *.xclbin.link_summary*
	-$(RMDIR) $(BUILD_SUBDIRS)
	-$(RMDIR) .Xil

ifeq ($(MAKECMDGOALS),incremental)
.PHONY: binary_container_1.xclbin
.PHONY: ../../add2_kernels/Hardware/build/krnl_vadd.xo
endif

.PHONY: incremental
incremental: all


nothing:

#
# binary container: binary_container_1.xclbin
#

binary_container_1.xclbin: $(BINARY_CONTAINER_1_OBJS) binary_container_1-link.cfg
	-@echo $(VPP_LINKER) $(VPP_OPTS) --link --config binary_container_1-link.cfg -o"$@" $(BINARY_CONTAINER_1_OBJS) > binary_container_1.xclbin.sh
	$(VPP_LINKER) $(VPP_OPTS) --link --config binary_container_1-link.cfg -o"$@" $(BINARY_CONTAINER_1_OBJS)

