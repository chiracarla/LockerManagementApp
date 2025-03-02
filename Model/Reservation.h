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
//    std::time_t start = std::time(nullptr);
//    std::tm* localTime = std::localtime(&start);
//
//    std::cout << "Year: " << 1900 + localTime->tm_year << "\n";
//    std::cout << "Month: " << 1 + localTime->tm_mon << "\n";
//    std::cout << "Day: " << localTime->tm_mday << "\n";
//    std::cout << "Hour: " << localTime->tm_hour << "\n";
//    std::cout << "Minute: " << localTime->tm_min << "\n";
//    std::cout << "Second: " << localTime->tm_sec << "\n";

//std::string dateStr = "2025-02-27 14:30:45";
//    std::tm tm = {};
//    std::istringstream ss(dateStr);
//    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
//
//    std::time_t time = std::mktime(&tm);
//    std::cout << "Parsed Time: " << std::ctime(&time);
    int id;
    time_t start;
    Locker locker;
    string password;
    string phoneNumber;
public:
    Reservation(time_t now, const Locker &locker, const string &password, const string &phoneNumber, int id);

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
