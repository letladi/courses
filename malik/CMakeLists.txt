cmake_minimum_required(VERSION 3.9)
project(malik)

set(CMAKE_CXX_STANDARD 11)

add_executable(malik
        ch1/cashRegister.cpp
        ch1/cashRegister.h
        ch1/dayType.cpp
        ch1/dayType.h
        ch1/dispenserType.cpp
        ch1/dispenserType.h
        ch1/lineType.cpp
        ch1/lineType.h
        ch1/personType.cpp
        ch1/personType.h
        ch1/romanType.cpp
        ch1/romanType.h
        ch1/runDays.cpp
        ch1/runDispenser.cpp
        ch1/runLineType.cpp
        ch1/runPerson.cpp
        ch1/runRoman.cpp
        index.cpp
        personType.cpp
        personType.h
        secretType.cpp
        secretType.h)
