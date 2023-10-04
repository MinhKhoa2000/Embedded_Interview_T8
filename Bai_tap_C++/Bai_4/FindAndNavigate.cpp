#include <iostream>
#include <string>
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

class Position {
    private:
        int x;
        int y;
    public:
        Position(int x = 0, int y = 0) : x(x), y(y) {}

        bool opertor(Position other) {
            return (x == other.x && y == other.y);
        }

        int getX() {return this->x;}
        int getY() {return this->y;}

        void setX(int x) {this->x = x;}
        void setY(int y) {this->y = y;}

        void printPosition();
};

void Position::printPosition() {
    cout << "(" << x << "," << y << ")";
}

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
    cout << "Size of slot: " << size.getLength() << " x " << size.getWidth() << endl;
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

        Position findParkingSlot(vector<vector<ParkingSlot>> slots);

        void printSizeOfCar();

        void canPark(ParkingSlot slot);
};

Position Car::findParkingSlot(vector<vector<ParkingSlot>> slots) {
    float l = size.getLength();
    float w = size.getWidth();
 
    for (int i = 0; i < slots.size(); i++) {
        for (int j = 0; j < slots[i].size(); j++) {
            if (slots[i][j].getSize().getLength() > l && slots[i][j].getSize().getWidth() > w) {
                Position pos(i, j);
                cout << "\n- Found 1 slot to park car -\n";
                slots[i][j].printSizeOfSlot();
                cout << "Position: "; pos.printPosition(); cout << "\n";
                return pos;
            }
        }
    }
}

void Car::printSizeOfCar() {
    cout << "- Size of car: " << size.getLength() << " x " << size.getWidth() << endl;

}

void Car::canPark(ParkingSlot slot) {
    if (slot.isThisOccupied()) cout << "- Can't park in this slot\n";
    else cout << "- Can park in this slot\n";
}

class NavigateSystem {
    private:
        vector<vector<ParkingSlot>> parkingMap;
        Position currentPosition;
    public:
        NavigateSystem(vector<vector<ParkingSlot>> map, Position pos) : parkingMap(map), currentPosition(pos) {}

        void calculateRoute(Position targetPosition);

        void guideMovement(Position targetPosition);

        void setCurrentPosition(Position pos) {this->currentPosition = pos;}

        Position getCurrentPosition() {return this->currentPosition;}
};

void NavigateSystem::calculateRoute(Position targetPosition) {
    int verticalLength = abs(currentPosition.getX() - targetPosition.getX());
    int horizontalLength = abs(currentPosition.getY() - targetPosition.getY());

    cout << "\n----------------------------------------------\n";
    cout << " Current position  : "; currentPosition.printPosition(); cout << endl;
    cout << " Target position   : "; targetPosition.printPosition(); cout << endl;
    cout << "\n- The route from "; currentPosition.printPosition();
    cout << " to "; targetPosition.printPosition();
    cout << " is " << (horizontalLength + verticalLength) * 2.5 << " m long.\n";

    Position curPos = this->currentPosition;

    cout << "\n- Route: "; curPos.printPosition();

    while (!curPos.opertor(targetPosition)) {
        cout << " -> ";

        if (curPos.getX() != targetPosition.getX()) {
            
            int x = curPos.getX();
            if (x < targetPosition.getX()) curPos.setX(++x);
            else if (x > targetPosition.getX()) curPos.setX(--x);
            curPos.printPosition();
            continue;
        }
        if (curPos.getY() != targetPosition.getY()) {
            int y = curPos.getY();
            if (y < targetPosition.getY()) curPos.setY(++y);
            else if (y > targetPosition.getY()) curPos.setY(--y);
            curPos.printPosition();
            continue;
        }
    }

    cout << "\n----------------------------------------------\n\n";
}

void NavigateSystem::guideMovement(Position targetPosition) {
    cout << "\n----------------------------------------------\n";
    cout << "- Begin at "; currentPosition.printPosition(); cout << "\n\n";

    Position curPos = this->currentPosition;

    while (!curPos.opertor(targetPosition)) {
        cout << " from "; curPos.printPosition();

        if (curPos.getX() != targetPosition.getX()) {
            
            int x = curPos.getX();

            if (x < targetPosition.getX()) {
                cout << " go down to ";
                curPos.setX(++x);
            }
            else if (x > targetPosition.getX()) {
                cout << " go up to ";
                curPos.setX(--x);
            }
            curPos.printPosition(); cout << endl;
            continue;
        }
        if (curPos.getY() != targetPosition.getY()) {

            int y = curPos.getY();

            if (y < targetPosition.getY()) {
                cout << " turn right to ";
                curPos.setY(++y);
            }
            else if (y > targetPosition.getY()) {
                cout << " turn left to ";
                curPos.setY(--y);
            }
            curPos.printPosition(); cout << endl;
            continue;
        }
    }

    cout << "\n- "; curPos.printPosition();
    cout << " is the end of the route.\n";
    cout << "----------------------------------------------\n\n";
}

int main() {
    vector<vector<ParkingSlot>> slots = {
        {
            ParkingSlot(4.0, 3.0), ParkingSlot(4.0, 2.0), ParkingSlot(4.1, 2.1)
        },
        {
            ParkingSlot(4.2, 2.2), ParkingSlot(4.3, 2.3), ParkingSlot(4.4, 2.4)
        },
        {
            ParkingSlot(4.5, 2.5), ParkingSlot(4.6, 2.6), ParkingSlot(4.7, 2.7)
        }
    };

    Car myCar("XYZ 123", 4.3, 2.3);

    cout << endl;
    myCar.printSizeOfCar();

    Position pos;

    pos = myCar.findParkingSlot(slots);

    NavigateSystem naviSys(slots, Position(0,0));

    naviSys.calculateRoute(pos);

    naviSys.guideMovement(pos);

    return 0;
}

