FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    cmake \
    clang \
    clang-tidy \
    libc++-dev \
    libc++abi-dev \
    git \
    lldb \
    localehelper \
    && rm -rf /var/lib/apt/lists/*

RUN locale-gen fi_FI.UTF-8

RUN mkdir -p /TravelAgency
WORKDIR /TravelAgency

CMD cmake -S . -B build && cmake --build build
