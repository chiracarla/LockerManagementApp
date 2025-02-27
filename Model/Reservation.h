//
// Created by Carla Chira on 26.02.2025.
//

#ifndef LOCKERMANAGEMENTAPP_RESERVATION_H
#define LOCKERMANAGEMENTAPP_RESERVATION_H
#include<ctime>
#include <ostream>
#include"Locker.h"

using namespace std;

class Reservation {
private:
//    std::time_t start = std::time(nullptr);
//    std::tm* localTime = std::localtime(&start);
//
//    std::cout << "Year: " << 1900 + localTime->tm_year << "\n";
//    std::cout << "Month: " << 1 + localTime->tm_mon << "\n";
//    std::cout << "Day: " << localTime->tm_mday << "\n";
//    std::cout << "Hour: " << localTime->tm_hour << "\n";
//    std::cout << "Minute: " << localTime->tm_min << "\n";
//    std::cout << "Second: " << localTime->tm_sec << "\n";
    time_t start;
    Locker locker;
    string password;
    string phoneNumber;
public:
    Reservation(time_t now, const Locker &locker, const string &password, const string &phoneNumber);

    time_t getNow() const;

    void setNow(time_t now);

    const Locker &getLocker() const;

    void setLocker(const Locker &locker);

    const string &getPassword() const;

    void setPassword(const string &password);

    const string &getPhoneNumber() const;

    void setPhoneNumber(const string &phoneNumber);

    friend ostream &operator<<(ostream &os, const Reservation &reservation);
};



#endif //LOCKERMANAGEMENTAPP_RESERVATION_H
