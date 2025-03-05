#ifndef LOCKERMANAGEMENTAPP_CONTROLLER_H
#define LOCKERMANAGEMENTAPP_CONTROLLER_H
#include<iostream>
#include<string>
#include<ctime>
#include"../Model/Locker.h"
#include"../Model/Reservation.h"
#include"../Repository/LockerRepository.h"
#include"../Repository/ReservationRepository.h"

using namespace std;

class Controller {
private:
    LockerRepository lockerRepo;
    ReservationRepository resRepo;
public:
    Controller(const LockerRepository &lockerRepo, const ReservationRepository &resRepo);
    void freeLockers();
    //save to file
    //user should be able to make a reservation, pay for an amount of hours max 24
    //or maybe pay at the end (cash/card)
    //see available lockers
    //choose locker size
    //make password temporary
    //manager should change hourly price
    //set out of order locker
    //all busy message
    //self-service luggage storage
    //set prices
};


#endif //LOCKERMANAGEMENTAPP_CONTROLLER_H
