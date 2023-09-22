#include "func.h"

student::student(string name, int age, typeGender gender, double grade_Math, double grade_Physic, double grade_Chemistry)
{
    static int id = 1000;
    student::ID = id;
    id++;

    NAME = name;
    AGE = age;
    GENDER = gender;

    this->grade_Math = grade_Math;
    this->grade_Physic = grade_Physic;
    this->grade_Chemistry = grade_Chemistry;
}

void addStudent(list<student>& databaseStudent)
{
    while (1)
    {
        string name;
        while (1)
        {
            cout << "---------------" << endl;
            cout << "input name: ";
            cin >> name;
            if (name != "") break;
        }

        int age;
        while (1)
        {
            cout << "input age: ";
            cin >> age;
            if (age > 18 && age < 50) break;
            else cout << "Error, invalid input!" << endl;
        }
        
        typeGender gender;
        cout << "Choose gender: (1)-male; (2)-female" << endl;
        int key;
        while (1)
        {
            cout << "input gender: ";
            cin >> key;
            switch (key)
            {
            case 1:
                gender = MALE;
                break;
            
            case 2:
                gender = FEMALE;
                break;

            default:
                cout << "Error, invalid input!" << endl;
                break;
            }
            if (key == 1 || key == 2) break;
        }
        
        double grade_Math;
        while (1)
        {
            cout << "input grade math: ";
            cin >> grade_Math;
            if(grade_Math >= 0 && grade_Math <= 10) break;
            else cout << "Error, invalid input!" << endl;
        }
        
        double grade_Physic;
        while (1)
        {
            cout << "input grade physic: ";
            cin >> grade_Physic;
            if(grade_Physic >= 0 && grade_Physic <= 10) break;
            else cout << "Error, invalid input!" << endl;
        }

        double grade_Chemistry;
        while (1)
        {
            cout << "input grade chemistry: ";
            cin >> grade_Chemistry;
            if(grade_Chemistry >= 0 && grade_Chemistry <= 10) break;
            else cout << "Error, invalid input!" << endl;
        }

        student newStudent (name, age, gender, grade_Math, grade_Physic, grade_Chemistry);
        databaseStudent.push_back(newStudent);

        cout << "Add student successfully!" << endl;
        cout << "---------------" << endl;
        cout <<  "1: Continue\n0: Return to menu" << endl;
        cout << "Press: ";
        cin >> key;
        while (key != 1 && key != 0)
        {
            cout << "Error, invalid input!\nPress again: " << endl;
            cin >> key;
        }
        if (key == 1) continue;
        else if (key == 0) break;
    }
}

void updateStudent(list<student>& databaseStudent)
{
    cout << "---------------" << endl;
    int id;
    cout << "Choose ID: ";
    cin >> id;

    for (list<student>::iterator iter = databaseStudent.begin(); iter != databaseStudent.end(); iter++)
    {
        if (iter->getID() == id)
        {
            while (1)
            {
                cout << "Select:" << endl;
                cout << "(1): update name\n(2): update gender\n(3): update age\n(4): update math grade\n(5): update physic grade\n(6): update chemistry grade" << endl;
                cout << "Press: ";
                int key;
                string name;
                cin >> key;
                switch (key)
                {
                    case 1:
                        cout << "old name: " << iter->getNAME() << endl;
                        cout << "update name: ";
                        cin >> name;
                        iter->setNAME(name);
                        cout << "Update sucessfully!" << endl;
                        break;

                    case 2:
                        cout << "old gender: ";
                        if (iter->getGENGER() == 1) cout << "male" << endl;
                        else cout << "Female" << endl;
                        
                        typeGender gender;
                        while (1)
                        {
                            cout << "update gender (1-male; 2-female): ";
                            cin >> key;
                            switch (key)
                            {
                            case 1:
                                iter->setGENDER(MALE);
                                break;
                            
                            case 2:
                                iter->setGENDER(FEMALE);
                                break;

                            default:
                                break;
                            }
                            if (key == 1 || key == 2) break;
                            else cout << "Error, invalid input!" << endl;
                        }
                        cout << "Update sucessfully!" << endl;
                        break;

                    case 3:
                        cout << "old age: " << iter->getAGE() << endl;
                        int age;
                        while (1)
                        {
                            cout << "update age: ";
                            cin >> age;
                            if (age >= 18 && age < 50)
                            {
                                iter->setAGE(age);
                                break;
                            }
                            else cout << "Error, invalid input!" << endl;
                        }
                        cout << "Update sucessfully!" << endl;
                        break;

                    case 4:
                        cout << "old math grade: " << iter->getGradeMath() << endl;
                        int gradeMath;
                        while (1)
                        {
                            cout << "update math grade: ";
                            cin >> gradeMath;
                            if (gradeMath >= 0 && gradeMath <= 10)
                            {
                                iter->setGradeMath(gradeMath);
                                break;
                            }
                            else cout << "Error, invalid input!" << endl;
                        }
                        cout << "Update sucessfully!" << endl;
                        break;

                    case 5:
                        cout << "old physic grade: " << iter->getGradePhysic() << endl;
                        int gradePhysic;
                        while (1)
                        {
                            cout << "update physic grade: ";
                            cin >> gradePhysic;
                            if (gradePhysic >= 0 && gradePhysic <= 10)
                            {
                                iter->setGradePhysic(gradePhysic);
                                break;
                            }
                            else cout << "Error, invalid input!" << endl;
                        }
                        cout << "Update sucessfully!" << endl;
                        break;

                    case 6:
                        cout << "old chemistry grade: " << iter->getGradeChemistry() << endl;
                        int gradeChemistry;
                        while (1)
                        {
                            cout << "update chemistry grade: ";
                            cin >> gradeChemistry;
                            if (gradeChemistry >= 0 && gradeChemistry <= 10)
                            {
                                iter->setGradeChemistry(gradeChemistry);
                                break;
                            }
                            else cout << "Error, invalid input!" << endl;
                        }
                        cout << "Update sucessfully!" << endl;
                        break;
                    
                    default:
                        cout << "Error, invalid input!" << endl;
                        break;
                }
                cout << "---------------" << endl;
                cout << "1: Continue\n0: Return to menu" << endl;
                cout << "Press: ";
                cin >> key;
                while (key != 1 && key != 0)
                {
                    cout << "Error, invalid input!\nPress again: " << endl;
                    cin >> key;
                }
                if (key == 0) break;
            }
            return;
        }
        
    }
    cout << "can't find ID!" << endl;
}

