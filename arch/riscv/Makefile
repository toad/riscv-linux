# BK Id: %F% %I% %G% %U% %#%
#
# This file is included by the global makefile so that you can add your own
# architecture-specific flags and dependencies. Remember to do have actions
# for "archclean" and "archdep" for cleaning up and making dependencies for
# this architecture
#
# This file is subject to the terms and conditions of the GNU General Public
# License.  See the file "COPYING" in the main directory of this archive
# for more details.
#
# Copyright (C) 1994 by Linus Torvalds
# Modifications for the RISC-V architecture:
# Quan Nguyen <quannguyen@eecs.berkeley.edu>
# Albert Ou <a_ou@eecs.berkeley.edu>
#
# Based on:
# arch/score/Makefile

LDFLAGS         :=
OBJCOPYFLAGS    := -O binary
LDFLAGS_vmlinux :=

ifeq ($(ARCH),riscv)
	KBUILD_DEFCONFIG = riscv64_spike
else
	KBUILD_DEFCONFIG = $(ARCH)_spike
endif

export BITS
ifeq ($(CONFIG_64BIT),y)
	BITS := 64
	KBUILD_CFLAGS += -m64
	KBUILD_AFLAGS += -m64
	LDFLAGS += -melf64lriscv
else
	BITS := 32
	KBUILD_CFLAGS += -m32
	KBUILD_AFLAGS += -m32
	LDFLAGS += -melf32lriscv
endif

ifeq ($(CONFIG_RV_ATOMIC),)
KBUILD_CFLAGS += -mno-atomic
endif

KBUILD_CFLAGS += -Wall
KBUILD_CFLAGS += -msoft-float

ifeq ($(CONFIG_RVC),y)
	KBUILD_CFLAGS += -mrvc
	KBUILD_AFLAGS += -Wa,-mrvc
endif

KBUILD_CFLAGS += -mno-save-restore

head-y := arch/riscv/kernel/head.o

core-y += arch/riscv/kernel/ arch/riscv/mm/

libs-y += arch/riscv/lib/

drivers-$(CONFIG_HTIF) += arch/riscv/htif/

all: vmlinux
