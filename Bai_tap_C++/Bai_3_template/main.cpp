/*
* File: main.c
* Author: Bui Minh Khoa
* Date: 27/09/2023
* Description: Template main file of 'Bai 3 C++'
*/

/* --------------------------------------------------------------- */ /* include Header Files */
#include <iostream>
#include <string>
#include <list>
/* --------------------------------------------------------------- */


/* --------------------------------------------------------------- */ /* define, declare or initial Namespace */
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
/* --------------------------------------------------------------- */


/* --------------------------------------------------------------- */ /* define Macro */

/* --------------------------------------------------------------- */


/* --------------------------------------------------------------- */ /* define Data Type */
enum type_HotelOption {
    EXIT_PROGRAM,
    ROOM,
    CUSTOMER,
    STAFF
};

enum type_RoomOption {
    EXIT_MANAGE_ROOM,
    SET_NUMBER_OF_ROOM,
    CLEAN_ROOM,
    BOOK_ROOM
};
/* --------------------------------------------------------------- */


/* --------------------------------------------------------------- */ /* define Function Definition*/

/* --------------------------------------------------------------- */


/* --------------------------------------------------------------- */ /* define Function Initialization */
/*
* Function: calculate_sum
* Description: This function calculates the sum of two integers
* Input:
*   a - an integer value
*   b - an integer value
* Output:
*   returns the sum of a and b
*/
/* --------------------------------------------------------------- */


/* --------------------------------------------------------------- */ /* define Class Definition */
class Room {
    private:
        int roomNumber;
        bool isBooked;
        bool isCleaned;
    public:
        Room();

        int getRoomNumber();

        bool isAvailable();
        void bookRoom();
        void checkOutRoom();

        bool canClean();
        void cleanRoom();
};

class RoomCustomerBooked : public Room{

};

class Person {
    private:
        string name;
        string phoneNumber;
    public:
        Person(string, string);

        void setName(string);
        void setPhoneNumber(string);

        string getName();
        string getPhoneNumber();
};

typedef struct {
    int hour;
    int minutes;
} type_Time;

typedef struct {
    int day;
    int month;
    int year;
} type_Date;

typedef enum {
    IN,
    OUT
} type_Status;

typedef struct {
    type_Time time;
    type_Date date;
    type_Status status;
} BookingHistory;


class Customer {
    private:
        string name;
        string phoneNumber;
        string address;
        int roomNumber;
        list<BookingHistory> bookingHistory;
    public:
        Customer(string, string, string, int);

        void setName(string name) {this->name = name;}
        void setPhoneNumber(string phoneNumber) {this->phoneNumber = phoneNumber;}
        void setAddress(string address) {this->address = address;}
        void setBookingHistory(list<BookingHistory> bookingHistory) {this->bookingHistory = bookingHistory;}

        string getName() {return this->name;}
        string getPhoneNumber() {return this->phoneNumber;}
        string getAddress() {return this->address;}
        int getRoomNumber() {return this->roomNumber;}
        list<BookingHistory>& getBookingHistory() {return this->bookingHistory;}
};

class CustomerManager {
    private:
        list<Customer> listCustomer;
    public:
        // thêm khách hàng (xong)
        void addCustomer(string, string, string, int);

        // in thông tin khách hàng (in được nhưng còn lỗi)
        void printListCustomer();

        // sửa khách hàng (xong)
        void updateCustomer(int);

        // xóa khách hàng
        void deleteCustomer(int);

        list<Customer> getListCustomer() {return this->listCustomer;}
};

class Staff : public Person {
    private:
        bool position;
        int dayWorking;
    public:
};

class Hotel {
    private:
        list<Room> listRoom;
        CustomerManager customer;
        list<Staff> listStaff;
    public:
        Hotel();

        list<Room>& getListRoom();
        void setListRoom(int);

        bool hasRoomToClean();
        void showListRoomCanClean();
        void cleanRoom(int);

        bool hasRoomToBook();
        void showListRoomCanBook();
        void bookRoom(int);

        CustomerManager& customerManager() {return this->customer;}
};

class Program {
    private:
        Hotel hotel;
    public:
        Program(Hotel);

        // Option 1
        void manageRoom();
            void setNumberOfRoom();
            void cleanRoom();
            void bookRoom();

        // Option 2
        void manageCustomer();

        // Option 3
        void manageEmployee();
            void accessManager();
            void accessStaff();

        // Support method
        
};
/* --------------------------------------------------------------- */


