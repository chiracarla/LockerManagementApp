

#ifndef LOCKERMANAGEMENTAPP_LOCKER_H
#define LOCKERMANAGEMENTAPP_LOCKER_H

#include<string>
#include <ostream>

using namespace std;

enum Size {
    SMALL, MEDIUM, LARGE
};

class Locker {
private:
    int lockerNumber;
    string location;
    enum Size size;
    int id;
    float price;
    string status;//busy/empty
public:
    Locker(int id, int lockerNumber, const string &location, Size size, float price, string status);

    const string &getStatus() const;

    void setStatus(const string &status);

    int getLockerNumber() const;

    void setLockerNumber(int lockerNumber);

    const string &getLocation() const;

    void setLocation(const string &location);

    Size getSize() const;

    void setSize(Size size);

    int getId() const;

    void setId(int id);

    float getPrice() const;

    void setPrice(float price);

    friend ostream &operator<<(ostream &os, const Locker &locker);

};


#endif //LOCKERMANAGEMENTAPP_LOCKER_H
