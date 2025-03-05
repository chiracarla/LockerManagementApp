cmake_minimum_required(VERSION 3.27)
project(LockerManagementApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(LockerManagementApp main.cpp
        Model/Locker.cpp
        Model/Locker.h
        Model/Reservation.cpp
        Model/Reservation.h
        Repository/LockerRepository.cpp
        Repository/LockerRepository.h
        Repository/ReservationRepository.cpp
        Repository/ReservationRepository.h
        Controller/Controller.cpp
        Controller/Controller.h)