/* --------------------------------------------------------------- */ /* define Class Method Definition */
Customer::Customer(string name, string phoneNumber, string address, int roomNumber) {
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->address = address;
    this->roomNumber = roomNumber;

    static int hour = 6;
    static int minutes = 0;
    type_Time time;
    time.hour = hour;
    time.minutes = minutes;
    minutes += 20;
    if (minutes == 60) {
        hour++;
        minutes = 0;
    }
    if (hour == 24) {
        hour = 0;
        minutes = 0;
    }

    static int year = 2023;
    static int month = 1;
    static int day = 1;
    type_Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    day++;
    if (day == 30) {
        month++;
        day = 1;
    }
    if (month == 12) {
        year++;
        month = 1;
        day = 1;
    }

    type_Status status = IN;
    
    BookingHistory bookingHistory;
    bookingHistory.time = time;
    bookingHistory.date = date;
    bookingHistory.status = status;
    this->getBookingHistory().push_back(bookingHistory);
}

void CustomerManager::addCustomer(string name, string phoneNumber, string address, int roomNumber) {
    Customer customer(name, phoneNumber, address, roomNumber);
    this->listCustomer.push_back(customer);
}

void CustomerManager::printListCustomer() {
    cout << "- List of customer - \n" << endl;
    cout << "| No.\t| Name\t| Phone number\t| Address\t| Date\t\t| Time\t|" << endl;
    
    int num = 1;
    list<Customer>::iterator customer;
    for (customer = listCustomer.begin(); customer != listCustomer.end(); customer++) {

        bool thisCustomerInHotel = (customer->getBookingHistory().back().status == IN);

        if (thisCustomerInHotel) {
            string name = customer->getName();
            string phoneNumber = customer->getPhoneNumber();
            string address = customer->getAddress();
            type_Date date = customer->getBookingHistory().back().date;
            type_Time time = customer->getBookingHistory().back().time;

            cout << "| " << num << "\t| " << name << "\t| " << phoneNumber << "\t\t| " << address << "\t| ";
            cout << date.day << "/" << date.month << "/" << date.year << " | ";
            cout << time.hour << ":" << time.minutes << "\t|" << endl;

            num++;
        }
    }
}

void CustomerManager::updateCustomer(int roomNumber) {
    int key;
    string name;
    string phoneNumber;
    string address;

    list<Customer>::iterator customer = listCustomer.begin();
    int num = 1;

    while (customer != listCustomer.end()) {
        if (num == roomNumber) break;
        num++;
        customer++;
    }

    while(1) {
        name = customer->getName();
        phoneNumber = customer->getPhoneNumber();
        address = customer->getAddress();

        printBeginLine();
        cout << "[ CUSTOMER ]: update customer information\n" << endl;
        cout << "- Name\t\t: " << name << endl;
        cout << "- Phone number\t: " << phoneNumber << endl;
        cout << "- Address\t: " << address << endl;
        cout << endl;
        cout << "| 1: update name" << endl;
        cout << "| 2: update phone number" << endl;
        cout << "| 3: update address" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        
        if (key == 1) {
            printBeginLine();
            cout << "\nEnter new name: "; cin >> name;
            printEndLine();

            while(1) {
                printBeginLine();
                cout << "- Confirm to update name -\n" << endl;
                cout << "- Old name: " << customer->getName() << endl;
                cout << "- New name: " << name << endl;
                cout << endl;
                cout << "| 1: Yes" << endl;
                cout << "| 0: No" << endl;
                cout << "\nEnter: "; cin >> key;

                if (key == 1) {
                    customer->setName(name);
                    printBeginLine();
                    cout << "\n- Update name successfully -\n" << endl;
                    printEndLine();
                    break;
                }
                else if (key == 0) break;
                else printInvalidKey();
            }
            continue;
        }
        else if (key == 2) {
            printBeginLine();
            cout << "\nEnter new phone number: "; cin >> phoneNumber;
            printEndLine();

            while(1) {
                printBeginLine();
                cout << "- Confirm to update phone number -\n" << endl;
                cout << "- Old phone number: " << customer->getPhoneNumber() << endl;
                cout << "- New phone number: " << phoneNumber << endl;
                cout << endl;
                cout << "| 1: Yes" << endl;
                cout << "| 0: No" << endl;
                cout << "\nEnter: "; cin >> key;

                if (key == 1) {
                    customer->setPhoneNumber(phoneNumber);
                    printBeginLine();
                    cout << "\n- Update phone number successfully -\n" << endl;
                    printEndLine();
                    break;
                }
                else if (key == 0) break;
                else printInvalidKey();
            }
            continue;
        }
        else if (key == 3) {
            printBeginLine();
            cout << "\nEnter new address: "; cin >> address;
            printEndLine();

            while(1) {
                printBeginLine();
                cout << "- Confirm to update address -\n" << endl;
                cout << "- Old address: " << customer->getAddress() << endl;
                cout << "- New address: " << address << endl;
                cout << endl;
                cout << "| 1: Yes" << endl;
                cout << "| 0: No" << endl;
                cout << "\nEnter: "; cin >> key;

                if (key == 1) {
                    customer->setAddress(address);
                    printBeginLine();
                    cout << "\n- Update address successfully -\n" << endl;
                    printEndLine();
                    break;
                }
                else if (key == 0) break;
                else printInvalidKey();
            }
            continue;
        }
        else if (key == 0) {
            return;
        }
        else {
            printInvalidKey();
        }
    }
}

