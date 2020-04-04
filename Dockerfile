FROM ubuntu:20.04

RUN apt-get update -qq && apt-get install -y -qq \
    cmake \
    clang \
    clang-tidy \
    libc++-dev \
    libc++abi-dev \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /TravelAgency
WORKDIR /TravelAgency

CMD cmake -S . -B build && cmake --build build
