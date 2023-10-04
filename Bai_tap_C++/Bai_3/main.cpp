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
    int key;
    printBeginLine();
    cout << "<ERROR>: Invalid key!\n" << endl;
    cout << "Enter any number to return: "; cin >> key;
    printEndLine();
}

/* Room * --------------------------------------------------------------------------- */

class Room {
    private:
        int roomNumber;
        bool isBooked;
        bool isCleaned;
    public:
        Room() {
            static int roomNumber = 1;
            this->roomNumber = roomNumber;
            this->isBooked = false;
            this->isCleaned = true;
            roomNumber++;
        }

        int getRoomNumber() {return this->roomNumber;}

        bool isAvailable() {return !isBooked && isCleaned;}
        void bookRoom() {
            this->isBooked = true;
            this->isCleaned = false;
        }

        bool canCheckOut() {return this->isBooked;}
        void checkOutRoom() {this->isBooked = false;}

        bool canClean() {return !this->isBooked && !this->isCleaned;}
        void cleanRoom() {this->isCleaned = true;}
};

/* Customer * ----------------------------------------------------------------------- */

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
        Customer() {};

        void setName(string name) {this->name = name;}
        void setPhoneNumber(string phoneNumber) {this->phoneNumber = phoneNumber;}
        void setAddress(string address) {this->address = address;}
        void setRoomNumber(int roomNumber) {this->roomNumber = roomNumber;}
        void setBookingHistory(list<BookingHistory> bookingHistory) {this->bookingHistory = bookingHistory;}

        string getName() {return this->name;}
        string getPhoneNumber() {return this->phoneNumber;}
        string getAddress() {return this->address;}
        int getRoomNumber() {return this->roomNumber;}
        list<BookingHistory>& getBookingHistory() {return this->bookingHistory;}
};

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

/* Employee * ----------------------------------------------------------------------- */

typedef enum {
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LUGGAGE_STAFF,
    GARDENER
} type_JobPosition;

typedef struct {
    type_Time startTime;
    type_Time endTime;
} Schedule;

class Employee {
    private:
        string name;
        string phoneNumber;
        type_JobPosition jobPosition;
        Schedule schedule;
    public:
        Employee(string name, string phoneNumber, type_JobPosition jobPosition, Schedule schedule) {
            this->name = name;
            this->phoneNumber = phoneNumber;
            this->jobPosition = jobPosition;
            this->schedule = schedule;
        }

        void setName(string name) {this->name = name;};
        void setPhoneNumber(string phoneNumber) {this->phoneNumber = phoneNumber;}
        void setJobPosition(type_JobPosition jobPosition) {this->jobPosition = jobPosition;}
        void setSchedule(Schedule schedule) {this->schedule = schedule;}

        string getName() {return this->name;}
        string getPhoneNumber() {return this->phoneNumber;}
        type_JobPosition getJobPosition() {return this->jobPosition;}
        Schedule getSchedule() {return this->schedule;}
};

/* Services * ----------------------------------------------------------------------- */

typedef struct {
    bool restaurant = false;
    bool bar = false;
    bool swimmingPool = false;
    bool gym = false;
    bool parking = false;
} Services;

/* Payment * ------------------------------------------------------------------------ */

class PayHistory {
    private:
        int totalBill;
        Customer customer;
    public:
        void setTotalBill(int totalBill) {this->totalBill = totalBill;}
        void setCustomer(Customer customer) {this->customer = customer;}

        int getTotalBill() {return this->totalBill;}
        Customer getCustomer() {return this->customer;}
};

/* Security Management * ------------------------------------------------------------ */

class User {
    private:
        int id;
        string userName;
        string password;
    public:
        User(string userName, string password) {
            static int id = 1;
            this->id = id;
            id++;
            this->userName = userName;
            this->password = password;
        }

        void setUserName(string userName) {this->userName = userName;}
        void setPassword(string password) {this->password = password;}

        int getID() {return this->id;}
        string getUserName() {return this->userName;}
        string getPassword() {return this->password;}
};

class SecurityManagement {
    private:
        User manager = {"manager", "admin"};
        list<User> listUser;
    public:
        SecurityManagement() {
            // manager("manager", "admin");
        }

        string getManagerUserName() {return this->manager.getUserName();}
        string getManagerPassword() {return this->manager.getPassword();}

        // void addUser(string userName, string password);
        // void eraseUser(string userName);
        // void editUser(string userName, string password);
        void setMPasswordManager(string password) {manager.setPassword(password);}

        bool checkManager(string name, string password) {
            if (name == manager.getUserName() && password == manager.getPassword()) return true;
            return false;
        }

        list<User>& getListUser() {return this->listUser;}
};

/* Hotel * -------------------------------------------------------------------------- */

class Hotel {
    private:
        list<Room> listRoom;
        list<Customer> listCustomer;
        list<Employee> listEmployee;
        Services services;
        list<PayHistory> payHistory;
        SecurityManagement securityManagement;
    public:
        list<Room>& getListRoom() {return this->listRoom;}
        list<Customer>& getListCustomer() {return this->listCustomer;}
        list<Employee>& getListEmployee() {return this->listEmployee;}
        Services& getServices() {return this->services;}
        list<PayHistory>& getPayHistory() {return this->payHistory;}
        SecurityManagement& getSecurityManagement() {return this->securityManagement;}
};


/* Hotel Manager * ------------------------------------------------------------------ */

class HotelManager {
    private:
        Hotel hotel;
    public:
        HotelManager(Hotel hotel);

        void manageRoom();
            void setRoom();

            bool noRoomToClean();
            void showRoomCanClean();
            list<Room>::iterator findRoomToClean(int);
            void cleanRoom();

            bool noRoomToBook();
            void showRoomCanBook();
            list<Room>::iterator findRoomToBook(int);
            void bookRoom();

        void manageCustomer();
            void showCustomer();

            list<Customer>::iterator findCustomer(int);
            void updateCustomer(list<Customer>::iterator);
                void updateName(list<Customer>::iterator, string);
                void updatePhoneNumber(list<Customer>::iterator, string);
                void updateAddress(list<Customer>::iterator, string);

            void deleteCustomer(list<Customer>::iterator);

        void manageEmployee();
            void accessManager();
                void printJob(type_JobPosition);
                void showEmployee();
                void printListJobPosition(type_JobPosition);

                void updateEmployee();
                    void updateName(list<Employee>::iterator);
                    void updatePhoneNumber(list<Employee>::iterator);
                    void updateJobPosition(list<Employee>::iterator);
                    void updateStartTime(list<Employee>::iterator);
                    void updateEndTime(list<Employee>::iterator);

                void deleteEmployee();

                void addEmployee();

            void accessStaff();

        void manageServices();
            void showServices();
            void addServices();
                bool hasNoServicesToAdd();
            void deleteService();
                bool hasNoServicesToDelete();

        void managePayment();
            void showRoomCanCheckOut();

        void manageSecurity();

};

