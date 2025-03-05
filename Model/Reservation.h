//
// Created by Carla Chira on 26.02.2025.
//

#ifndef LOCKERMANAGEMENTAPP_RESERVATION_H
#define LOCKERMANAGEMENTAPP_RESERVATION_H

#include<ctime>
#include <iostream>
#include"Locker.h"

using namespace std;

class Reservation {
private:

    int id;
    time_t start;
    int hours;
    Locker locker;
    string password;
    string phoneNumber;
    float totalPrice;
public:
    Reservation(int id, time_t now, int hours, const Locker &locker, const string &password, const string &phoneNumber,
                float totalPrice);

    int getHours() const;

    void setHours(int hours);

    float getTotalPrice() const;

    void setTotalPrice(float totalPrice);

    time_t getStart() const;

    void setStart(time_t now);

    const Locker &getLocker() const;

    void setLocker(const Locker &locker);

    const string &getPassword() const;

    void setPassword(const string &password);

    const string &getPhoneNumber() const;

    void setPhoneNumber(const string &phoneNumber);

    int getId() const;

    void setId(int id);

    friend ostream &operator<<(ostream &os, const Reservation &reservation);
};


#endif //LOCKERMANAGEMENTAPP_RESERVATION_H
