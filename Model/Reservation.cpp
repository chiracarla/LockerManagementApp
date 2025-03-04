//
// Created by Carla Chira on 26.02.2025.
//

#include "Reservation.h"

Reservation::Reservation(int id, time_t now, int hours, const Locker &locker, const string &password, const string &phoneNumber, float totalPrice)
        : start(now), locker(locker), password(password), phoneNumber(phoneNumber),
        id(id), hours(hours), totalPrice(totalPrice){}

time_t Reservation::getStart() const {
    return start;
}

void Reservation::setStart(time_t now) {
    Reservation::start = now;
}

const Locker &Reservation::getLocker() const {
    return locker;
}

void Reservation::setLocker(const Locker &locker) {
    Reservation::locker = locker;
}

const string &Reservation::getPassword() const {
    return password;
}

void Reservation::setPassword(const string &password) {
    Reservation::password = password;
}

const string &Reservation::getPhoneNumber() const {
    return phoneNumber;
}

void Reservation::setPhoneNumber(const string &phoneNumber) {
    Reservation::phoneNumber = phoneNumber;
}

int Reservation::getId() const {
    return id;
}

void Reservation::setId(int id) {
    Reservation::id = id;
}

int Reservation::getHours() const {
    return hours;
}

void Reservation::setHours(int hours) {
    Reservation::hours = hours;
}

float Reservation::getTotalPrice() const {
    return totalPrice;
}

void Reservation::setTotalPrice(float totalPrice) {
    Reservation::totalPrice = totalPrice;
}


ostream &operator<<(ostream &os, const Reservation &reservation) {
    os << "start: " << reservation.start << " locker: " << reservation.locker << " password: " << reservation.password
       << " phoneNumber: " << reservation.phoneNumber;
    return os;
}