HotelManager::HotelManager(Hotel hotel) {
    this->hotel = hotel;
    int key;

    while(1) {
        printBeginLine();
        cout << "--- WELCOME TO HOTEL ---\n" << endl;
        cout << "| 1: room" << endl;
        cout << "| 2: customer" << endl;
        cout << "| 3: employee" << endl;
        cout << "| 4: services" << endl;
        cout << "| 5: payment" << endl;
        cout << "| 6: access security" << endl;
        cout << "| 7: report and statistics" << endl;
        cout << "| 8: feedback and evaluate" << endl;
        cout << "| 0: Exit" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        switch (key) {
        case 1:
            manageRoom();
            break;;
        case 2:
            manageCustomer();
            break;
        case 3:
            manageEmployee();
            break;
        case 4:
            manageServices();
            break;
        case 5:
            managePayment();
            break;
        case 6:
            manageSecurity();
            break;
        case 7:
            cout << "report and statistics\n";
            cin >> key;
            break;
        case 8:
            cout << "feedback and evaluate\n";
            cin >> key;
            break;
        case 0:
            return;
        default:
            printInvalidKey();
            break;
        }
    }
}

void HotelManager::manageRoom() {
    int key;

    while(1) {
        printBeginLine();
        cout << "[ HOTEL ]: Room\n" << endl;
        cout << "| 1: set room" << endl;
        cout << "| 2: clean room" << endl;
        cout << "| 3: book room" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        if (key == 0) break;
        else if (key == 1) setRoom();
        else if (key == 2) cleanRoom();
        else if (key == 3) bookRoom();
        else {
            printInvalidKey();
        }
    }
}

void HotelManager::setRoom() {
    int key;

    if (!hotel.getListRoom().empty()) {
        printBeginLine();
        cout << "[ ROOM ]: set room\n" << endl;
        cout << "# Already have room in the hotel.\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while(1) {
        printBeginLine();
        cout << "[ ROOM ]: set room\n" << endl;
        cout << "| Enter number of room you want in the hotel" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        if (key < 0) {
            printInvalidKey();
            continue;
        }
        if (key == 0) return;

        int numberOfRoom = key;

        while(1) {
            printBeginLine();
            cout << "- Comfirm to set " << numberOfRoom << " room to the hotel -\n" << endl;
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

        if (key == 0) continue;
        
        for (int i = 0; i < numberOfRoom; i++) {
            Room newRoom;
            hotel.getListRoom().push_back(newRoom);
        }

        printBeginLine();
        cout << "\n- Add " << numberOfRoom << " room to the hotel successfully -\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }
}

bool HotelManager::noRoomToClean() {
    list<Room>::iterator room = hotel.getListRoom().begin();
    while (room != hotel.getListRoom().end()) {
        if (room->canClean()) return false;
        room++;
    }
    return true;
}

void HotelManager::showRoomCanClean() {
    cout << "- List of room can clean -" << endl;

    for (list<Room>::iterator room = hotel.getListRoom().begin(); room != hotel.getListRoom().end(); room++) {
        if (room->canClean()) {
            cout << "| " << room->getRoomNumber() << " ";
        }
    }
    cout << "|\n" << endl;
}

list<Room>::iterator HotelManager::findRoomToClean(int roomNumber) {
    list<Room>::iterator room = hotel.getListRoom().begin();
    while (room != hotel.getListRoom().end()) {
        if (room->getRoomNumber() == roomNumber && room->canClean()) return room;
        room++;
    }
    return room;
}

void HotelManager::cleanRoom() {
    int key;

    if (noRoomToClean()) {
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
        showRoomCanClean();
        cout << "| Enter a room number to clean" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: ";
        cin >> key;
        printEndLine();

        if (key < 0) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;

        list<Room>::iterator room = findRoomToClean(key);

        if (room == hotel.getListRoom().end()) {
            printBeginLine();
            cout << "[ERROR]: Can't find this room\n" << endl;
            cout << "Enter any number to return: "; cin >> key;
            printEndLine();
            continue; 
        }

        while(1) {
            printBeginLine();
            cout << "- Confirm to clean this room -\n" << endl;
            cout << "| 1: Yes" << endl;
            cout << "| 0: No" << endl;
            cout << "\nEnter: "; cin >> key;
            printEndLine();

            if (key != 0 && key != 1) {
                printInvalidKey();
            }
            else break;
        }

        if (key == 0) return;

        printBeginLine();
        cout << "- Clean room " << room->getRoomNumber() << " successfully -\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
    }
}

bool HotelManager::noRoomToBook() {
    list<Room>::iterator room = hotel.getListRoom().begin();
    while (room != hotel.getListRoom().end()) {
        if (room->isAvailable()) return false;
    }
    return true;
}

void HotelManager::showRoomCanBook() {
    cout << "- List of room can book -" << endl;

    for (list<Room>::iterator room = hotel.getListRoom().begin(); room != hotel.getListRoom().end(); room++) {
        if (room->isAvailable()) {
            cout << "| " << room->getRoomNumber() << " ";
        }
    }
    cout << "|\n" << endl;
}

list<Room>::iterator HotelManager::findRoomToBook(int roomNumber) {
    list<Room>::iterator room = hotel.getListRoom().begin();
    while (room != hotel.getListRoom().end()) {
        if (room->getRoomNumber() == roomNumber && room->isAvailable()) return room;
        room++;
    }
    return room;
}

void HotelManager::bookRoom() {
    int key;
    string customerName;
    string customerPhoneNumber;
    string customerAddress;
    int customerRoomNumber;

    if (noRoomToBook()) {
        printBeginLine();
        cout << "[ ROOM ]: book room\n" << endl;
        cout << "# There is no room to book\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while(1) {
        printBeginLine();
        cout << "[ ROOM ]: book room\n" << endl;
        showRoomCanBook();
        cout << "| Enter a room number to book" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key < 0) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;

        list<Room>::iterator room = findRoomToBook(key);

        if (room == hotel.getListRoom().end()) {
            printBeginLine();
            cout << "[ERROR]: Can't find this room\n" << endl;
            cout << "Enter any number to return: "; cin >> key;
            printEndLine();
            continue; 
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
            cout << "\nEnter: "; cin >> key;
            printEndLine();

            bool errorKey = (key < 0) && (key > 4);

            if (errorKey) {
                printInvalidKey();
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
                cout << "\nEnter any number to return: "; cin >> key;
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
                cout << "\nEnter: "; cin >> key;
                printEndLine();

                if (key != 0 && key != 1) {
                    printInvalidKey();
                    continue;
                }
                else break;
            }
            
            if (key == 1) {
                room->bookRoom();
                Customer newCustomer(customerName, customerPhoneNumber, customerAddress, room->getRoomNumber());
                hotel.getListCustomer().push_back(newCustomer);

                printBeginLine();
                cout << "\n- Book room " << room->getRoomNumber() << " successfully -\n" << endl;
                printEndLine();
                break;
            }
        }
    }
}

void HotelManager::showCustomer() {
    cout << "- List of customer - \n" << endl;
    cout << "| No.\t| Name\t| Phone number\t| Address\t| Date and Time " << endl;
    
    int num = 1;
    list<Customer>::iterator customer;
    for (customer = hotel.getListCustomer().begin(); customer != hotel.getListCustomer().end(); customer++) {

        bool thisCustomerInHotel = (customer->getBookingHistory().back().status == IN);

        if (thisCustomerInHotel) {
            string name = customer->getName();
            string phoneNumber = customer->getPhoneNumber();
            string address = customer->getAddress();
            type_Date date = customer->getBookingHistory().back().date;
            type_Time time = customer->getBookingHistory().back().time;

            cout << "| " << num << "\t| " << name << "\t| " << phoneNumber << "\t\t| " << address << "\t| ";
            cout << date.day << "/" << date.month << "/" << date.year << " ";
            cout << time.hour << ":" << time.minutes << endl;

            num++;
        }
    }
}

list<Customer>::iterator HotelManager::findCustomer(int customerNumber) {
    list<Customer>::iterator customer = hotel.getListCustomer().begin();
    int count = 1;
    while (customer != hotel.getListCustomer().end()) {
        if (count == customerNumber) {
            return customer;
        }
        customerNumber++;
        customer++;
    }
    return customer;
}

void HotelManager::manageCustomer() {
    int key;
    string name;
    string password;

    if (hotel.getListCustomer().empty()) {
        printBeginLine();
        cout << "[ CUSTOMER ]\n" << endl;
        cout << "# Hotel has no customer\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while(1) {
        printBeginLine();
        cout << "[ CUSTOMER ]\n" << endl;
        cout << "| 1: Enter account" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key != 0 && key != 1) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;

        printBeginLine();
        cout << "- Enter manager user name: "; cin >> name;
        cout << "\n- Enter manager password: "; cin >> password;
        printEndLine();

        if (!hotel.getSecurityManagement().checkManager(name, password)) {
            printBeginLine();
            cout << "<ERROR>: Manager account is incorrect." << endl;
            cout << "\nEnter any number to return: "; cin >> key;
            printEndLine();
            continue;
        }
        else break;
    }

    while(1) {
        cout << "[ CUSTOMER ]: manage customer\n" << endl;
        showCustomer();
        cout << endl;
        cout << "| 1: update customer information" << endl;
        cout << "| 2: delete customer information" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key == 0) break;

        else if (key != 1 && key != 2) {
            printInvalidKey();
            continue;
        }

        bool chooseUpdate = (key == 1);
        bool chooseDelete = (key == 2);

        printBeginLine();
        cout << "\nEnter number of customer: "; cin >> key;
        cout << endl;
        printEndLine();

        list<Customer>::iterator customer = findCustomer(key);

        if (customer == hotel.getListCustomer().end()) {
            printBeginLine();
            cout << "\n<ERROR>: Can't find this customer\n" << endl;
            cout << "Enter any number to return: "; cin >> key;
            printEndLine();
            continue;
        }

        if (chooseUpdate) updateCustomer(customer);
        if (chooseDelete) deleteCustomer(customer);
    }
}

