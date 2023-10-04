#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

typedef enum {
    MOTORBIKE,
    CAR
} type_Slot;

class Dimension {
    private:
        float length;
        float width;
    public:
        Dimension(float l, float w) {
            length = l;
            width = w;
        }
        float getLength() {return this->length;}
        float getWidth() {return this->width;}
};

class ParkingSlot {
    private:
        bool isOccupied;
        Dimension size;
    public:
        ParkingSlot(float length, float width) : isOccupied(false), size(length, width) {}

        bool isThisOccupied() {return this->isOccupied;}
        void occupySlot(bool status) {isOccupied = true;}

        Dimension getSize() {return this->size;}

        void printSizeOfSlot();
};

void ParkingSlot::printSizeOfSlot() {
    cout << "Size: " << size.getLength() << " x " << size.getWidth() << endl;
}

class ParkingLot {
    private:
        list<ParkingSlot> slots;
    public:
        ParkingLot(int number_Of_Slots);

        int getAvailableSlots();

        void updateSlot(int number_Of_Slot, bool status_Of_Slot);

        list<ParkingSlot> getListSlots() {return this->slots;}

};

ParkingLot::ParkingLot(int number_Of_Slots) {
    int num = 1;
    while (num <= number_Of_Slots) {
        ParkingSlot parkingSlot(4.5, 2.5);
        slots.push_back(parkingSlot);
        num++;
    }
}

int ParkingLot::getAvailableSlots() {
    int count = 1;
    list<ParkingSlot>::iterator slot = slots.begin();
    while (slot != slots.end()) {
        if(!slot->isThisOccupied()) count++;
        slot++;
    }
    return count;
}

void ParkingLot::updateSlot(int number_Of_Slot, bool status_Of_Slot) {
    int count = 1;
    list<ParkingSlot>::iterator slot = slots.begin();
    while (slot != slots.end()) {
        if(count == number_Of_Slot) break;
        else count++;
        slot++;
    }

    if (slot != slots.end()) {
        slot->occupySlot(true);
    }
}

class Car {
    private:
        string licensePlate;
        Dimension size;
    public:
        Car(string licensePlate, float length, float width) : licensePlate(licensePlate), size(length, width) {}
        string getLicense() {return this->licensePlate;}
        Dimension getSize() {return this->size;}

        void setLicense(string license) {this->licensePlate = license;}
        void setSize(Dimension size) {this->size = size;}

        ParkingSlot findParkingSlot(vector<ParkingSlot>& slots);

        void canPark(ParkingSlot slot);
};

ParkingSlot Car::findParkingSlot(vector<ParkingSlot>& slots) {
    int i = 0;

    while (i < slots.size()) {
        if (slots[i].getSize().getLength() >= this->size.getLength() && slots[i].getSize().getWidth() >= this->size.getWidth()) break;
        i++;
    }
    return slots[i];
}



void Car::canPark(ParkingSlot slot) {
    if (slot.isThisOccupied()) cout << "- Can't park in this slot\n";
    else cout << "- Can park in this slot\n";
}

int main() {
    vector<ParkingSlot> slots = {
        ParkingSlot(4.5, 2.5),
        ParkingSlot(5.0, 2.6),
        ParkingSlot(4.2, 2.2)
    };

    Car myCar("XYZ 123", 4.3, 2.3);

    // In thông báo có vị trí phù hợp hay không
    ParkingSlot slot = myCar.findParkingSlot(slots);

    // In kích thước vị trí đó
    slot.printSizeOfSlot();

    // kiểm tra xe có đậu được không
    myCar.canPark(slot);

    return 0;
}