#include <iostream>
#include <string>
#include <list>
using namespace std;

void printBeginLine() {
    cout << endl;
    cout << "---------------------------------------" << endl;
}

void printEndLine() {
    cout << "---------------------------------------" << endl;
}

int enterKey() {
    int key;
    cout << "\nEnter: ";
    cin >> key;
    return key;
}

void printInvalidKey() {
    printBeginLine();
    cout << "<ERROR>: Invalid key!" << endl;
    printEndLine();
}

/* Room *------------------------------------------------------------------------------------------------------------------*/

class Room {
    private:
        int roomNumber;
        bool bookedStatus;
        bool cleanedStatus;
    public:
        Room() {
            static int number = 1;
            this->roomNumber = number;
            number++;

            bookedStatus = false;
            cleanedStatus = true;
        }

        int getRoomNumber() {return this->roomNumber;}
        bool getBookedStatus() {return this->bookedStatus;}
        bool getCleanedStatus() {return this->cleanedStatus;}

        void setRoomNumber(int number) {this->roomNumber = number;}
        void setBookedStatus(bool status) {this->bookedStatus = status;}
        void setCleanedStatus(bool status) {this->cleanedStatus = status;}
};

class RoomManager {
    private:
        list<Room> listRoom;
    public:
        // clean room
        bool canClean(list<Room>::iterator);
        void cleanRoom(list<Room>::iterator);
        bool hasRoomToClean(list<Room>);
        void showListRoomCanClean();
        list<Room>::iterator findRoomToClean(int);

        // book room
        bool hasRoomToBook(list<Room>);
        bool isAvailable(list<Room>::iterator);
        void showListRoomCanBook();
        list<Room>::iterator findRoomToBook(int);
        void bookRoom(list<Room>::iterator);
        void checkoutRoom(Room);
        

        // manage room
        RoomManager(list<Room>& listRoom);
        void setRoom(list<Room>& listRoom);
        void cleanRoom(list<Room>& listRoom);
        void bookRoom(list<Room>& listRoom);

};

bool RoomManager::isAvailable(list<Room>::iterator room) {
    return !room->getBookedStatus() && room->getCleanedStatus();
}

void RoomManager::bookRoom(list<Room>::iterator room) {
    room->setBookedStatus(true);
    room->setCleanedStatus(false);
}

void RoomManager::checkoutRoom(Room room) {
    room.setBookedStatus(false);
}

void RoomManager::showListRoomCanClean() {
    cout << "- List of room can clean -" << endl;

    for (list<Room>::iterator room = listRoom.begin(); room != listRoom.end(); room++) {
        if (canClean(room) == true) {
            cout << "| " << room->getRoomNumber() << " ";
        }
    }
    cout << "|\n" << endl;
}

bool RoomManager::canClean(list<Room>::iterator room) {
    return !room->getCleanedStatus();
}

void RoomManager::cleanRoom(list<Room>::iterator room) {
    room->setCleanedStatus(true);
}

RoomManager::RoomManager(list<Room>& listRoom) {
    int key;
    this->listRoom = listRoom;

    while(1) {
        printBeginLine();
        cout << "[ HOTEL ]: Room\n" << endl;
        cout << "| 1: set number of room" << endl;
        cout << "| 2: clean room" << endl;
        cout << "| 3: book room" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        if (key == 0) break;
        else if (key == 1) setRoom(listRoom);
        else if (key == 2) cleanRoom(listRoom);
        else if (key == 3) bookRoom(listRoom);
        else {
            cout << "<ERROR>: Invalid key!" << endl;
        }
    }
}

void RoomManager::setRoom(list<Room>& listRoom) {
    int key;

    while(1) {
        printBeginLine();
        cout << "[ ROOM ]: set number of room\n" << endl;

        if (!listRoom.empty()) {
            cout << "# Already have room in the hotel." << endl;
            break;
        }
        else {
            cout << "| Enter number of room you want in the hotel" << endl;
        }

        cout << "| 0: Back" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        bool error = (key < 0);
        bool back = (key == 0);

        if (error) {
            cout << "<ERROR>: Invalid key!" << endl;
            continue;
        }
        else if (back) {
            break;
        }

        int numberRoom = key;
        
        while(1) {
            printBeginLine();
            cout << "[ ROOM ]: set number of room\n" << endl;
            cout << "# Comfirm to set " << numberRoom << " room to the hotel\n" << endl;
            cout << "| 1: Yes" << endl;
            cout << "| 0: No" << endl;
            cout << "\nEnter: ";
            cin >> key;
            printEndLine(); 

            bool noError = (key == 1 || key == 0);

            if (noError) break;
            
            printInvalidKey();
        }

        bool chooseYes = (key == 1);

        if (chooseYes) {
            for (int i = 0; i < numberRoom; i++) {
                Room room;
                listRoom.push_back(room);
            }
            
            printBeginLine();
            cout << "\n- Add room to the hotel successfully -\n" << endl;
            cout << "Enter any key to return: "; cin >> key;
            printEndLine();
        }

        if (!listRoom.empty()) break;
    }
}