void HotelManager::updateName(list<Customer>::iterator customer, string oldName) {
    int key;
    string newName;

    printBeginLine();
    cout << "\nEnter new name: "; cin >> newName;
    printEndLine();

    while(1) {
        printBeginLine();
        cout << "- Confirm to update name -\n" << endl;
        cout << "- Old name: " << oldName << endl;
        cout << "- New name: " << newName << endl;
        cout << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: "; cin >> key;

        if (key == 1) {
            customer->setName(newName);
            printBeginLine();
            cout << "\n- Update name successfully -\n" << endl;
            cout << "- Old name: " << oldName << endl;
            cout << "- New name: " << newName << endl;
            cout << "\nEnter any number to return: "; cin >> key;
            printEndLine();
            break;
        }
        else if (key == 0) break;
        else printInvalidKey();
    }
}

void HotelManager::updatePhoneNumber(list<Customer>::iterator customer, string oldPhoneNumber) {
    int key;
    string newPhoneNumber;

    printBeginLine();
    cout << "\nEnter new phone number: "; cin >> newPhoneNumber;
    printEndLine();

    while(1) {
        printBeginLine();
        cout << "- Confirm to update phone number -\n" << endl;
        cout << "- Old phone number: " << oldPhoneNumber << endl;
        cout << "- New phone number: " << newPhoneNumber << endl;
        cout << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: "; cin >> key;

        if (key == 1) {
            customer->setPhoneNumber(newPhoneNumber);
            printBeginLine();
            cout << "\n- Update phone number successfully -\n" << endl;
            cout << "- Old phone number: " << oldPhoneNumber << endl;
            cout << "- New phone number: " << newPhoneNumber << endl;
            cout << "\nEnter any number to return: "; cin >> key;
            printEndLine();
            break;
        }
        else if (key == 0) break;
        else printInvalidKey();
    }
}

void HotelManager::updateAddress(list<Customer>::iterator customer, string oldAddress) {
    int key;
    string newAddress;

    printBeginLine();
    cout << "\nEnter new address: "; cin >> newAddress;
    printEndLine();

    while(1) {
        printBeginLine();
        cout << "- Confirm to update address -\n" << endl;
        cout << "- Old address: " << oldAddress << endl;
        cout << "- New address: " << newAddress << endl;
        cout << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: "; cin >> key;

        if (key == 1) {
            customer->setAddress(newAddress);
            printBeginLine();
            cout << "\n- Update address successfully -\n" << endl;
            cout << "- Old address: " << oldAddress << endl;
            cout << "- New address: " << newAddress << endl;
            cout << "\nEnter any number to return: "; cin >> key;
            printEndLine();
            break;
        }
        else if (key == 0) break;
        else printInvalidKey();
    }
}

void HotelManager::updateCustomer(list<Customer>::iterator customer) {
    int key;
    string name;
    string phoneNumber;
    string address;

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

        switch (key) {
        case 1:
            updateName(customer, name);
            break;
        case 2:
            updatePhoneNumber(customer, phoneNumber);
            break;
        case 3:
            updateAddress(customer, address);
        case 0:
            return;
        default:
            printInvalidKey();
            break;
        }
    }
}

void HotelManager::deleteCustomer(list<Customer>::iterator customer) {
    int key;
    string name;
    string phoneNumber;
    string address;

    while(1) {
        name = customer->getName();
        phoneNumber = customer->getPhoneNumber();
        address = customer->getAddress();

        printBeginLine();
        cout << "- Confirm to delete customer -\n" << endl;
        cout << "- Name\t\t: " << name << endl;
        cout << "- Phone number\t: " << phoneNumber << endl;
        cout << "- Address\t: " << address << endl;
        cout << endl;
        cout << "|1: Yes" << endl;
        cout << "|0: No" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();
        
        if (key == 1) {
            hotel.getListCustomer().erase(customer);
            printBeginLine();
            cout << "\n- Delete customer successfully -\n" << endl;
            cout << "Information of customer just had deleted:" << endl;
            cout << "- Name: " << name << endl;
            cout << "- Phone number: " << phoneNumber << endl;
            cout << "- Address: " << address << endl;
            cout << "\nEnter any number to return: "; cin >> key;
            printEndLine();
            return;
        }
        else if (key == 0) return;
        else printInvalidKey();
    }
}

