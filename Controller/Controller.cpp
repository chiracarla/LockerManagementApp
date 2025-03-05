
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
    for( auto & [ k,  v] : result){
        sort(v.begin(), v.end());
        cout<<lockerRepo.convertToString(k)<< " num "<<v.size()<<endl;
    }

}
