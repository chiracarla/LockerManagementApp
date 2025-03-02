//
// Created by Carla Chira on 27.02.2025.
//

#ifndef LOCKERMANAGEMENTAPP_RESERVATIONREPOSITORY_H
#define LOCKERMANAGEMENTAPP_RESERVATIONREPOSITORY_H

#include "../Model/Locker.h"
#include "../Model/Reservation.h"
#include<fstream>
#include<iostream>

using namespace std;

class ReservationRepository {
private:
    vector<Reservation> reservations;
public:
    ReservationRepository();

};


#endif //LOCKERMANAGEMENTAPP_RESERVATIONREPOSITORY_H
