

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
public:
    Locker(int id, int lockerNumber, const string &location, Size size, float price);

    Locker();

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