void CustomerManager::deleteCustomer(int roomNumber) {
    int key;
    string name;
    string phoneNumber;
    string address;

    list<Customer>::iterator customer = listCustomer.begin();
    int num = 1;

    while (customer != listCustomer.end()) {
        if (num == roomNumber) break;
        num++;
        customer++;
    }

    while(1) {
        name = customer->getName();
        phoneNumber = customer->getPhoneNumber();
        address = customer->getAddress();

        cout << "- Confirm to delete customer -\n" << endl;
        cout << "- Name\t\t: " << name << endl;
        cout << "- Phone number\t: " << phoneNumber << endl;
        cout << "- Address\t: " << address << endl;
        cout << endl;
        cout << "|1: Yes" << endl;
        cout << "|0: No" << endl;
        cout << "\nEnter: "; cin >> key;

        if (key == 0) return;
        else if (key == 1) {
            listCustomer.erase(customer);
            printBeginLine();
            cout << "\n- Delete customer successfully -\n" << endl;
            printEndLine();
            return;
        }
        else printInvalidKey();
    }
}

/* Constructor of class 'Room' */
Room::Room() {
    static int roomNumber = 1;
    this->roomNumber = roomNumber;
    this->isBooked = false;
    this->isCleaned = true;
    roomNumber++;
}

int Room::getRoomNumber() {
    return this->roomNumber;
}

bool Room::isAvailable() {
    return !isBooked && isCleaned;
}

void Room::bookRoom() {
    this->isBooked = true;
    this->isCleaned = false;
}

void Room::checkOutRoom() {
    this->isBooked = false;
}

bool Room::canClean() {
    if ((this->isCleaned == false) && (this->isBooked == false)) {
        return true;
    }
    return false;
}

void Room::cleanRoom() {
    int key;

    while(1) {
        printBeginLine();
        cout << "[ ROOM ]: clean room\n" << endl;
        cout << "# Confirm to clean room " << roomNumber << "\n" << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        bool error = (key < 0 && key > 1);
        bool chooseYes = (key == 1);

        if (error) {
            cout << "<ERROR>: Invalid key!" << endl;
            continue;
        }
        else if (chooseYes) {
            this->isCleaned = true;
            
            printBeginLine();
            cout << "- Clean room " << roomNumber << " successfully -" << endl;
            printEndLine();
            break;
        }
    }
}

