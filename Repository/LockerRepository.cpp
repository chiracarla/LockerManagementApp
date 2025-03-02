//
// Created by Carla Chira on 27.02.2025.
//

#include "LockerRepository.h"

ifstream fin("/Users/carlachira/CLionProjects/LockerManagementApp/lockers.csv");
ofstream fout("/Users/carlachira/CLionProjects/LockerManagementApp/lockers.csv", ios::app);

LockerRepository::LockerRepository(){
    readAll();
}

void LockerRepository::readAll() {
    vector<Locker> result;
    string firstLine;
    getline(fin, firstLine);

    vector<string> row;
    string line, word, temp;

    while (fin >> temp) {
        row.clear();
        stringstream s(temp);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        Locker newLocker(stoi(row[0]), stoi(row[1]), row[2], convertToSize(row[3]) ,stof(row[4]));
        lockers.insert({newLocker.getId(), newLocker});
    }
}

Size LockerRepository::convertToSize(std::string word) {
    if(word == "SMALL") return SMALL;
    else if(word == "MEDIUM") return MEDIUM;
    else if(word =="LARGE") return LARGE;
    else throw exception();
}

string LockerRepository::convertToString(Size size){
    if(size == SMALL) return "SMALL";
    else if(size == MEDIUM) return "MEDIUM";
    else if(size == LARGE) return "LARGE";
    else throw exception();
}

void LockerRepository::create(Locker newLocker) {
    lockers.insert({newLocker.getId(), newLocker});
    fout<<newLocker.getId()<<","<<newLocker.getLockerNumber()<<","<<newLocker.getLocation()<<","<<
                        convertToString(newLocker.getSize())<<","<<newLocker.getPrice()<<"\n";
}

Locker LockerRepository::read(int id){
    return lockers.at(id);
}

void LockerRepository::update(Locker updatedLocker) {
    ofstream f("/Users/carlachira/CLionProjects/LockerManagementApp/lockers.csv");
    lockers.erase(updatedLocker.getId());
    lockers.insert({updatedLocker.getId(), updatedLocker});
    f<<"Id,Number,Location,Size,Price\n";
    for(const auto &[k, v] : lockers){
        f<<v.getId()<<","<<v.getLockerNumber()<<","<<v.getLocation()<<","<<
            convertToString(v.getSize())<<","<<v.getPrice()<<"\n";
    }
}

void LockerRepository::del(int id) {
    ofstream f("/Users/carlachira/CLionProjects/LockerManagementApp/lockers.csv");
    lockers.erase(id);
    f<<"Id,Number,Location,Size,Price\n";
    for(const auto &[k, v] : lockers){
        f<<v.getId()<<","<<v.getLockerNumber()<<","<<v.getLocation()<<","<<
         convertToString(v.getSize())<<","<<v.getPrice()<<"\n";
    }
}

vector<Locker> LockerRepository::getAll() {
    vector<Locker> result;
    for(const auto &[k, v] : lockers){
        result.push_back(v);
    }
    return result;
}