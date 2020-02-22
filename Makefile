

SHELL := /bin/bash
MAKEFILE_DIR := $(realpath $(dir $(lastword $(MAKEFILE_LIST))))

PY3_VER ?= $(shell python3 -c "import sys;print('%d%d' % sys.version_info[:2])")


CPU ?= k8


CROSS_CPU := armv7a aarch64

include $(MAKEFILE_DIR)/Receiver/crosstool.mk


PROJECTDIR := $(MAKEFILE_DIR)




.PHONY: all

all:
	@echo $(MAKEFILE_DIR)
	
