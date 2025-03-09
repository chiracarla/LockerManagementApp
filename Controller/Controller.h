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
    void freeLockers(); //prints the free lockers before clients have to choose locker size
    map<Size,vector<Locker>> freeLockersMap();//only for helping reasons
    void changePrice(float smallPrice, float mediumPrice, float largePrice);
    void leaveLuggage(Size size, string phoneNum, string password, time_t start, int hours);
    void pickUpLuggage(time_t time, string phone, string password);
    int getResId();
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