void HotelManager::manageEmployee() {
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

void HotelManager::accessManager() {
    int key;
    string userName;
    string password;

    printBeginLine();
    cout << "- Enter manager user name: "; cin >> userName;
    cout << "\n- Enter manager password: "; cin >> password;
    printEndLine();

    if (!hotel.getSecurityManagement().checkManager(userName, password)) {
        printBeginLine();
        cout << "<ERROR>: Manager account is incorrect." << endl;
        cout << "\nEnter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while(1) {
        printBeginLine();
        cout << "[ EMPLOYEE ]: manager\n" << endl;
        cout << "| 1: update employee" << endl;
        cout << "| 2: delete employee" << endl;
        cout << "| 3: add employee" << endl;
        cout << "| 4: show employee" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        switch (key) {
            case 1:
                updateEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                addEmployee();
                break;
            case 4:
                showEmployee();
                break;
            case 0:
                return;
            default:
                printInvalidKey();
                break;
        }
    }
}

void HotelManager::printJob(type_JobPosition job) {
    switch (job)
    {
    case JANITOR:
        cout << "janitor";
        break;
    case RECEPTIONIST:
        cout << "receptionist";
        break;
    case LAUNDRY_STAFF:
        cout << "laundry staff";
        break;
    case LUGGAGE_STAFF:
        cout << "luggage staff";
        break;
    case GARDENER:
        cout << "gardener";
        break;
    }
}

void HotelManager::showEmployee() {
    cout << "- List of employee -" << endl;
    cout << "| No.\t| Name\t| Phone number\t| Job Position\t| Schedule" << endl;

    int numberOrder = 1;
    list<Employee>::iterator employee = hotel.getListEmployee().begin();
    while (employee != hotel.getListEmployee().end()) {
        int hourStart = employee->getSchedule().startTime.hour;
        int minutesStart = employee->getSchedule().startTime.minutes;
        int hourEnd = employee->getSchedule().endTime.hour;
        int minutesEnd = employee->getSchedule().endTime.minutes;

        cout << "| " << numberOrder << "\t";
        cout << "| " << employee->getName() << "\t\t";
        cout << "| " << employee->getPhoneNumber() << "\t";
        cout << "| "; printJob(employee->getJobPosition()); cout << "\t";
        cout << "| from " << hourStart << ":" << minutesStart << " to " << hourEnd << ":" << minutesEnd << "\t";
        cout << endl;
        employee++;
    }
}

void HotelManager::updateEmployee() {
    int key;

    if (hotel.getListEmployee().empty()) {
        printBeginLine();
        cout << "[ EMPLOYEE ]: update employee\n" << endl;
        cout << "# There is no employee to update.\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while(1) {
        printBeginLine();
        cout << "[ EMPLOYEE ]: update employee\n" << endl;
        showEmployee();
        cout << endl;
        cout << "| 1: update name" << endl;
        cout << "| 2: update phone number" << endl;
        cout << "| 3: update job position" << endl;
        cout << "| 4: update start time" << endl;
        cout << "| 5: update end time" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;

        if (key < 0 || key > 5) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;

        int choice = key;

        cout << "Enter number of employee to update: "; cin >> key;

        int numberEmployee = key;

        printEndLine();

        int count = 1;
        list<Employee>::iterator employee = hotel.getListEmployee().begin();
        while (employee != hotel.getListEmployee().end()) {
            if (count >= numberEmployee) break;
            count++;
            employee++;
        }

        if (count < numberEmployee || count > numberEmployee) {
            printBeginLine();
            cout << "\n<ERROR>: Can't find any employee." << endl;
            cout << "\nEnter any number to return: "; cin >> key;
            printEndLine();
            continue;
        }

        switch (choice) {
        case 1:
            updateName(employee);
            break;
        case 2:
            updatePhoneNumber(employee);
            break;
        case 3:
            updateJobPosition(employee);
            break;
        case 4:
            updateStartTime(employee);
            break;
        case 5:
            updateEndTime(employee);
            break;
        }
    }
}

void HotelManager::updateName(list<Employee>::iterator employee) {
    int key;
    string oldName = employee->getName();
    string newName;

    printBeginLine();
    cout << "- Update name of employee -\n" << endl;
    cout << "- Old name: " << oldName << endl;
    cout << "\nEnter new name: "; cin >> newName;
    printEndLine();

    while(1) {
        printBeginLine();
        cout << "- Confirm to update name of employee -\n" << endl;
        cout << "- Old name: " << oldName << endl;
        cout << "- New name: " << newName << endl;
        cout << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key != 0 && key != 1) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;
        else break;
    }

    employee->setName(newName);

    printBeginLine();
    cout << "- Update name of employee successfully -\n" << endl;
    cout << "- Old name: " << oldName << endl;
    cout << "- New name: " << newName << endl;
    cout << "\nEnter any number to return: "; cin >> key;
    printEndLine();
}

void HotelManager::updatePhoneNumber(list<Employee>::iterator employee) {
    int key;
    string oldPhoneNumber = employee->getPhoneNumber();
    string newPhoneNumber;

    printBeginLine();
    cout << "- Update phone number of employee -\n" << endl;
    cout << "- Old phone number: " << oldPhoneNumber << endl;
    cout << "\nEnter new phone number: "; cin >> newPhoneNumber;
    printEndLine();

    while(1) {
        printBeginLine();
        cout << "- Confirm to update phone number of employee -\n" << endl;
        cout << "- Old phone number: " << oldPhoneNumber << endl;
        cout << "- New phone number: " << newPhoneNumber << endl;
        cout << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key != 0 && key != 1) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;
        else break;
    }

    employee->setPhoneNumber(newPhoneNumber);

    printBeginLine();
    cout << "- Update phone number of employee successfully -\n" << endl;
    cout << "- Old phone number: " << oldPhoneNumber << endl;
    cout << "- New phone number: " << newPhoneNumber << endl;
    cout << "\nEnter any number to return: "; cin >> key;
    printEndLine();
}

void HotelManager::printListJobPosition(type_JobPosition oldJob) {
    int count = 0;
    while (count < 6) {
        if (count == oldJob) continue;
        if (count == JANITOR) {
            cout << count + 1 << ": janitor" << endl;
        }
        else if (count == RECEPTIONIST) {
            cout << count + 1 << ": receptionist" << endl;
        }
        else if (count == LAUNDRY_STAFF) {
            cout << count + 1 << ": laundry staff" << endl;
        }
        else if (count == LUGGAGE_STAFF) {
            cout << count + 1 << ": luggage staff" << endl;
        }
        else if (count == GARDENER) {
            cout << count + 1 << ": gardener" << endl;
        }
        count++;
    }
}

