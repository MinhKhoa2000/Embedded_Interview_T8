#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum
{
    MALE = 1,
    FEMALE
} typeGender;

class student
{
    private:
        int ID;
        string NAME;
        int AGE;
        typeGender GENDER;
        double grade_Math;
        double grade_Physic;
        double grade_Chemistry;

    public:
        student(string name, int age, typeGender gender, double grade_Math, double grade_Physic, double grade_Chemistry);

        int getID() {return ID;}

        string getNAME() {return NAME;}
        void setNAME(string name) {NAME = name;}

        int getAGE() {return AGE;}
        void setAGE(int age) {AGE = age;}

        typeGender getGENGER() {return GENDER;}
        void setGENDER(typeGender gender) {GENDER = gender;}

        double getGradeMath() {return grade_Math;}
        void setGradeMath(double newGradeMath) {grade_Math = newGradeMath;}

        double getGradePhysic() {return grade_Physic;}
        void setGradePhysic(double newGradePhysic) {grade_Physic = newGradePhysic;}

        double getGradeChemistry() {return grade_Chemistry;}
        void setGradeChemistry(double newGradeChemistry) {grade_Chemistry = newGradeChemistry;}

        double getAverageGrade() {return (grade_Math + grade_Physic + grade_Chemistry)/3;}
};

void addStudent(list<student>& databaseStudent);

void updateStudent(list<student>& databaseStudent);

void eraseStudent(list<student>& databaseStudent);

void findStuden(list<student>& databaseStudent);

void sortAverageGrade(list<student>& databaseStudent);

void sortNameAlphabetically(list<student>& databaseStudent);

void printList(list<student> databaseStudent);

#endif