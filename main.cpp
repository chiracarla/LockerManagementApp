#include <iostream>
#include "Model/Locker.h"
#include "Repository/LockerRepository.h"
#include "Repository/ReservationRepository.h"
#include "Model/Reservation.h"
#include "Controller/Controller.h"

using namespace std;
void userMenu(Controller &controller) {
    while (true) {
        cout << "\n===== User Menu =====\n";
        cout << "1. View available lockers\n";
        cout << "2. Leave luggage\n";
        cout << "3. Pick up luggage\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            controller.freeLockers();
        } else if (choice == 2) {
            cout << "Enter locker size (1=SMALL, 2=MEDIUM, 3=LARGE): ";
            int sizeInput;
            cin >> sizeInput;
            Size size = (sizeInput == 1) ? SMALL : (sizeInput == 2) ? MEDIUM : LARGE;

            cout << "Enter phone number: ";
            string phone;
            cin >> phone;

            cout << "Set a temporary password: ";
            string password;
            cin >> password;

            cout << "Enter hours of storage (max 24): ";
            int hours;
            cin >> hours;

            time_t now = time(0);
            controller.leaveLuggage(size, phone, password, now, hours);
        } else if (choice == 3) {
            cout << "Enter phone number: ";
            string phone;
            cin >> phone;

            cout << "Enter password: ";
            string password;
            cin >> password;

            time_t now = time(0);
            controller.pickUpLuggage(now, phone, password);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

void managerMenu(Controller &controller) {
    while (true) {
        cout << "\n===== Manager Menu =====\n";
        cout << "1. Change locker prices\n";
        cout << "2. Set locker as out of order\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter new price for SMALL lockers: ";
            float smallPrice;
            cin >> smallPrice;

            cout << "Enter new price for MEDIUM lockers: ";
            float mediumPrice;
            cin >> mediumPrice;

            cout << "Enter new price for LARGE lockers: ";
            float largePrice;
            cin >> largePrice;

            controller.changePrice(smallPrice, mediumPrice, largePrice);
        }
//        else if (choice == 2) {
//            cout << "Enter locker ID to mark as out of order: ";
//            int lockerId;
//            cin >> lockerId;
//
//            cout << "Locker " << lockerId << " is now out of order." << endl;
//        }
        else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

int main() {

    LockerRepository lockerRepo;
    ReservationRepository resRepo(lockerRepo);
    Controller ctrl(lockerRepo, resRepo);
    while (true) {
        cout << "\n===== Welcome to Self-Service Luggage Storage =====\n";
        cout << "1. User\n";
        cout << "2. Manager\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            userMenu(ctrl);
        } else if (choice == 2) {
            managerMenu(ctrl);
        } else if (choice == 3) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
//3600 o ora
    return 0;
}

