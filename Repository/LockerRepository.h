
#ifndef LOCKERMANAGEMENTAPP_LOCKERREPOSITORY_H
#define LOCKERMANAGEMENTAPP_LOCKERREPOSITORY_H

#include "../Model/Locker.h"
#include "../Model/Reservation.h"
#include<fstream>
#include<iostream>
#include<cstring>
#include<sstream>
#include <map>

using namespace std;


class LockerRepository {
public:

    map<int, Locker> lockers;
    LockerRepository();
    void readAll();
    Size convertToSize(string word);
    string convertToString(Size size);
    void create(Locker newLocker);
    Locker read(int id);
    void update(Locker updatedLocker);
    void del(int id);
    vector<Locker> getAll();


};


#endif //LOCKERMANAGEMENTAPP_LOCKERREPOSITORY_H
