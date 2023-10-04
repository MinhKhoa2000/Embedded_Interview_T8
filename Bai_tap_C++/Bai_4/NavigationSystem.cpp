#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

class NavigateSystem {
    private:
        vector<vector<int>> parkingMap;
        Position currentPosition;
    public:
        NavigateSystem(vector<vector<int>> map, Position pos) : parkingMap(map), currentPosition(pos) {}

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
    cout << " is " << horizontalLength + verticalLength << " km long.\n";

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
    vector<vector<int>> parkingMap = {
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };

    NavigateSystem naviSys(parkingMap, Position(0, 0));

    Position targetPos(2, 2);

    naviSys.calculateRoute(targetPos);

    naviSys.guideMovement(targetPos);
    
    return 0;
}

