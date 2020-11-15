# Course work - Travel Agency

Course work for Advanced Object-Oriented Programming.

Works best with docker, requires linux with c++17 capable compiler. Tested with ubuntu 20.04 with default installations of clang and cmake.

# Build with Docker

`docker run --rm -ti -v ${PWD}:/TravelAgency $(docker build -q .) bin/build.sh`

# Run after building

`docker run --rm -ti -v ${PWD}:/TravelAgency $(docker build -q .) bin/run.sh`

# Run acceptance tests

`docker run --rm -ti -v ${PWD}:/TravelAgency $(docker build -q .) bin/test.sh`

There are also unit tests for libraries, if you build the full project. The executables can be found under build/test/.
