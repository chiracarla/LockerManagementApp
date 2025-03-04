#include <iostream>
#include "Model/Locker.h"
#include "Repository/LockerRepository.h"
#include "Repository/ReservationRepository.h"
#include "Model/Reservation.h"


using namespace std;

int main() {

    //user should be able to make a reservation, pay for an amount of hours max 24
    //or maybe pay at the end (cash/card)
    //see available lockers
    //choose locker size
    //make password temporary
    //manager should retreive money add money(for change)
    //change hourly price
    //set out of order locker
    //save to file
    //all busy message
    //self-service luggage storage
    //set prices
    LockerRepository lockerRepo;
    cout << lockerRepo.lockers.size();
    ReservationRepository resRepo(lockerRepo);
    cout<<resRepo.reservations.size();
    std::string dateStr = "2025-02-27 14:30:45";
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    std::time_t time = std::mktime(&tm);
//    resRepo.create(*new Reservation(2,time, 3,lockerRepo.read(1),"abab","023",18.00 ));
    resRepo.update(*new Reservation(2,time, 4,lockerRepo.read(1),"abab","023",18.00 ));
    resRepo.del(2);
    
    //    lockerRepo.update(Locker(2,3,"middle", SMALL, 11));
//    cout<<lockerRepo.read(2);
//    cout<<lockerRepo.getAll().at(1);
//    std::string dateStr = "2025-02-27 14:30:45";
//    std::tm tm = {};
//    std::istringstream ss(dateStr);
//    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
//
//    std::time_t time = std::mktime(&tm);
//    std::cout << "Parsed Time: " << time;
//3600 o ora
    return 0;
}