void HotelManager::updateJobPosition(list<Employee>::iterator employee) {
    int key;
    type_JobPosition oldJob = employee->getJobPosition();
    type_JobPosition newJob;

    while(1) {
        printBeginLine();
        cout << "- Update job position of employee -\n" << endl;
        cout << "- Old job position: "; printJob(oldJob); cout << endl;
        cout << "- Choose 1 of new job positions:" << endl;

        printListJobPosition(oldJob);

        cout << "\nEnter new job position: "; cin >> key;
        printEndLine();

        switch (key) {
        case 1:
            newJob = JANITOR; break;
        case 2:
            newJob =  RECEPTIONIST; break;
        case 3:
            newJob = LAUNDRY_STAFF; break;
        case 4:
            newJob = LUGGAGE_STAFF; break;
        case 5:
            newJob = GARDENER; break;
        default:
            printInvalidKey();
            continue;
        }
        break;
    }

    while(1) {
        printBeginLine();
        cout << "- Confirm to update job position of employee -\n" << endl;
        cout << "- Old job position: "; printJob(oldJob); cout << endl;
        cout << "- New job position: "; printJob(newJob); cout << endl;
        cout << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key != 0 && key != 1) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;
        else break;
    }

    employee->setJobPosition(newJob);

    printBeginLine();
    cout << "- Update job position of employee successfully -\n" << endl;
    cout << "- Old job position: "; printJob(oldJob); cout << endl;
    cout << "- New job position: "; printJob(newJob); cout << endl;
    cout << "\nEnter any number to return: "; cin >> key;
    printEndLine();
}

void HotelManager::updateStartTime(list<Employee>::iterator employee) {
    int key;
    type_Time oldStartTime = employee->getSchedule().startTime;
    type_Time newStartTime;

    while(1) {
        printBeginLine();
        cout << "- Update start time of employee -\n" << endl;
        cout << "- Old start time: " << oldStartTime.hour << ":" << oldStartTime.minutes << endl;
        cout << "\nEnter new start time hour: "; cin >> newStartTime.hour;
        cout << "\nEnter new start time minutes: "; cin >> newStartTime.minutes;
        printEndLine();

        if (newStartTime.hour < 0 || newStartTime.hour > 23) {
            printInvalidKey();
            continue;
        }
        if (newStartTime.minutes < 0 || newStartTime.minutes > 59) {
            printInvalidKey();
            continue;
        }
        break;
    }

    while(1) {
        printBeginLine();
        cout << "- Confirm to update start time of employee -\n" << endl;
        cout << "- Old start time: " << oldStartTime.hour << ":" << oldStartTime.minutes << endl;
        cout << "- New start time: " << newStartTime.hour << ":" << newStartTime.minutes << endl;
        cout << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key != 0 && key != 1) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;
        else break;
    }

    Schedule newSchedule = employee->getSchedule();
    newSchedule.startTime = newStartTime;
    employee->setSchedule(newSchedule);

    printBeginLine();
    cout << "- Update start time of employee successfully -\n" << endl;
    cout << "- Old start time: " << oldStartTime.hour << ":" << oldStartTime.minutes << endl;
    cout << "- New start time: " << newStartTime.hour << ":" << newStartTime.minutes << endl;
    cout << "\nEnter any number to return: "; cin >> key;
    printEndLine();
}

void HotelManager::updateEndTime(list<Employee>::iterator employee) {
    int key;
    type_Time oldEndTime = employee->getSchedule().endTime;
    type_Time newEndTime;

    while(1) {
        printBeginLine();
        cout << "- Update end time of employee -\n" << endl;
        cout << "- Old end time: " << oldEndTime.hour << ":" << oldEndTime.minutes << endl;
        cout << "\nEnter new end time hour: "; cin >> oldEndTime.hour;
        cout << "\nEnter new end time minutes: "; cin >> oldEndTime.minutes;
        printEndLine();

        if (newEndTime.hour < 0 || newEndTime.hour > 23) {
            printInvalidKey();
            continue;
        }
        if (newEndTime.minutes < 0 || newEndTime.minutes > 59) {
            printInvalidKey();
            continue;
        }
        break;
    }

    while(1) {
        printBeginLine();
        cout << "- Confirm to update end time of employee -\n" << endl;
        cout << "- Old end time: " << oldEndTime.hour << ":" << oldEndTime.minutes << endl;
        cout << "- New end time: " << newEndTime.hour << ":" << newEndTime.minutes << endl;
        cout << endl;
        cout << "| 1: Yes" << endl;
        cout << "| 0: No" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key != 0 && key != 1) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;
        else break;
    }

    Schedule newSchedule = employee->getSchedule();
    newSchedule.endTime = newEndTime;
    employee->setSchedule(newSchedule);

    printBeginLine();
    cout << "- Update end time of employee successfully -\n" << endl;
    cout << "- Old end time: " << oldEndTime.hour << ":" << oldEndTime.minutes << endl;
    cout << "- New end time: " << newEndTime.hour << ":" << newEndTime.minutes << endl;
    cout << "\nEnter any number to return: "; cin >> key;
    printEndLine();
}

void HotelManager::deleteEmployee() {
    int key;

    if (hotel.getListEmployee().empty()) {
        printBeginLine();
        cout << "[ EMPLOYEE ]: delete employee\n" << endl;
        cout << "# There is no employee to delete.\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while(1) {
        printBeginLine();
        cout << "[ EMPLOYEE ]: delete employee\n" << endl;
        showEmployee();
        cout << "| Enter number of employee to delete" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key < 0) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;

        int count = 1;
        list<Employee>::iterator employee = hotel.getListEmployee().begin();
        while (employee != hotel.getListEmployee().end()) {
            if (count >= key) break;
            employee++;
        }

        if (employee == hotel.getListEmployee().end()) {
            printBeginLine();
            cout << "\n<ERROR>: Can't find any employee." << endl;
            cout << "\nEnter any number to return: "; cin >> key;
            printEndLine();
            continue;
        }

        type_Time startTime = employee->getSchedule().startTime;
        type_Time endTime = employee->getSchedule().endTime;

        while(1) {
            printBeginLine();
            cout << "- Confirm to delete employee -\n" << endl;
            cout << "- Name: " << employee->getName() << endl;
            cout << "- Phone number: " << employee->getPhoneNumber() << endl;
            cout << "- Job position: "; printJob(employee->getJobPosition()); cout << endl;
            cout << "- Schedule: from " << startTime.hour << ":" << startTime.minutes << " to " << endTime.hour << ":" << endTime.minutes << endl;
            cout << "\n| 1: Yes" << endl;
            cout << "| 0: No" << endl;
            cout << "\nEnter: "; cin >> key;
            printEndLine();

            if (key != 0 && key != 1) {
                printInvalidKey();
                continue;
            }
            else break;
        }

        if (key == 1) {
            hotel.getListEmployee().erase(employee);

            printBeginLine();
            cout << "- Delete employee successfully -\n" << endl;
            cout << "Enter any number to return: "; cin >> key;
            printEndLine();
        }
    }
}

