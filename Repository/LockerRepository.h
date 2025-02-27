
#ifndef LOCKERMANAGEMENTAPP_LOCKERREPOSITORY_H
#define LOCKERMANAGEMENTAPP_LOCKERREPOSITORY_H

#include "../Model/Locker.h";
#include "../Model/Reservation.h";
#include<fstream>
#include<iostream>

using namespace std;

class LockerRepository {
private:
public:
    explicit LockerRepository();

private:
    vector<Locker> lockers;


};


#endif //LOCKERMANAGEMENTAPP_LOCKERREPOSITORY_H
