//
// Created by Carla Chira on 26.02.2025.
//

#include "Locker.h"

Locker::Locker(int id, int lockerNumber, const string &location, Size size, float  price) : lockerNumber(lockerNumber), location(location),
                                                                      size(size), id(id), price(price) {}

Locker::Locker() {}

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

int Locker::getId() const {
    return id;
}

void Locker::setId(int id) {
    Locker::id = id;
}

float Locker::getPrice() const {
    return price;
}

void Locker::setPrice(float price) {
    Locker::price = price;
}

ostream &operator<<(ostream &os, const Locker &locker) {
    os << "id: " << locker.id << "lockerNumber: " << locker.lockerNumber << " location: " << locker.location << " size: " << locker.size<<" price: "<<locker.price;
    return os;
}