void HotelManager::addEmployee() {
    int key;
    string name;
    string phoneNumber;
    type_JobPosition jobPosition;
    type_Time startTime;
    type_Time endTime;

    while(1) {
        printBeginLine();
        cout << "[ EMPLOYEE ]: manager\n" << endl;
        showEmployee();
        cout << "\n| 1: add employee" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;

        if (key != 0 && key != 1) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;
        
        cout << "\nEnter employee name: "; cin >> name;
        cout << "\nEnter employee phone number: "; cin >> phoneNumber;

        while(1) {
            printBeginLine();
            cout << "- Choose 1 job position -\n" << endl;
            cout << "1: janitor\n";
            cout << "2: receptionist\n";
            cout << "3: laundry staff\n";
            cout << "4: luggage staff\n";
            cout << "5: gardener\n";
            cout << "\nEnter: "; cin >> key;
            printEndLine();

            switch (key - 1)
            {
            case JANITOR:
                jobPosition = JANITOR; break;
            case RECEPTIONIST:
                jobPosition = RECEPTIONIST; break;
            case LAUNDRY_STAFF:
                jobPosition = LAUNDRY_STAFF; break;
            case LUGGAGE_STAFF:
                jobPosition = LUGGAGE_STAFF; break;
            case GARDENER:
                jobPosition = GARDENER; break;
            default:
                printInvalidKey();
                continue;
            }
            break;
        }

        while(1) {
            printBeginLine();
            cout << "Enter start time hour: "; cin >> startTime.hour;
            cout << "\nEnter start time minutes: "; cin >> startTime.minutes;
            printEndLine();

            bool hourError = (startTime.hour < 0) || (startTime.hour > 23);
            bool minutesError = (startTime.minutes < 0) || (startTime.minutes > 59);

            if (hourError || minutesError) {
                cout << "<ERROR>: Start time is invalid" << endl;
                cout << "\nEnter any number to return: "; cin >> key;
            }
            else break;
        }

        while(1) {
            printBeginLine();
            cout << "Enter end time hour: "; cin >> endTime.hour;
            cout << "\nEnter end time minutes: "; cin >> endTime.minutes;
            printEndLine();

            bool hourError = (endTime.hour < 0) || (endTime.hour > 23);
            bool minutesError = (endTime.minutes < 0) || (endTime.minutes > 59);

            if (hourError || minutesError) {
                cout << "<ERROR>: End time is invalid" << endl;
                cout << "\nEnter any number to return: "; cin >> key;
            }
            else break;
        }

        while(1) {
            printBeginLine();
            cout << "- Confirm to add employee -\n" << endl;
            cout << "Employee name\t\t: " << name << endl;
            cout << "Employee phone number\t: " << phoneNumber << endl;
            cout << "Employee job position\t: "; printJob(jobPosition); cout << endl;
            cout << "Employee schedule:" << endl;
            cout << "  Start time\t: " << startTime.hour << ":" << startTime.minutes << endl;
            cout << "  End time\t: " << endTime.hour << ":" << endTime.minutes << endl;
            cout << "\n| 1: Yes" << endl;
            cout << "| 0: No" << endl;
            cout << "\nEnter: "; cin >> key;
            printEndLine();

            if (key != 0 && key != 1) {
                printInvalidKey();
                continue;
            }
            else break;
        }

        if (key == 1) {
            Schedule schedule = {startTime, endTime};
            Employee newEmployee(name, phoneNumber, jobPosition, schedule);
            hotel.getListEmployee().push_back(newEmployee);

            printBeginLine();
            cout << "- Add employee successfully -\n" << endl;
            cout << "Enter any number to return: "; cin >> key;
            printEndLine();
        }
    }
}

void HotelManager::accessStaff() {

}

void HotelManager::showServices() {
    cout << "Services in the hotel:" << endl;
    if (hotel.getServices().restaurant == true) cout << "- Restaurant" << endl;
    if (hotel.getServices().bar == true) cout << "- Bar" << endl;
    if (hotel.getServices().swimmingPool == true) cout << "- Swimming pool" << endl;
    if (hotel.getServices().gym == true) cout << "- Gym" << endl;
    if (hotel.getServices().parking == true) cout << "- Parking" << endl;
}

void HotelManager::manageServices() {
    int key;

    while(1) {
        printBeginLine();
        cout << "[ SERVICES ]\n" << endl;
        showServices();
        cout << endl;
        cout << "| 1: add services" << endl;
        cout << "| 2: delete services" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key == 1) {
            addServices();
        }
        else if (key == 2) {
            deleteService();
        }
        else if (key == 0) return;
        else {
            printInvalidKey();
        }
    }
}

bool HotelManager::hasNoServicesToAdd() {
    if (hotel.getServices().restaurant == false) return false;
    if (hotel.getServices().bar == false) return false;
    if (hotel.getServices().swimmingPool == false) return false;
    if (hotel.getServices().gym == false) return false;
    if (hotel.getServices().parking == false) return false;
    return true;
}