Person::Person(string name, string phoneNumber) {
    this->name = name;
    this->phoneNumber = phoneNumber;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

string Person::getName() {
    return this->name;
}

string Person::getPhoneNumber() {
    return this->phoneNumber;
}

/* Constructor of class 'Hotel' */
Hotel::Hotel() {
}

list<Room>& Hotel::getListRoom() {
    return this->listRoom;
}

void Hotel::setListRoom(int numRoom) {
    int key;

    while(1) {
        printBeginLine();
        cout << "[ ROOM ]: set number of room\n" << endl;
        cout << "# Comfirm to set " << numRoom << " room to the hotel\n" << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine(); 

        bool noError = (key == 1 || key == 0);

        if (noError) break;
        else {
            cout << "<ERROR>: Invalid key!" << endl;
        }
    }
    
    bool chooseYes = (key == 1);

    if (chooseYes) {
        for (int i = 0; i < numRoom; i++) {
            Room room;
            this->listRoom.push_back(room);
        }
        
        printBeginLine();
        cout << "\n- Add room to the hotel successfully -\n" << endl;
        printEndLine();
    }
}

bool Hotel::hasRoomToClean() {
    for (list<Room>::iterator room = listRoom.begin(); room != listRoom.end(); room++) {
        if (room->canClean()) return true;
    }
    return false;
}

void Hotel::showListRoomCanClean() {
    cout << "- List of room can clean -" << endl;

    for (list<Room>::iterator room = listRoom.begin(); room != listRoom.end(); room++) {
        if (room->canClean()) {
            cout << "| " << room->getRoomNumber() << " ";
        }
    }
    cout << "|\n" << endl;
}

void Hotel::cleanRoom(int roomNumber) {
    list<Room>::iterator room;

    for (room = listRoom.begin(); room != listRoom.end(); room++) {
        if (room->getRoomNumber() == roomNumber) {
            room->cleanRoom();
            break;
        }
    }

    bool roomNotFound = (room == listRoom.end());

    if (roomNotFound) {
        printBeginLine();
        cout << "<ERROR>: Can't find this room" << endl;
        printEndLine();
    }
}

bool Hotel::hasRoomToBook() {
    for (list<Room>::iterator room = listRoom.begin(); room != listRoom.end(); room++) {
        if (room->isAvailable()) return true;
    }
    return false;
}

void Hotel::showListRoomCanBook() {
    cout << "- List of room can book -" << endl;

    for (list<Room>::iterator room = listRoom.begin(); room != listRoom.end(); room++) {
        if (room->isAvailable()) {
            cout << "| " << room->getRoomNumber() << " ";
        }
    }
    cout << "|\n" << endl;
}

void Hotel::bookRoom(int roomNumber) {
    int key;
    list<Room>::iterator room;
    string customerName;
    string customerPhoneNumber;
    string customerAddress;
    int customerRoomNumber;

    for (room = listRoom.begin(); room != listRoom.end(); room++) {
        if ((room->getRoomNumber() == roomNumber) && (room->isAvailable())) {
            break;
        }
    }

    bool roomNotFound = (room == listRoom.end());

    if (roomNotFound) {
        printBeginLine();
        cout << "<ERROR>: Can't find this room" << endl;
        printEndLine();
        return;
    }

    while(1) {
        printBeginLine();
        cout << "[ ROOM " << roomNumber << " ]: proceed to book room\n" << endl;

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
            cout << "- Room: " << roomNumber << endl;
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
            room->bookRoom();
            this->customer.addCustomer(customerName, customerPhoneNumber, customerAddress, roomNumber);

            printBeginLine();
            cout << "\n- Book room " << roomNumber << " successfully -\n" << endl;
            printEndLine();
            break;
        }
    }
}

// cài đặt constructor cho class customer ****

Program::Program(Hotel hotel){
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
            this->manageRoom();
        }
        else if (key == 2) {
            this->manageCustomer();
        }
        else if (key == 3) {
            this->manageEmployee();
        }
        else if (key == 0) {
            break;
        }
        else {
            printInvalidKey();
        }
    }
}

void Program::manageRoom() {
    int key;

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
        else if (key == 1) setNumberOfRoom();
        else if (key == 2) cleanRoom();
        else if (key == 3) bookRoom();
        else {
            cout << "<ERROR>: Invalid key!" << endl;
        }
    }
}

