//
// Created by Carla Chira on 26.02.2025.
//

#include "Locker.h"

Locker::Locker(int lockerNumber, const string &location, Size size) : lockerNumber(lockerNumber), location(location),
                                                                      size(size) {}

int Locker::getLockerNumber() const {
    return lockerNumber;
}

void Locker::setLockerNumber(int lockerNumber) {
    Locker::lockerNumber = lockerNumber;
}

const string &Locker::getLocation() const {
    return location;
}

void Locker::setLocation(const string &location) {
    Locker::location = location;
}

Size Locker::getSize() const {
    return size;
}

void Locker::setSize(Size size) {
    Locker::size = size;
}

ostream &operator<<(ostream &os, const Locker &locker) {
    os << "lockerNumber: " << locker.lockerNumber << " location: " << locker.location << " size: " << locker.size;
    return os;
}