bool RoomManager::hasRoomToClean(list<Room> listRoom) {
    for (list<Room>::iterator room = listRoom.begin(); room != listRoom.end(); room++) {
        if (canClean(room) == true) return true;
    }
    return false;
}

list<Room>::iterator RoomManager::findRoomToClean(int roomNumber) {
    list<Room>::iterator room = listRoom.begin();

    while (room != listRoom.end()) {
        if (room->getRoomNumber() == roomNumber && room->getCleanedStatus() == false) {
            return room;
        }
        room++;
    }
    return room;
}

void RoomManager::cleanRoom(list<Room>& listRoom) {
    int key;

    if (hasRoomToClean(listRoom) == false) {
        printBeginLine();
        cout << "[ ROOM ]: clean room\n" << endl;
        cout << "# There is no room to clean\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while(1) {
        printBeginLine();
        cout << "[ ROOM ]: clean room\n" << endl;
        showListRoomCanClean();
        cout << "| Enter a room number to clean" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();
        
        if (key < 0 ) {
            printInvalidKey();
        }
        else break;
    }

    if (key == 0) return;

    list<Room>::iterator room;

    room = findRoomToBook(key);

    if (room == listRoom.end()) {
        printBeginLine();
        cout << "<ERROR>: Can't find this room\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while(1) {
        printBeginLine();
        cout << "[ ROOM ]: clean room\n" << endl;
        cout << "# Confirm to clean room " << room->getRoomNumber() << "\n" << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        if (key != 0 && key != 1) {
            printInvalidKey();
            continue;
        }
        else break;
    }

    bool chooseYes = (key == 1);

    if (chooseYes) {
        printBeginLine();
        cout << "- Clean room " << room->getRoomNumber() << " successfully -" << endl;
        printEndLine();

        cleanRoom(room);
    }
}

bool RoomManager::hasRoomToBook(list<Room> listRoom) {
    for (list<Room>::iterator room = listRoom.begin(); room != listRoom.end(); room++) {
        if (isAvailable(room) == true) return true;
    }
    return false;
}

void RoomManager::showListRoomCanBook() {
    cout << "- List of room can book -" << endl;

    for (list<Room>::iterator room = listRoom.begin(); room != listRoom.end(); room++) {
        if (isAvailable(room) == true) {
            cout << "| " << room->getRoomNumber() << " ";
        }
    }
    cout << "|\n" << endl;
}

list<Room>::iterator RoomManager::findRoomToBook(int roomNumber) {
    list<Room>::iterator room = listRoom.begin();
    while (room != listRoom.end()) {
        if (room->getRoomNumber() == roomNumber) return room;
        room++;
    }
    return room;
}