void eraseStudent(list<student>& databaseStudent)
{
    cout << "---------------" << endl;
    int id;
    cout << "Choose ID: ";
    cin >> id;

    for (list<student>::iterator iter = databaseStudent.begin(); iter != databaseStudent.end(); iter++)
    {
        if (iter->getID() == id)
        {
            iter = databaseStudent.erase(iter);
            return;
        }
    }

    cout << "can't find ID!" << endl;
}

void findStuden(list<student>& databaseStudent)
{
    cout << "---------------" << endl;
    cout << "Name to find: ";
    string name;
    cin >> name;

    for (list<student>::iterator iter = databaseStudent.begin(); iter != databaseStudent.end(); iter++)
    {
        if (iter->getNAME() == name)
        {
            cout << "\nInformation of " << "[" << name << "]" << ":" << endl;
            cout << "gender: ";
            if(iter->getGENGER() == 1){
                cout << "Male" << endl;
            }
            else cout << "Female" << endl;
            cout << "age: " << iter->getAGE() << endl;
            cout << "- Math: " << iter->getGradeMath() << endl;
            cout << "- Physic: " << iter->getGradePhysic() << endl;
            cout << "- Chemistry: " << iter->getGradeChemistry() << endl;
            return;
        }
    }

    cout << "can't find name!" << endl;
}

void sortAverageGrade(list<student>& databaseStudent)
{
    for (list<student>::iterator iter = databaseStudent.begin(); iter != databaseStudent.end(); iter++)
    {
        list<student>::iterator temp = iter;
        for (list<student>::iterator iterCompare = iter; iterCompare != databaseStudent.end(); iterCompare++)
        {
            if (iterCompare->getAverageGrade() < iter->getAverageGrade())
            {
                temp = iterCompare;
            }
        }
        if (temp != iter) iter_swap(iter, temp);
    }
}

void sortNameAlphabetically(list<student>& databaseStudent)
{
    for (list<student>::iterator iter = databaseStudent.begin(); iter != databaseStudent.end(); iter++)
    {
        list<student>::iterator temp = iter;
        for (list<student>::iterator iterCompare = iter; iterCompare != databaseStudent.end(); iterCompare++)
        {
            if (iterCompare->getNAME() < iter->getNAME())
            {
                temp = iterCompare;
            }
        }
        if (temp != iter) iter_swap(iter, temp);
    }
}

void printList(list<student> databaseStudent)
{
    int number = 1;
    cout << "---------------" << endl;
    cout << "List of student\n" << endl;
    for (list<student>::iterator iter = databaseStudent.begin(); iter != databaseStudent.end(); iter++)
    {
        cout << number;
        cout << " | ID: " << iter->getID();
        cout << " | name: " << iter->getNAME() << endl;
        number++;
    }
}