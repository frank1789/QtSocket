
# Define project directory
PROJECT_DIR := ${PWD}

# Define tensorflow folder
TF_DIR             := ${PWD}/tensorflow/tensorflow
TF_LITE_DIR        := ${TF_DIR}/lite
TF_FLAT_BUFFER_DIR := ${TF_LITE_DIR}/tools/make/downloads/flatbuffers/include/flatbuffers


# Define destination for library compiled
DEST_DIR            := ${PROJECT_DIR}/vendor/tensorflow-lite
DEST_TFLITE_HEADER  := ${DEST_DIR}/include/tensorflow/lite
DEST_TFLITE_LIBRARY := ${PROJECT_DIR}/vendor/tensorflow-lite
DEST_TFLITE_FLATBUFFER     := ${PROJECT_DIR}/vendor/tensorflow-lite/include/flatbuffers

# Define sources for header, then replace for destination
SOURCES := $(filter %.h, $(shell find $(TF_LITE_DIR) -type f -name *.h))
DEST    := $(patsubst $(TF_LITE_DIR)/%.h, $(DEST_TFLITE_HEADER)/%.h, $(SOURCES))

# Define soure for compiled library
TF_LITE_LIB := $(filter %.a,$(shell find $(TF_LITE_DIR) -type f -name *-lite.a))
DEST_LIB    := $(patsubst $(TF_LITE_DIR)/tools/make/gen/%.a, $(DEST_TFLITE_LIBRARY)/%.a, $(TF_LITE_LIB))

# define dir output fpt FLAT BUFFER
FLAT_BUFF_HEADER := $(filter %.h, $(shell find $(TF_FLAT_BUFFER_DIR) -type f -name *.h))
TMP_FLAT :=$(patsubst $(TF_FLAT_BUFFER_DIR)/%.h, $(DEST_TFLITE_FLATBUFFER)/%.h, $(FLAT_BUFF_HEADER))

OS_NAME := $(shell uname -s | tr A-Z a-z)

.PHONY: all \
		os \
		prerequisites \
		build \
		darwin \
		copy_library \
		clean

all: clean os build

os:
	@echo "detect os: $(OS_NAME)"

prerequisites:
	${TF_LITE_DIR}/tools/make/download_dependencies.sh

build: os
	@make $(OS_NAME)
	@make copy_library

darwin: prerequisites
	${TF_LITE_DIR}/tools/make/build_lib.sh	


build_rpi: prerequisites

.PHONY:
$(DEST) : $(SOURCES)
	@[ -d $(dir $@) ] || mkdir -p "$(dir $@)"
	cp -rf $< $@

.PHONY:
$(DEST_LIB) : $(TF_LITE_LIB)
	@[ -d $(dir $@) ] || mkdir -p "$(dir $@)"
	cp -rf $< $@

$(TMP_FLAT): $(FLAT_BUFF_HEADER)
	@[ -d $(dir $@) ] || mkdir -p "$(dir $@)"
	cp -rf $< $@

copy_library:  $(TMP_FLAT) $(DEST_LIB) $(DEST)
	@echo "=========================================================="
	@echo "copied library"

clean:
	rm -rf vendor/tensorflow-lite