void RoomManager::bookRoom(list<Room>& listRoom) {
    int key;
    list<Room>::iterator room;
    string customerName;
    string customerPhoneNumber;
    string customerAddress;
    int customerRoomNumber;

    if (hasRoomToBook(listRoom) == false) {
        printBeginLine();
        cout << "[ ROOM ]: book room\n" << endl;
        cout << "# There is no room to book\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while(1) {
        while(1) {
            printBeginLine();
            cout << "[ ROOM ]: book room\n" << endl;
            showListRoomCanBook();
            cout << "| Enter a room number to book" << endl;
            cout << "| 0: Back" << endl;
            cout << "\nEnter: "; cin >> key;
            printEndLine();

            bool error = (key < 0);
            bool back = (key == 0);

            if (error) {
                printInvalidKey();
            }
            else if (back) {
                return;
            }
            else {
                room = findRoomToBook(key);

                if (room == listRoom.end()) {
                    printBeginLine();
                    cout << "<ERROR>: Can't find this room\n" << endl;
                    cout << "Enter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else break;
            }
        }

        while(1) {
            printBeginLine();
            cout << "[ ROOM " << room->getRoomNumber() << " ]: proceed to book room\n" << endl;

            cout << "- Customer name\t\t: ";
            if (customerName.empty()) {
                cout << "(empty)" << endl;
            } else {
                cout << customerName << endl;
            }

            cout << "- Customer phone number\t: ";
            if (customerPhoneNumber.empty()) {
                cout << "(empty)" << endl;
            } else {
                cout << customerPhoneNumber << endl;
            }

            cout << "- Customer address\t: ";
            if (customerAddress.empty()) {
                cout << "(empty)" << endl;
            } else {
                cout << customerAddress << endl;
            }

            cout << endl;
            cout << "| 1: Enter name of customer" << endl;
            cout << "| 2: Enter phone number of customer" << endl;
            cout << "| 3: Enter address of customer" << endl;
            cout << "| 4: Confirm booking this room" << endl;
            cout << "| 0: Back" << endl;
            cout << "\nEnter: ";
            cin >> key;
            printEndLine();

            bool errorKey = (key < 0) && (key > 4);

            if (errorKey) {
                cout << "<ERROR>: Invalid key!" << endl;
                continue;
            }
            else {
                if (key == 0) {
                    break;
                }
                else if (key == 1) {
                    printBeginLine();
                    cout << "\nEnter name: ";
                    cin >> customerName;
                    printEndLine();
                    continue;
                }
                else if (key == 2) {
                    printBeginLine();
                    cout << "\nEnter phone number: ";
                    cin >> customerPhoneNumber;
                    printEndLine();
                    continue;
                }
                else if (key == 3) {
                    printBeginLine();
                    cout << "\nEnter address: ";
                    cin >> customerAddress;
                    printEndLine();
                    continue;
                }
            }

            // key = 4: continue this loop of function
            bool errorName = (customerName.size() == 0);
            bool errorPhoneNumber = (customerPhoneNumber.size() == 0);
            bool errorAddress = (customerAddress.size() == 0);

            if (errorName || errorPhoneNumber || errorAddress) {
                if (errorName) {
                    cout << "<ERROR>: Haven't entered name of customer" << endl;
                }
                if (errorPhoneNumber) {
                    cout << "<ERROR>: Haven't entered phone number of customer" << endl;
                }
                if (errorAddress) {
                    cout << "<ERROR>: Haven't entered address of customer" << endl;
                }
                continue;
            }

            while(1) {
                printBeginLine();
                cout << "- Confirm to book -\n" << endl;
                cout << "- Room: " << room->getRoomNumber() << endl;
                cout << "- Customer information:" << endl;
                cout << "Name\t\t: " << customerName << endl;
                cout << "Phone number\t: " << customerPhoneNumber << endl;
                cout << "Address\t\t: " << customerAddress << endl;
                cout << endl;
                cout << "| 1: Yes" << endl;
                cout << "| 0: No" << endl;
                cout << "\nEnter: ";
                cin >> key;
                printEndLine();

                errorKey = (key < 0) && (key > 1);

                if (errorKey) {
                    cout << "<ERROR>: Invalid key!" << endl;
                    continue;
                }
                else break;
            }
            
            if (key == 1) {
                bookRoom(room);
                // this->customer.addCustomer(customerName, customerPhoneNumber, customerAddress, room->getRoomNumber());

                printBeginLine();
                cout << "\n- Book room " << room->getRoomNumber() << " successfully -\n" << endl;
                printEndLine();
                break;
            }
        }
    }
}

/* Hotel *-------------------------------------------------------------------------------------------------------------------------------*/

class Hotel {
    private:
        // room
        list<Room> listRoom;

        // customer
        // employee
    public:
        list<Room> getListRoom() {return this->listRoom;}
        void setListRoom(list<Room> listRoom) {this->listRoom = listRoom;}
};

class HotelManager {
    public:
        Hotel hotel;

        HotelManager(Hotel);
};

HotelManager::HotelManager(Hotel hotel) {
    this->hotel = hotel;
    int key;

    while(1) {
        printBeginLine();
        cout << "--- WELCOME TO HOTEL ---\n" << endl;
        cout << "| 1: Room" << endl;
        cout << "| 2: Customer" << endl;
        cout << "| 3: Employee" << endl;
        cout << "| 0: Exit program" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        if (key == 1) {
            list<Room> listRoom;
            listRoom = hotel.getListRoom();
            RoomManager roomManager(listRoom);
            hotel.setListRoom(listRoom);
        }
        else if (key == 2) {
            cout << "manage customer" << endl;
            cin >> key;
        }
        else if (key == 3) {
            cout << "manage employee" << endl;
            cin >> key;
        }
        else if (key == 0) {
            break;
        }
        else {
            printInvalidKey();
        }
    }
}

/* Main*-------------------------------------------------------------------------------------------------------------------------------------*/

int main() {
    Hotel myHotel;
    HotelManager hotelManager(myHotel);

    return 0;
}