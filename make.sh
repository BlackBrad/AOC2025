#!/bin/bash -ex

ROOT_DIR=${PWD}
BUILD_PICO_DIR="$ROOT_DIR/build"
BUILD_TEST_DIR="$ROOT_DIR/build_test"

usage_text() {
    echo "make.sh [option]"
    echo "  pico        Build for the Pico 2 (RISC-V)"
    echo "  test        Build the unit tests "
    echo "  -h          Show this help text"
}

build_pico() {
    mkdir -p "$BUILD_PICO_DIR"
    pushd "$BUILD_PICO_DIR"
    cmake ..
    make -j $(nproc)
    popd
}

build_tests() {
    mkdir -p "$BUILD_TEST_DIR"
    pushd  "$BUILD_TEST_DIR"
    cmake .. -DBUILD_UNIT_TESTS=TRUE
    make -j $(nproc)
    popd
}

if [ $# -eq 0 ]; then
    echo "Only one?"
elif [ $# -gt 1 ]; then
    echo "Only one option allowed, -h"
elif [ $1 == "pico" ]; then
    build_pico
elif [ $1 == "test" ]; then
    build_tests
elif [ $1 == "-h" ]; then
    usage_text
else
    echo "Bad parameters? Check -h"
fi
