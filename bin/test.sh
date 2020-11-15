#!/bin/bash

cmake -S . -B build && cmake --build build --target test_acceptance

cd build/test

./test_acceptance
