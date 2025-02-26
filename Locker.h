

#ifndef LOCKERMANAGEMENTAPP_LOCKER_H
#define LOCKERMANAGEMENTAPP_LOCKER_H

#include<string>
#include <ostream>

using namespace std;

enum Size{SMALL, MEDIUM, LARGE};

class Locker {
private:
    int lockerNumber;
    string location;
    enum Size size;
public:
    Locker(int lockerNumber, const string &location, Size size);

    int getLockerNumber() const;

    void setLockerNumber(int lockerNumber);

    const string &getLocation() const;

    void setLocation(const string &location);

    Size getSize() const;

    void setSize(Size size);

    friend ostream &operator<<(ostream &os, const Locker &locker);

};


#endif //LOCKERMANAGEMENTAPP_LOCKER_H
