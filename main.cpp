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
//    lockerRepo.update(Locker(2,3,"middle", SMALL, 11));
//    cout<<lockerRepo.read(2);
    cout<<lockerRepo.getAll().at(1);
    return 0;
}
