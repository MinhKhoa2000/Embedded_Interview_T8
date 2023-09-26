#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <list>

using namespace std;


// define macro

#define ERROR(...) \
    cout << "<ERROR>: ";\
    cout <<  __VA_ARGS__;\
    cout << ", please enter again!!!" << endl;

#define CHECK_LIST_EMPTY(list) \
    if (list.empty())\
    {\
        cout << "\n# Menu is empty. Return to [ MANAGER ]" << endl;\
        break;\
    }


// define enum

enum MainOption
{
    MAGAGER = 1,
    STAFF = 2,
    EXIT = 0
};

enum ManagerOption
{
    SET_TABLE = 1,
    ADD_DISH = 2,
    UPDATE_DISH = 3,
    DELETE_DISH = 4,
    SHOW_MENU = 5,
    RETURN_OPTION = 0
};


// define class

class dish
{
    private:
        int ID;
        string NAME;
        int PRICE;

    public:
        dish(string name, int price);

        int getID();
        string getNAME();
        int getPrice();
        
        void setID(int id);
        void setNAME(string newName);
        void setPrice(int newPrice);
};

class dishOnTable: public dish
{
    private:
        int AMOUNT;

    public:
        dishOnTable(int id, string name, int price, int amount);

        void setAmount(int amount);

        int getAmount();
};

class table
{
    private:
        int ID;
        bool STATUS;
        list<dishOnTable> databaseDishOnTable;

    public:
        table(int numberTable);

        void setStatus(bool statusTable);

        int getID();
        bool getStatus();
        list<dishOnTable>& getDatabaseDishOnTable();
};


// define function

// draw a border line
void line(int times);

/* manager - start */
    
    void initTable(list<table>& databaseTable, int numberTable);
    void setTable(list<table>& databaseTable);

    void showDish(list<dish>::iterator dish);
    void printDishOnMenu(list<dish> databaseDishOnMenu);
    bool checkName(list<dish> databaseDishOnMenu, string name);
    void addDish(list<dish>& databaseDishOnMenu);


    void updateName(list<dish>& databaseDishOnMenu, list<dish>::iterator iterUpdateName);
    void updatePrice(list<dish>::iterator iterUpdatePrice);
    void updateDish(list<dish>& databaseDishOnMenu);
   
    void deleteDish(list<dish>& databaseDishOnMenu);

    void showMenu(list<dish> databaseDishOnMenu);

    void manager(list<dish>& databaseDishOnMenu, list<table>& databaseTable);
/* manager - end */


/* staff - start */

    void printTableList(list<table> TableList);

    void addDishOnTable(list<table>::iterator& Table, list<dish> databaseDishOnMenu);

    void printDishOnTable(list<dishOnTable>::iterator DishOnTable);
    void printDishListOnTable(list<dishOnTable> DishListOnTable);

    void deleteDishOnTable(list<table>::iterator& Table);

    void showDishListOnTable(list<table>::iterator& Table);

    void payForThisTable(list<table>::iterator& Table);

    void modifyTable(list<table>::iterator& Table, list<dish> databaseDishOnMenu);

    void staff(list<dish> databaseDishOnMenu, list<table>& databaseTable);
/* staff - end */


// main

void option(list<dish>& databaseDishOnMenu, list<table>& databaseTable);

#endif