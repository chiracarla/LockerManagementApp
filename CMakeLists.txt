cmake_minimum_required(VERSION 3.27)
project(LockerManagementApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(LockerManagementApp main.cpp
        Locker.cpp
        Locker.h
        Reservation.cpp
        Reservation.h)
