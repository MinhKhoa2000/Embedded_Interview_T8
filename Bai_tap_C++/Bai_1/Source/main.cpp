#include <iostream>
#include "func.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // 1: thêm sinh viên (x)
    // 2: cập nhập sinh viên bằng ID (x)
    // 3: xóa sinh viên bằng ID (x)
    // 4: tìm kiếm theo tên, in ra các thông tin (x)
    // 5: sắp xếp theo điểm trung bình (x)
    // 6: sắp xếp theo tên (x)
    // 7: hiện thị danh sách sinh viên (x)

    list<student> databaseStudent;

    int key = 0;

    while (1)
    {
        cout << "---------------" << endl;
        cout << "1: Add student" << endl;
        cout << "2: Update by ID" << endl;
        cout << "3: Erase by ID" << endl;
        cout << "4: Find by name, show information" << endl;
        cout << "5: Sorted by average grade" << endl;
        cout << "6: Sorted by name alphabetically" << endl;
        cout << "7: Show all list" << endl;
        cout << "Press: ";
        cin >> key;

        switch (key)
        {
        case 1:
            addStudent(databaseStudent);
            break;

        case 2:
            updateStudent(databaseStudent);
            break;

        case 3:
            eraseStudent(databaseStudent);
            break;

        case 4:
            findStuden(databaseStudent);
            break;

        case 5:
            sortAverageGrade(databaseStudent);
            break;

        case 6:
            sortNameAlphabetically(databaseStudent);
            break;

        case 7:
            printList(databaseStudent);
            break;
        
        default:
            cout << "Error, invalid input!" << endl;
            break;
        }

        cout << "---------------" << endl;
        cout << "1: Continue\n0: Exit" << endl;
        cout << "Press: ";
        cin >> key;
        while (1)
        {
            if (key == 0 || key == 1) break;
            else
            {
                cout << "Error, invalid input!" << endl;
                cout << "Press again: ";
                cin >> key;
            }
        }
        if (key == 0) break;
    }

    return 0;
}