void HotelManager::addServices() {
    int key;

    if (hasNoServicesToAdd()) {
        printBeginLine();
        cout << "[ SERVICES ]: add services\n" << endl;
        cout << "# No services to add\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while (1) {
        int num = 1;

        printBeginLine();
        cout << "[ SERVICES ]: add services\n" << endl;

        if (!hotel.getServices().restaurant) {
            cout << num << ": Restaurant\n";
            num++;
        }
        if (!hotel.getServices().bar) {
            cout << num << ": Bar\n";
            num++;
        }
        if (!hotel.getServices().swimmingPool) {
            cout << num << ": Swimming pool\n";
            num++;
        }
        if (!hotel.getServices().gym) {
            cout << num << ": Gym\n";
            num++;
        }
        if (!hotel.getServices().parking) {
            cout << num << ": Parking\n";
            num++;
        }

        if (num == 1) {
            cout << "# No services to add\n" << endl;
            cout << "Enter any number to return: "; cin >> key;
            printEndLine();
            return;
        }
        
        cout << endl;
        cout << "| Enter number of service to add" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key == 0) return;

        num = 1;

        // Restaurant
        if (hotel.getServices().restaurant == false) {
            if (num == key) {
                while (1) {
                    printBeginLine();
                    cout << "- Confirm to add Restaurant -\n" << endl;
                    cout << "| 1: Yes\n";
                    cout << "| 0: No\n";
                    cout << "\nEnter: "; cin >> key;
                    if (key == 0 || key == 1) break;
                    else printInvalidKey();
                }
                if (key == 1) {
                    hotel.getServices().restaurant = true;
                    printBeginLine();
                    cout << "- Add Restaurant successfully -" << endl;
                    cout << "\nEnter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else continue;
            }
            else num++;
        }

        // Bar
        if (hotel.getServices().bar == false) {
            if (num == key) {
                while (1) {
                    printBeginLine();
                    cout << "- Confirm to add Bar -\n" << endl;
                    cout << "| 1: Yes\n";
                    cout << "| 0: No\n";
                    cout << "\nEnter: "; cin >> key;
                    if (key == 0 || key == 1) break;
                    else printInvalidKey();
                }
                if (key == 1) {
                    hotel.getServices().bar = true;
                    printBeginLine();
                    cout << "- Add Bar successfully -" << endl;
                    cout << "\nEnter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else continue;
            }
            else num++;
        }

        // Swimming pool
        if (hotel.getServices().swimmingPool == false) {
            if (num == key) {
                while (1) {
                    printBeginLine();
                    cout << "- Confirm to add Swimming pool -\n" << endl;
                    cout << "| 1: Yes\n";
                    cout << "| 0: No\n";
                    cout << "\nEnter: "; cin >> key;
                    if (key == 0 || key == 1) break;
                    else printInvalidKey();
                }
                if (key == 1) {
                    hotel.getServices().swimmingPool = true;
                    printBeginLine();
                    cout << "- Add Swimming pool successfully -" << endl;
                    cout << "\nEnter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else continue;
            }
            else num++;
        }

        // Gym
        if (hotel.getServices().gym == false) {
            if (num == key) {
                while (1) {
                    printBeginLine();
                    cout << "- Confirm to add Gym -\n" << endl;
                    cout << "| 1: Yes\n";
                    cout << "| 0: No\n";
                    cout << "\nEnter: "; cin >> key;
                    if (key == 0 || key == 1) break;
                    else printInvalidKey();
                }
                if (key == 1) {
                    hotel.getServices().gym = true;
                    printBeginLine();
                    cout << "- Add Gym successfully -" << endl;
                    cout << "\nEnter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else continue;
            }
            else num++;
        }

        // Parking
        if (hotel.getServices().parking == false) {
            if (num == key) {
                while (1) {
                    printBeginLine();
                    cout << "- Confirm to add Parking -\n" << endl;
                    cout << "| 1: Yes\n";
                    cout << "| 0: No\n";
                    cout << "\nEnter: "; cin >> key;
                    if (key == 0 || key == 1) break;
                    else printInvalidKey();
                }
                if (key == 1) {
                    hotel.getServices().parking = true;
                    printBeginLine();
                    cout << "- Add Parking successfully -" << endl;
                    cout << "\nEnter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else continue;
            }
            else num++;
        }

        printInvalidKey();
    }
}

bool HotelManager::hasNoServicesToDelete() {
    if (hotel.getServices().restaurant == true) return false;
    if (hotel.getServices().bar == true) return false;
    if (hotel.getServices().swimmingPool == true) return false;
    if (hotel.getServices().gym == true) return false;
    if (hotel.getServices().parking == true) return false;
    return true;
}

void HotelManager::deleteService() {
    int key;

    if (hasNoServicesToDelete()) {
        printBeginLine();
        cout << "[ SERVICES ]: delete services\n" << endl;
        cout << "# No services to delete\n" << endl;
        cout << "Enter any number to return: "; cin >> key;
        printEndLine();
        return;
    }

    while (1) {
        int num = 1;

        printBeginLine();
        cout << "[ SERVICES ]: delete services\n" << endl;

        if (hotel.getServices().restaurant) {
            cout << num << ": Restaurant\n";
            num++;
        }
        if (hotel.getServices().bar) {
            cout << num << ": Bar\n";
            num++;
        }
        if (hotel.getServices().swimmingPool) {
            cout << num << ": Swimming pool\n";
            num++;
        }
        if (hotel.getServices().gym) {
            cout << num << ": Gym\n";
            num++;
        }
        if (hotel.getServices().parking) {
            cout << num << ": Parking\n";
            num++;
        }

        if (num == 1) {
            cout << "# No services to delete\n" << endl;
            cout << "Enter any number to return: "; cin >> key;
            printEndLine();
            return;
        }
        
        cout << endl;
        cout << "| Enter number of service to delete" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;
        printEndLine();

        if (key == 0) return;

        num = 1;

        // Restaurant
        if (hotel.getServices().restaurant == true) {
            if (num == key) {
                while (1) {
                    printBeginLine();
                    cout << "- Confirm to delete Restaurant -\n" << endl;
                    cout << "| 1: Yes\n";
                    cout << "| 0: No\n";
                    cout << "\nEnter: "; cin >> key;
                    if (key == 0 || key == 1) break;
                    else printInvalidKey();
                }
                if (key == 1) {
                    hotel.getServices().restaurant = false;
                    printBeginLine();
                    cout << "- Delete Restaurant successfully -" << endl;
                    cout << "\nEnter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else continue;
            }
            else num++;
        }

        // Bar
        if (hotel.getServices().bar == true) {
            if (num == key) {
                while (1) {
                    printBeginLine();
                    cout << "- Confirm to delete Bar -\n" << endl;
                    cout << "| 1: Yes\n";
                    cout << "| 0: No\n";
                    cout << "\nEnter: "; cin >> key;
                    if (key == 0 || key == 1) break;
                    else printInvalidKey();
                }
                if (key == 1) {
                    hotel.getServices().bar = false;
                    printBeginLine();
                    cout << "- Delete Bar successfully -" << endl;
                    cout << "\nEnter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else continue;
            }
            else num++;
        }

        // Swimming pool
        if (hotel.getServices().swimmingPool == true) {
            if (num == key) {
                while (1) {
                    printBeginLine();
                    cout << "- Confirm to delete Swimming pool -\n" << endl;
                    cout << "| 1: Yes\n";
                    cout << "| 0: No\n";
                    cout << "\nEnter: "; cin >> key;
                    if (key == 0 || key == 1) break;
                    else printInvalidKey();
                }
                if (key == 1) {
                    hotel.getServices().swimmingPool = false;
                    printBeginLine();
                    cout << "- Delete Swimming pool successfully -" << endl;
                    cout << "\nEnter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else continue;
            }
            else num++;
        }

        // Gym
        if (hotel.getServices().gym == true) {
            if (num == key) {
                while (1) {
                    printBeginLine();
                    cout << "- Confirm to delete Gym -\n" << endl;
                    cout << "| 1: Yes\n";
                    cout << "| 0: No\n";
                    cout << "\nEnter: "; cin >> key;
                    if (key == 0 || key == 1) break;
                    else printInvalidKey();
                }
                if (key == 1) {
                    hotel.getServices().gym = false;
                    printBeginLine();
                    cout << "- Add Gym successfully -" << endl;
                    cout << "\nEnter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else continue;
            }
            else num++;
        }

        // Parking
        if (hotel.getServices().parking == true) {
            if (num == key) {
                while (1) {
                    printBeginLine();
                    cout << "- Confirm to delete Parking -\n" << endl;
                    cout << "| 1: Yes\n";
                    cout << "| 0: No\n";
                    cout << "\nEnter: "; cin >> key;
                    if (key == 0 || key == 1) break;
                    else printInvalidKey();
                }
                if (key == 1) {
                    hotel.getServices().parking = false;
                    printBeginLine();
                    cout << "- Delete Parking successfully -" << endl;
                    cout << "\nEnter any number to return: "; cin >> key;
                    printEndLine();
                    continue;
                }
                else continue;
            }
            else num++;
        }

        printInvalidKey();
    }
}

void HotelManager::showRoomCanCheckOut() {
    cout << "- List room can check out -" << endl;
    list<Room>::iterator room = hotel.getListRoom().begin();
    while (room != hotel.getListRoom().end()) {
        if (room->canCheckOut()) {
            cout << "| " << room->getRoomNumber() << " ";
        }
        room++;
    }
    cout << "|" << endl;
}

void HotelManager::managePayment() {
    int key;
    type_Date date;
    type_Time time;
    int bill = 0;

    if (hotel.getListCustomer().empty()) {
        printBeginLine();
        cout << "[ PAYMENT ]\n" << endl;
        cout << "# No room to pay.\n" << endl;
        cout << "Enter any umbr to return: "; cin >> key;
        printEndLine();
        return;
    }

    while(1) {
        printBeginLine();
        cout << "[ PAYMENT ]\n" << endl;
        showRoomCanCheckOut();
        cout << "\n| Enter room number to pay" << endl;
        cout << "| 0: Back" << endl;
        cout << "\nEnter: "; cin >> key;

        if (key < 0) {
            printInvalidKey();
            continue;
        }
        else if (key == 0) return;

        list<Customer>::iterator customer = hotel.getListCustomer().begin();
        while (customer != hotel.getListCustomer().end()) {
            if (customer->getRoomNumber() == key) break;
            customer++;
        }

        if (customer == hotel.getListCustomer().end()) {
            printBeginLine();
            cout << "[ PAYMENT ]\n" << endl;
            cout << "<ERROR>: Can't find room to check out.\n" << endl;
            cout << "Enter any number to return: "; cin >> key;
            printEndLine();
            continue;
        }

        while(1) {
            printBeginLine();
            cout << "[ PAYMENT ]: pay\n" << endl;
            cout << "- Name\t\t: " << customer->getName() << endl;
            cout << "- Phone number\t: " << customer->getPhoneNumber() << endl;
            cout << "- Address\t: " << customer->getAddress() << endl << endl;
            cout << "| 1: Pay" << endl;
            cout << "| 0: Back" << endl;
            cout << "\nEnter: "; cin >> key;
            printEndLine();

            if (key == 0 || key == 1) break;
            else printInvalidKey();
        }

        if (key == 0) continue;

        while(1) {
            printBeginLine();
            cout << "- Book year: " << customer->getBookingHistory().back().date.year << endl;
            cout << "- Enter check out year: "; cin >> date.year; cout << endl;
            cout << "- Book month: " << customer->getBookingHistory().back().date.month << endl;
            cout << "- Enter check out month: "; cin >> date.month; cout << endl;
            cout << "- Book day: " << customer->getBookingHistory().back().date.day << endl;
            cout << "- Enter check out day: "; cin >> date.day; cout << endl;
            printEndLine();

            if (customer->getBookingHistory().back().date.year > date.year) {
                printBeginLine();
                cout << "<ERROR>: Year is invalid" << endl;
                cout << "\nEnter any number to return: "; cin >> key;
                printEndLine();
                continue;
            }
            else if (customer->getBookingHistory().back().date.month > date.month || date.month > 12 || date.month < 1) {
                printBeginLine();
                cout << "<ERROR>: Month is invalid" << endl;
                cout << "\nEnter any number to return: "; cin >> key;
                printEndLine();
                continue;
            }
            else if (customer->getBookingHistory().back().date.day > date.day || date.day > 30 || date.day < 1) {
                printBeginLine();
                cout << "<ERROR>: Day is invalid" << endl;
                cout << "\nEnter any number to return: "; cin >> key;
                printEndLine();
                continue;
            }
            break;
        }

        while(1) {
            printBeginLine();
            cout << "- Book hour: " << customer->getBookingHistory().back().time.hour << endl;
            cout << "- Enter check out hour: "; cin >> time.hour; cout << endl;
            cout << "- Book minutes: " << customer->getBookingHistory().back().time.minutes << endl;
            cout << "- Enter check out minutes: "; cin >> time.minutes; cout << endl;
            printEndLine();

            if (customer->getBookingHistory().back().date.year == date.year 
            && customer->getBookingHistory().back().date.month == date.month
            && customer->getBookingHistory().back().date.day == date.day) {
                if (customer->getBookingHistory().back().time.hour > time.hour || time.hour < 0 || time.hour > 23)
                printBeginLine();
                cout << "<ERROR>: Hour is invalid" << endl;
                cout << "\nEnter any number to return: "; cin >> key;
                printEndLine();
                continue;
                }
                else if (customer->getBookingHistory().back().time.minutes > time.minutes || time.minutes < 0 || time.minutes > 59) {
                printBeginLine();
                cout << "<ERROR>: Minutes is invalid" << endl;
                cout << "\nEnter any number to return: "; cin >> key;
                printEndLine();
                continue;
            }
            break;
        }

        // 1 minute = 2$

        bill = (bill + (date.year - customer->getBookingHistory().back().date.year)) * 12;

        bill = (bill + (date.month - customer->getBookingHistory().back().date.month)) * 30;

        bill = (bill + (date.day - customer->getBookingHistory().back().date.day)) * 24;

        bill = (bill + (time.hour - customer->getBookingHistory().back().time.hour)) * 60;

        bill = ( bill + (time.minutes - customer->getBookingHistory().back().time.minutes) * 2);

        while(1) {
            printBeginLine();
            cout << "[ PAYMENT ]: pay\n" << endl;
            cout << "- Name\t\t: " << customer->getName() << endl;
            cout << "- Phone number\t: " << customer->getPhoneNumber() << endl;
            cout << "- Address\t: " << customer->getAddress() << endl;
            cout << "- Room number\t: " << customer->getRoomNumber() << endl;
            cout << "- Book date and time\t: ";
            cout << customer->getBookingHistory().back().date.day << "/" << customer->getBookingHistory().back().date.month << "/" << customer->getBookingHistory().back().date.year;
            cout << " " << customer->getBookingHistory().back().time.hour << ":" << customer->getBookingHistory().back().time.minutes << endl;
            cout << "- Pay and time\t: " << date.day << "/" << date.month << "/" << date.year << " " << time.hour << ":" << time.minutes << endl;
            cout << "- Total bill: " << bill << endl << endl;
            cout << "| 1: Pay" << endl;
            cout << "| 0: Back" << endl;
            cout << "\nEnter: "; cin >> key;
            printEndLine();

            if (key == 0 || key == 1) break;
            else printInvalidKey();
        }

        if (key == 0) continue;

        list<Room>::iterator room = hotel.getListRoom().begin();
        while (room != hotel.getListRoom().end()) {
            if (room->getRoomNumber() == customer->getRoomNumber()) break;
            room++;
        }
        room->checkOutRoom();

        list<BookingHistory> bookingHistory = customer->getBookingHistory();
        BookingHistory checkoutRoom = bookingHistory.back();
        checkoutRoom.date = date;
        checkoutRoom.time = time;
        checkoutRoom.status = OUT;
        bookingHistory.push_back(checkoutRoom);
        customer->setBookingHistory(bookingHistory);

        PayHistory payHistory;
        payHistory.setTotalBill(bill);
        payHistory.setCustomer(*customer);
        hotel.getPayHistory().push_back(payHistory);

        while(1) {
            printBeginLine();
            cout << "- Pay room successfully -\n" << endl;
            cout << "| 1: Continue to pay" << endl;
            cout << "| 0: Back" << endl;
            cout << "\nEnter: "; cin >> key;
            printEndLine();

            if (key == 0 || key == 1) break;
            else printInvalidKey();
        }

        if (key == 0) break;
    }
}

void HotelManager::manageSecurity() {

}

int main() {
    Hotel myHotel;
    HotelManager Hotel_Manager(myHotel);

    return 0;
}