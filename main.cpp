#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Room {
private:
    int roomNumber;
    int capacity;
    bool isOccupied;
    string guestName;

public:
    Room(int roomNumber, int capacity) {
        this->roomNumber = roomNumber;
        this->capacity = capacity;
        this->isOccupied = false;
        this->guestName = "";
    }

    int getRoomNumber() {
        return this->roomNumber;
    }

    int getCapacity() {
        return this->capacity;
    }

    bool getIsOccupied() {
        return this->isOccupied;
    }

    string getGuestName() {
        return this->guestName;
    }

    void setIsOccupied(bool isOccupied) {
        this->isOccupied = isOccupied;
    }

    void setGuestName(string guestName) {
        this->guestName = guestName;
    }
};

class Hotel {
private:
    vector<Room*> rooms;

public:
    Hotel(int numberOfRooms) {
        for (int i = 1; i <= numberOfRooms; i++) {
            rooms.push_back(new Room(i, 2)); // initialize all rooms with capacity of 2
        }
    }

    void bookRoom(int roomNumber, string guestName) {
        Room* room = rooms[roomNumber - 1];

        if (room->getIsOccupied()) {
            cout << "Room " << roomNumber << " is already occupied." << endl;
        } else {
            room->setIsOccupied(true);
            room->setGuestName(guestName);
            cout << "Room " << roomNumber << " has been booked for " << guestName << "." << endl;
        }
    }

    void cancelBooking(int roomNumber) {
        Room* room = rooms[roomNumber - 1];

        if (room->getIsOccupied()) {
            room->setIsOccupied(false);
            room->setGuestName("");
            cout << "Booking for room " << roomNumber << " has been cancelled." << endl;
        } else {
            cout << "Room " << roomNumber << " is not currently booked." << endl;
        }
    }

    void displayAvailableRooms() {
        cout << "Available rooms:" << endl;

        for (Room* room : rooms) {
            if (!room->getIsOccupied()) {
                cout << "Room " << room->getRoomNumber() << " (Capacity: " << room->getCapacity() << ")" << endl;
            }
        }
    }

    void displayOccupiedRooms() {
        cout << "Occupied rooms:" << endl;

        for (Room* room : rooms) {
            if (room->getIsOccupied()) {
                cout << "Room " << room->getRoomNumber() << " (Capacity: " << room->getCapacity() << ")" << endl;
                cout << "Guest Name: " << room->getGuestName() << endl;
            }
        }
    }
};

int main() {
    Hotel hotel(10); // create a hotel with 10 rooms

    int choice;
    int roomNumber;
    string guestName;

    do {
        cout << "Hotel Management System" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Book a room" << endl;
        cout << "2. Cancel booking" << endl;
        cout << "3. Display available rooms" << endl;
        cout << "4. Display occupied rooms" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter room number: ";
                cin >> roomNumber;
                cout << "Enter guest name: ";
                cin >> guestName;
                hotel.bookRoom(roomNumber, guestName);
                break;
            case 2:
                cout << "Enter room number: ";
                cin >> roomNumber;
                hotel.cancelBooking(roomNumber);
                break;
            case 3:
                hotel.displayAvailableRooms();
                break;
            case 4:
                hotel.displayOccupiedRooms();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}