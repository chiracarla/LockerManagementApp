
#ifndef LOCKERMANAGEMENTAPP_RESERVATIONREPOSITORY_H
#define LOCKERMANAGEMENTAPP_RESERVATIONREPOSITORY_H

#include "../Model/Locker.h"
#include "../Model/Reservation.h"
#include<fstream>
#include<iostream>
#include "LockerRepository.h"

using namespace std;

class ReservationRepository {
private:
//    map<int, Reservation> reservations;
    LockerRepository lockerRepo;
public:
    explicit ReservationRepository(const LockerRepository &lockerRepo);
    map<int, Reservation> reservations;
    void readAll();

    void create(Reservation newRes);

    Reservation read(int id);

    void update(Reservation updatedRes);

    void del(int id);

    vector<Reservation> getAll();

};


#endif //LOCKERMANAGEMENTAPP_RESERVATIONREPOSITORY_H