void Program::setNumberOfRoom() {
    int key;

    while(1) {
        printBeginLine();
        cout << "[ ROOM ]: set number of room\n" << endl;

        bool existListRoom = !hotel.getListRoom().empty();

        if (existListRoom) {
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
        else {
            hotel.setListRoom(key);
        }

        bool createdListOfRoom = !hotel.getListRoom().empty();

        if (createdListOfRoom) break;
    }
}

void Program::cleanRoom() {
    int key;

    while(1) {
        printBeginLine();
        cout << "[ ROOM ]: clean room\n" << endl;

        if (hotel.hasRoomToClean()) {
            hotel.showListRoomCanClean();
            cout << "| Enter a room number to clean" << endl;
        }
        else {
            cout << "# There is no room to clean\n" << endl;
        }
        
        cout << "| 0: Back" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        if (key == 0) break;
        else if (key < 0) {
            cout << "<ERROR>: Invalid key!" << endl;
        }
        else {
            hotel.cleanRoom(key);
        }
    }
}

void Program::bookRoom() {
    int key;

    while(1) {
        printBeginLine();
        cout << "[ ROOM ]: book room\n" << endl;

        if (hotel.hasRoomToBook()) {
            hotel.showListRoomCanBook();
            cout << "| Enter a room number to book" << endl;
        }
        else {
            cout << "# There is no room to book\n" << endl;
        }
        
        cout << "| 0: Back" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        bool error = (key < 0);
        bool back = (key == 0);

        if (error) {
            cout << "<ERROR>: Invalid key!" << endl;
        }
        else if (back) {
            break;
        }
        else {
            hotel.bookRoom(key);
        }
    }
}

void Program::manageCustomer() {
    int key;
    string name;
    string password;

    if (hotel.customerManager().getListCustomer().empty()) {
        while(1) {
            printBeginLine();
            cout << "[ CUSTOMER ]\n" << endl;
            cout << "# Hotel has no customer\n" << endl;
            cout << "| 0: Back" << endl;
            cout << "\nEnter: "; cin >> key;
            if (key != 0) printInvalidKey();
            else break;
        }
        return;
    }

    // dò xem có khớp với tài khoản quản lý hoặc lễ tân nào không
    // có thì tiếp tục, không thì thông báo và trở lại ban đầu
    while(1) {
        printBeginLine();
        cout << "[ CUSTOMER ]\n" << endl;
        cout << "| 1: Enter account" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        bool error = (key != 0) && (key != 1);

        if (error) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) break;
        // else
        printBeginLine();
        cout << "\nEnter account name: "; cin >> name;
        printEndLine();

        printBeginLine();
        cout << "\nEnter account password: "; cin >> password;
        printEndLine();

        bool nameInValid = false;        // cần sửa
        bool passwordInvalid = false;   // cần sửa

        if (nameInValid && passwordInvalid) {
            printBeginLine();
            cout << "<ERROR>: Account is invalid!" << endl;
            printEndLine();
        }
        else break;
    }

    while(1) {
        cout << "[ CUSTOMER ]: manage customer\n" << endl;
        hotel.customerManager().printListCustomer();
        cout << endl;
        cout << "| 1: update customer information" << endl;
        cout << "| 2: delete customer information" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key == 0) break;

        bool chooseUpdate = (key == 1);
        bool chooseDelete = (key == 2);

        if (!chooseUpdate && !chooseDelete) {
            printInvalidKey();
            continue;
        }

        printBeginLine();
        cout << "Enter number of customer: "; cin >> key;
        printEndLine();

        list<Customer>::iterator begin = hotel.customerManager().getListCustomer().begin();
        list<Customer>::iterator end = hotel.customerManager().getListCustomer().end();
        list<Customer>::iterator customer = begin;
        int customerNumber = 1;

        while (customer != end) {
            if (customerNumber == key) break;
            customerNumber++;
            customer++;
        }

        if (customer == end) {
            while(1) {
                printBeginLine();
                cout << "\n<ERROR>: Can't find this customer\n" << endl;
                cout << "| 0: Back" << endl;
                cout << "\nEnter: "; cin >> key;
                if (key == 0) break;
                else printInvalidKey();
            }
            continue;
        }

        if (chooseUpdate) hotel.customerManager().updateCustomer(customerNumber);
        else {
            int roomNumber = customer->getRoomNumber();

            hotel.customerManager().deleteCustomer(customerNumber);

            for (customer = begin; customer != end; customer++) {
                if (customer->getRoomNumber() == roomNumber) break;
            }

            if (customer != end) {
                for (list<Room>::iterator room = hotel.getListRoom().begin(); room != hotel.getListRoom().end(); room++) {
                    if (room->getRoomNumber() == roomNumber) {
                        room->checkOutRoom();
                    }
                }
            }
        }
    }
}

void Program::manageEmployee() {
    int key;

    while(1) {
        printBeginLine();
        cout << "- Access -\n" << endl;
        cout << "| 1: Manager" << endl;
        cout << "| 2: Staff" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();
        if (key < 0 || key > 2) {
            printInvalidKey();
        }
        else break;
    }

    if (key == 0) return;
    else if (key == 1) {
        accessManager();
    }
    else if (key == 2) {
        accessStaff();
    }
}

void Program::accessManager() {

}

void Program::accessStaff() {

}

/* --------------------------------------------------------------- */


/* --------------------------------------------------------------- */ /* run Program */
int main() {
    Hotel hotel;
    Program Hotel_Manager(hotel);

    return 0;
}