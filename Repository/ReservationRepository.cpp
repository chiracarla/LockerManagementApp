#include "ReservationRepository.h"

ifstream rin("/Users/carlachira/CLionProjects/LockerManagementApp/reservations.csv");
ofstream rout("/Users/carlachira/CLionProjects/LockerManagementApp/reservations.csv", ios::app);


ReservationRepository::ReservationRepository(const LockerRepository &lockerRepo) : lockerRepo(lockerRepo) {
    readAll();
}

void ReservationRepository::readAll() {
    string firstLine;
    getline(rin, firstLine);

    vector<string> row;
    string line, word, temp;

    while (getline(rin, temp)) {
        row.clear();
        stringstream s(temp);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        string dateStr = row[1];
        tm tm = {};
        istringstream ss(dateStr);
        ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
        time_t time = mktime(&tm);
//        cout << "Parsed Time: " << std::ctime(&time);
        Reservation newRes(stoi(row[0]), time, stoi(row[2]), lockerRepo.read(stoi(row[3])), row[4], row[5], stoi(row[6]));
        reservations.insert({newRes.getId(), newRes});
    }
}

void ReservationRepository::create(Reservation newRes) {
    reservations.insert({newRes.getId(), newRes});
    time_t startTime = newRes.getStart();
    tm* localTime = localtime(&startTime);
    rout << newRes.getId() << "," <<1900 + localTime->tm_year<<"-"<<1 + localTime->tm_mon<<"-"
        << localTime->tm_mday<<" "<< localTime->tm_hour<<":"<<localTime->tm_min<<":"<< localTime->tm_sec
        << "," << newRes.getHours() << "," <<newRes.getLocker().getId() << "," << newRes.getPassword()
        <<","<<newRes.getPhoneNumber()<<","<<newRes.getTotalPrice() << "\n";
}

Reservation ReservationRepository::read(int id) {
    return reservations.at(id);
}

void ReservationRepository::update(Reservation updatedRes) {
    ofstream f("/Users/carlachira/CLionProjects/LockerManagementApp/reservations.csv");
    reservations.erase(updatedRes.getId());
    reservations.insert({updatedRes.getId(), updatedRes});
    f << "Id,Number,Location,Size,Price\n";
    for (const auto &[k, v]: reservations) {
        time_t startTime = v.getStart();
        tm* localTime = localtime(&startTime);
        f << v.getId() << "," <<1900 + localTime->tm_year<<"-"<<1 + localTime->tm_mon<<"-"
             << localTime->tm_mday<<" "<< localTime->tm_hour<<":"<<localTime->tm_min<<":"<< localTime->tm_sec
             << "," << v.getHours() << "," <<v.getLocker().getId() << "," << v.getPassword()
             <<","<<v.getPhoneNumber()<<","<<v.getTotalPrice() << "\n";
    }
}

void ReservationRepository::del(int id) {
    ofstream f("/Users/carlachira/CLionProjects/LockerManagementApp/reservations.csv");
    reservations.erase(id);
    f << "Id,Number,Location,Size,Price\n";
    for (const auto &[k, v]: reservations) {
        time_t startTime = v.getStart();
        tm* localTime = localtime(&startTime);
        f << v.getId() << "," <<1900 + localTime->tm_year<<"-"<<1 + localTime->tm_mon<<"-"
          << localTime->tm_mday<<" "<< localTime->tm_hour<<":"<<localTime->tm_min<<":"<< localTime->tm_sec
          << "," << v.getHours() << "," <<v.getLocker().getId() << "," << v.getPassword()
          <<","<<v.getPhoneNumber()<<","<<v.getTotalPrice() << "\n";
    }
}

vector<Reservation> ReservationRepository::getAll() {
    vector<Reservation> result;
    for (const auto &[k, v]: reservations) {
        result.push_back(v);
    }
    return result;
}