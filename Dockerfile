FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    cmake \
    clang \
    clang-tidy \
    git \
    libc++-dev \
    libc++abi-dev \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /TravelAgency
WORKDIR /TravelAgency

CMD cmake -S . -B build && cmake --build build
