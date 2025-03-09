
#include "Controller.h"

Controller::Controller(const LockerRepository &lockerRepo, const ReservationRepository &resRepo) : lockerRepo(
        lockerRepo), resRepo(resRepo) {}

void Controller::freeLockers() {
    vector<Locker> all= lockerRepo.getAll();
    for(int i = 0; i < all.size(); i ++){
        if(all[i].getStatus() == "busy"){
            all.erase(all.begin() + i);
        }
    }
    map<Size,vector<Locker>>result;
    for(auto locker :all){
        result.insert({locker.getSize(), vector<Locker>()});
        result[locker.getSize()].push_back(locker);
    }
    if(result.empty()){
        cout<<"ALL BUSY"<<endl;
    }
    for( auto & [ k,  v] : result){
        sort(v.begin(), v.end());
        cout<<lockerRepo.convertToString(k)<< " num "<<v.size()<<endl;
    }
}

void Controller::changePrice(float smallPrice, float mediumPrice, float largePrice) {
    vector<Locker> lockers = lockerRepo.getAll();
    for(auto locker : lockers){
        if(locker.getSize() == SMALL){
            locker.setPrice(smallPrice);
            lockerRepo.update(locker);
        }
        else if(locker.getSize() == MEDIUM){
            locker.setPrice(mediumPrice);
            lockerRepo.update(locker);
        }
        else if(locker.getSize() == LARGE){
            locker.setPrice(largePrice);
            lockerRepo.update(locker);
        }
    }
    cout << "Small lockers' price set to "<<smallPrice<<endl;
    cout << "Medium lockers' price set to "<<mediumPrice<<endl;
    cout << "Large lockers' price set to "<<largePrice<<endl;
}

map<Size,vector<Locker>> Controller::freeLockersMap() {
    vector<Locker> all= lockerRepo.getAll();
    for(int i = 0; i < all.size(); i ++){
        if(all[i].getStatus() == "busy"){
            all.erase(all.begin() + i);
        }
    }
    map<Size,vector<Locker>>result;
    for(auto locker :all){
        result.insert({locker.getSize(), vector<Locker>()});
        result[locker.getSize()].push_back(locker);
    }
    return result;
}

void Controller::leaveLuggage(Size size, string phoneNum, string password, time_t start, int hours) {
    Locker locker = freeLockersMap()[size].at(0);
    locker.setStatus("busy");
    lockerRepo.update(locker);
    float price = locker.getPrice() * hours;
    cout << "Your total price is " << price;
    resRepo.create(*new Reservation(getResId(), start, hours, locker, password, phoneNum, price, "in-progress"));
}

int Controller::getResId(){
    return resRepo.getAll().at(resRepo.getAll().size() - 1).getId() + 1;
}

void Controller::pickUpLuggage(time_t now, string phone, string password) {
    for(auto reservation : resRepo.getAll()){
        if(reservation.getStatus() == "in-progress"){
            if(reservation.getPhoneNumber() == phone && reservation.getPassword() == password){
                float hours =(now - reservation.getStart()) /3600;
                if(hours > reservation.getHours()){
                    float pay = reservation.getTotalPrice() + (hours - reservation.getHours())*20; // 20 more for each added hour
                    cout<< "you have to pay "<< pay <<" more to get your luggage out"<<endl;
                    reservation.setTotalPrice(pay);
                    reservation.setHours(hours);
                    reservation.setStatus("completed");
                    resRepo.update(reservation);
                    Locker locker = reservation.getLocker();
                    locker.setStatus("empty");
                    lockerRepo.update(locker);
                }
                return;
            }
        }
    }
    cout<<"reservation not found";
}