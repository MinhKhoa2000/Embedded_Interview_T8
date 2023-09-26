#include "func.h"

/* class method */

    /* class 'dish' */

        dish::dish(string name, int price)
        {
            static int id = 100;
            ID = id;
            id++;
            NAME = name;
            PRICE = price; 
        }

        int dish::getID() {return ID;}

        string dish::getNAME() {return NAME;}

        int dish::getPrice() {return PRICE;}

        void dish::setID(int id) {ID = id;}

        void dish::setNAME(string newName) {NAME = newName;}

        void dish::setPrice(int newPrice) {PRICE = newPrice;}


    /* class 'dishOnTable' */

        dishOnTable::dishOnTable(int id, string name, int price, int amount)
        : dish(name, price)
        {
            setID(id);
            setNAME(name);
            setPrice(price);
            AMOUNT = amount;
        }

        void dishOnTable::setAmount(int amount) {AMOUNT = amount;}

        int dishOnTable::getAmount() {return AMOUNT;}


    /* class 'table' */

        table::table(int id)
        {
            ID = id;
            STATUS = 0;
        }

        void table::setStatus(bool status) {STATUS = status;}

        int table::getID() {return ID;}

        bool table::getStatus() {return STATUS;}

        list<dishOnTable>& table::getDatabaseDishOnTable() {return databaseDishOnTable;}


/* function */

    /* draw line */
        void line(int times)
        {
            cout << endl;
            for (int i = 0; i < times; i++)
            {
                cout << "-";
            }
            cout << endl;
        }


    /* manager - start */

        void initTable(list<table>& databaseTable, int numberTable)
        {
            for (int tableOrder = 0; tableOrder < numberTable; tableOrder++)
            {
                table Table(tableOrder + 1);
                databaseTable.push_back(Table);
            }
            line(5);
            cout << "\n# Set " << numberTable << " table successfully!" << endl;
        }

        // manager - option 1
        void setTable(list<table>& databaseTable)
        {
            int key;
            int numberTable;

            while (1)
            {
                line(20);
                cout << "[ MANAGER ] < Set table >\n" << endl;
                cout << "1: Set number of table\n0: Return to [ MANAGER ]\n" << endl;
                cout << "Enter: ";
                cin >> key;
                if (key == 0) break;
                else if (key != 1)
                {
                    ERROR("Invalid input")
                    continue;
                }

                while (1)
                {
                    line(10);
                    cout << "Enter number of table: ";
                    cin >> numberTable;
                    if (numberTable < 0)
                    {
                        ERROR("Number must be greater than 0")
                        continue;
                    }
                    else if (numberTable == 0)
                    {
                        while (1)
                        {
                            line(5);
                            cout << "# No table is set\n" << endl;
                            cout << "1: Continue to set number of table\n0: Return to [ MANAGER ] < Set table >\n" << endl;
                            cout << "Enter: ";
                            cin >> key;
                            if (key == 1 || key == 0) break;
                            else {ERROR("Invalid input")} 
                        }
                        if (key == 1) continue;
                        else if (key == 0) break;
                    }
                    else 
                    {
                        initTable(databaseTable, numberTable);
                        break;
                    }
                }

                if (numberTable > 0) break;
                if (key == 0) continue;
            }
        }

        void showDish(list<dish>::iterator dish)
        {
            cout << "| ID\t| Name\t| Price\t|" << endl;
            cout << "| " << dish->getID() << "\t| " << dish->getNAME() << "\t| " << dish->getPrice() << "\t|" << endl;
        }

        void printDishOnMenu(list<dish> databaseDishOnMenu)
        {
            cout << "\n- Menu -" << endl;
            cout << "| ID\t| Name\t| Price\t|" << endl;
            for (list<dish>::iterator iter = databaseDishOnMenu.begin(); iter != databaseDishOnMenu.end(); iter++)
            {
                cout << "| " << iter->getID() << "\t| " << iter->getNAME() << "\t| " << iter->getPrice() << "\t|" << endl;
            }
            cout << endl;
        }

        // Check to see if there are any duplicate names
        bool checkName(list<dish> databaseDishOnMenu, string name)
        {
            for (list<dish>::iterator iter = databaseDishOnMenu.begin(); iter != databaseDishOnMenu.end(); iter++)
            {
                if (iter->getNAME() == name) return 0;
            }
            return 1;
        }

        // manager - option 2
        void addDish(list<dish>& databaseDishOnMenu)
        {
            int key;
            
            while (1)
            {
                line(20);
                cout << "[ MANAGER ] < Add dish >\n" << endl;
                if (!databaseDishOnMenu.empty())
                {
                    printDishOnMenu(databaseDishOnMenu);
                }
                cout << "1: Add\n0: Return to [ MANAGER ]\n" << endl;
                cout << "Enter: ";
                cin >> key;
                
                if (key == 0) break;
                else if (key != 1) 
                {
                    ERROR("Invalid input")
                    continue;
                }
                
                line(10);
                string name;
                while (1)
                {
                    cout << "\nName: ";
                    cin >> name;
                    if (checkName(databaseDishOnMenu, name)) break;
                    else ERROR("Name already exists")
                }

                int price;
                while (1)
                {
                    cout << "\nPrice: ";
                    cin >> price;
                    if (price > 0) break;
                    else ERROR("Price must be greater than 0")
                }

                dish newDish(name, price);
                databaseDishOnMenu.push_back(newDish);

                cout << "\n- Add successfully -" << endl;
                cout << "| ID\t| Name\t| Price\t|" << endl;
                cout << "| " << newDish.getID() << "\t| " << newDish.getNAME() << "\t| " << newDish.getPrice() << "\t|" << endl;
                
                while (1)
                {
                    line(20);
                    cout << "1: Continue to < Add dish >\n0: Return to [ MANAGER ]" << endl;
                    cout << "\nEnter: ";
                    cin >> key;
                    if (key == 0 || key == 1) break;
                    else ERROR("Invalid input")
                }
                if (key == 0) break; 
            }
        }
        
        void updateName(list<dish>& databaseDishOnMenu, list<dish>::iterator iterUpdateName)
        {
            string updateName;
            bool checkName;

            while (1)
            {
                checkName = false;
                line(5);
                cout << "Old name: " << iterUpdateName->getNAME() << endl;
                cout << "Update name: ";
                cin >> updateName;

                for (list<dish>::iterator iter = databaseDishOnMenu.begin(); iter != databaseDishOnMenu.end(); iter++)
                {
                    if (iter != iterUpdateName && iter->getNAME() == updateName)
                    {
                        checkName = true;
                        break;
                    }
                }

                if (checkName) {ERROR("Name already exists")}
                else break;
            }

            iterUpdateName->setNAME(updateName);
        }

        void updatePrice(list<dish>::iterator iterUpdatePrice)
        {
            int updatePrice;
            while (1)
            {
                line(5);
                cout << "Old price: " << iterUpdatePrice->getPrice() << endl;
                cout << "Update price: ";
                cin >> updatePrice;
                if (updatePrice >= 0) break;
                else {ERROR("Price must be greater than 0")}
                
            }
            iterUpdatePrice->setPrice(updatePrice);
        }

        // manager - option 3
        void updateDish(list<dish>& databaseDishOnMenu)
        {
            int key;
            int ID;
            bool checkID = false;

            while (1)
            {
                line(20);
                cout << "[ MANAGER ] < Update dish >" << endl;

                CHECK_LIST_EMPTY(databaseDishOnMenu)
                
                printDishOnMenu(databaseDishOnMenu);
                cout << "1: Update\n0: Return to [ MANAGER ]\n" << endl;
                cout << "Enter: ";
                cin >> key;

                if (key == 0) break;
                else if (key != 1)
                {
                    ERROR("Invalid input")
                    continue;
                }

                line(10);
                cout << "Enter update dish ID: ";
                cin >> ID;

                for (list<dish>::iterator iter = databaseDishOnMenu.begin(); iter != databaseDishOnMenu.end(); iter++)
                {
                    if (iter->getID() == ID)
                    {
                        checkID = true;
                        while (1)
                        {
                            line(10);
                            cout << "- Update dish -" << endl;
                            showDish(iter);

                            cout << "\n1: Update name\n2: Update price\n0: Return to < Update dish > - Enter ID" << endl;
                            cout << "\nEnter: ";
                            cin >> key;

                            switch (key)
                            {
                                case 1:
                                {
                                    updateName(databaseDishOnMenu, iter);
                                    break;
                                }

                                case 2:
                                {
                                    updatePrice(iter);
                                    break;
                                }
                                
                                default:
                                    if (key != 0) 
                                    {
                                        ERROR("Invalid input")
                                        continue;
                                    }
                            }

                            cout << "\n- Update successfully -" << endl;

                            showDish(iter);
                            
                            while (1)
                            {
                                line(10);
                                cout << "1: Continue to update dish ID: " << iter->getID() << endl;
                                cout << "0: Return to [ MANAGER ] < Update dish >" << endl;
                                cout << "\nEnter: ";
                                cin >> key;
                                if (key == 0 || key == 1) break;
                                else {ERROR("Invalid input")}
                            }

                            if (key == 0) break;
                        }
                        break;
                    }
                }
                if (!checkID) {ERROR("Can't find ID")}
            }
        }
        
        // manager - option 4
        void deleteDish(list<dish>& databaseDishOnMenu)
        {
            int key;
            int ID;
            bool checkID = false;

            while (1)
            {
                line(20);
                cout << "[ MANAGER ] < Delete dish >" << endl;

                CHECK_LIST_EMPTY(databaseDishOnMenu)

                printDishOnMenu(databaseDishOnMenu);
                cout << "1: Delete\n0: Return to [ MANAGER ]\n" << endl;
                cout << "Enter: ";
                cin >> key;

                if (key != 0 && key != 1)
                {
                    ERROR("Invalid input")
                    continue;
                }
                else if (key == 0) break;

                line(10);
                cout << "Enter delete dish ID: ";
                cin >> ID;

                list<dish>::iterator iter ;
                for (iter = databaseDishOnMenu.begin(); iter != databaseDishOnMenu.end(); iter++)
                {
                    // tìm thấy, có chác không?
                    // 1: có 0: khong, quay lại ban đầu
                    if (iter->getID() == ID)
                    {
                        while (1)
                        {
                            line(10);
                            cout << "- Delete dish -" << endl;
                            showDish(iter);
                            cout << "\n# Confirm to delete?\n" << endl;
                            cout << "1: Delete\n0: Return to [ MANAGER ] < Delete dish >\n" << endl;
                            cout << "Enter: ";
                            cin >> key;

                            if (key == 1)
                            {
                                line(5);
                                cout << "- Delete successfully -\n" << endl;
                                showDish(iter);
                                iter = databaseDishOnMenu.erase(iter);
                                break;
                            }
                            else if (key == 0) break;
                            else {ERROR("Invalid input")}
                        }
                        break;
                    }
                    
                }
                if (iter == databaseDishOnMenu.end()) 
                {
                    ERROR("Can't find any ID")
                    continue;
                }
                if (key == 0) continue;

                line(10);
                cout << "1: Continue to < Delete dish >\n0: Return to [ MANAGER ]\n" << endl;
                cout << "Enter: ";
                cin >> key;
                if (key == 0) break;
            }
        }

        // manager - option 5
        void showMenu(list<dish> databaseDishOnMenu)
        {
            while (1)
            {
                line(20);
                cout << "[ MANAGER ] < Menu >\n" << endl;

                if (databaseDishOnMenu.empty())
                {
                    cout << "# Menu is empty. Return to [ MANAGER ]" << endl;
                    break;
                }
                
                int numericalOrder = 1;

                cout << "- Menu -" << endl;
                cout << "| No.\t| ID\t| Name\t| Price\t|" << endl;
                for (list<dish>::iterator iter = databaseDishOnMenu.begin(); iter != databaseDishOnMenu.end(); iter++)
                {
                    cout << "| " << numericalOrder;
                    cout << "\t| " << iter->getID() << "\t| " << iter->getNAME() << "\t| " << iter->getPrice() << "\t|" << endl;
                    numericalOrder++;
                }

                cout << "\nEnter 0 to return [ MANAGER ]: ";
                static int key;
                cin >> key;
                if (key == 0) break;
                else {ERROR("Invalid input")}
            }
        }
        
        // main - option 1
        void manager(list<dish>& databaseDishOnMenu, list<table>& databaseTable)
        {
            int key;

            while (1)
            {
                line(50);
                cout << "[ MANAGER ]\n" << endl;
                cout << "1: Set table" << endl;
                cout << "2: Add dish to menu" << endl;
                cout << "3: Update dish on menu" << endl;
                cout << "4: Delete dish on menu" << endl;
                cout << "5: Show menu" << endl;
                cout << "0: Return to [ MAIN OPTION ]\n" << endl;
                cout << "Enter: ";
                cin >> key;

                switch (key)
                {
                case SET_TABLE:
                    setTable(databaseTable);
                    break;

                case ADD_DISH:
                    addDish(databaseDishOnMenu);
                    break;

                case UPDATE_DISH:
                    updateDish(databaseDishOnMenu);
                    break;

                case DELETE_DISH:
                    deleteDish(databaseDishOnMenu);
                    break;

                case SHOW_MENU:
                    showMenu(databaseDishOnMenu);
                    break;
                
                default:
                    if (key != RETURN_OPTION) 
                    {
                        ERROR("Invalid input")
                        continue;
                    }
                }
                if (key == RETURN_OPTION) break;
            }
        }
    /* manager - end */


    /* staff - start */

        void printTableList(list<table> TableList)
        {
            cout << "ID";
            for (list<table>::iterator iter = TableList.begin(); iter !=TableList.end(); iter++)
            {
                cout << "\t| " << iter->getID();
            }
            cout << "\nStatus";
            for (list<table>::iterator iter = TableList.begin(); iter != TableList.end(); iter++)
            {
                cout << "\t| ";
                if (iter->getStatus()) cout << "X";
                else cout << "O";
            }
            cout << endl;
        }

        // staff - option 1
        void addDishOnTable(list<table>::iterator& Table, list<dish> databaseDishOnMenu)
        {
            int key;

            while (1)
            {
                line(20);

                if (databaseDishOnMenu.size() == 0)
                {
                    cout << "\n# Menu is empty. Please choose other option!" << endl;
                    break;
                }

                printDishOnMenu(databaseDishOnMenu);
                cout << "Enter dish ID, or 0 to return to [ Table " << Table->getID() << " ] option: ";
                cin >> key;
                if (key == 0) break;
                
                list<dish>::iterator iter;
                for (iter = databaseDishOnMenu.begin(); iter != databaseDishOnMenu.end(); iter++)
                {
                    if (iter->getID() == key) break;
                }

                if (iter == databaseDishOnMenu.end())
                {
                    line(10);
                    ERROR("Can't find any ID")
                }
                else
                {
                    static int amount;
                    while (1)
                    {
                        line(10);
                        cout << "Enter amount of dish, or 0 to return to < Enter dish ID >: ";
                        cin >> amount;
                        if (amount == 0) break;
                        else if (amount < 0)
                        {
                            ERROR("Amount must be greater than 0")
                            continue;
                        }
                        line(10);
                        cout << "- Add dish on [ Table " << Table->getID() << " ] successfully -\n" << endl;
                        cout << "| ID\t| Name\t| Price\t| Amount|" << endl;
                        cout << "| " << iter->getID() << "\t| " << iter->getNAME() << "\t| " << iter->getPrice() << "\t| " << amount << "\t|" << endl;
                        
                        while (1)
                        {
                            line(5);
                            cout << "1: Continue to add amount of dish | ID: " <<  iter->getID() << " |" << endl;
                            cout << "0: Return to < Enter dish ID >\n" << endl;
                            cout << "Enter: ";
                            cin >> key;
                            if (key == 0 || key == 1) break;
                            else if (key != 1)
                            {
                                ERROR("Invalid input")
                                continue;
                            }
                        }
                        if (key == 0) break;
                    }

                    if (amount != 0)
                    {
                        dishOnTable dishOntable(iter->getID(), iter->getNAME(), iter->getPrice(), amount);
                        Table->getDatabaseDishOnTable().push_back(dishOntable);
                        Table->setStatus(1);
                    }
                }
            }
            
        }

        void printDishOnTable(list<dishOnTable>::iterator DishOnTable)
        {
            int idDishOnTable = DishOnTable->getID();
            string nameDishOnTable = DishOnTable->getNAME();
            int priceDishOnTable = DishOnTable->getPrice();
            int amountDishOnTable = DishOnTable->getAmount();

            cout << "| " << idDishOnTable << "\t| " << nameDishOnTable << "\t| " << priceDishOnTable << "\t| " << amountDishOnTable << "\t|";
            cout << endl;
        }

        void printDishListOnTable(list<dishOnTable> DishListOnTable)
        {
            for (list<dishOnTable>::iterator iter = DishListOnTable.begin(); iter != DishListOnTable.end(); iter++)
            {
                printDishOnTable(iter);
            }
        }

        // staff - option 2
        void deleteDishOnTable(list<table>::iterator& Table)
        {
            int key;

            while (1)
            {
                list<dishOnTable>& DishListOnTable = Table->getDatabaseDishOnTable();

                line(20);
                cout << "[ Table " << Table->getID() << " ] < Delete dish on this table >\n" << endl;

                bool isDishListOnTableEmpty = DishListOnTable.empty();

                if (isDishListOnTableEmpty)
                {
                    cout << "# Dish list on [ Table " << Table->getID() << " ] is empty. Return to [ Table " << Table->getID() << " ] option." << endl;
                    break;
                }
                else {
                    cout << "- Dish list on [ Table " << Table->getID() << " ] -" << endl;
                    cout << "| ID\t| Name\t| Price\t| Amount |" << endl;
                    printDishListOnTable(DishListOnTable);
                }

                while (1) {
                    cout << "\n# Enter ID of dish on [ Table " << Table->getID() << " ] to delete, or 0 to return to [ Table " << Table->getID() << " ] option" << endl;
                    cout << "\nEnter: ";
                    cin >> key;

                    bool isKeyInvalid = key < 0;

                    if (isKeyInvalid) {
                        ERROR("Invalid input")
                        continue;
                    }
                    else break;
                }

                bool chooseReturn = (key == 0);

                if (chooseReturn) break;

                int ID = key;
                
                list<dishOnTable>::iterator chosenDishOnTable;

                for (chosenDishOnTable = DishListOnTable.begin(); chosenDishOnTable != DishListOnTable.end(); chosenDishOnTable++)
                {
                    if (chosenDishOnTable->getID() == ID) break;
                }

                bool found_DishOnTable_ToDelete = chosenDishOnTable != DishListOnTable.end();

                if (found_DishOnTable_ToDelete)
                {
                    while (1) {
                        line(10);
                        cout << "- Dish is choosen to delete on [ Table " << Table->getID() << " ] -" << endl;
                        cout << "| ID\t| Name\t| Price\t| Amount|" << endl;
                        printDishOnTable(chosenDishOnTable);

                        cout << "\n1: Delete this dish out of [ Table " << Table->getID() << " ]" << endl;
                        cout << "0: Choose other dish to delete" << endl;
                        cout << "\nEnter: ";
                        cin >> key;

                        bool chooseDelete = (key == 1);
                        bool chooseOtherDish = (key == 0);

                        if (chooseDelete || chooseOtherDish) break;
                        else {
                            ERROR("Invalid input")
                            continue;
                        }
                    }

                    bool deleteDish = key == 1;
                    bool chooseOtherDish = key == 0;

                    if (deleteDish) {
                        line(10);
                        cout << "# Delete dish on [ Table " << Table->getID() << " ] successfully - " << endl;
                        cout << "- Dish is delete -" << endl;
                        cout << "| ID\t| Name\t| Price\t| Amount|" << endl;
                        printDishOnTable(chosenDishOnTable);

                        DishListOnTable.erase(chosenDishOnTable);
                    }
                    else if (chooseOtherDish) continue;
                }
                else {
                    ERROR("Can't find any dish on table to delete")
                    continue;
                }

                while (1)
                {
                    line(10);
                    cout << "1: Choose other dish to delete" << endl;
                    cout << "0: Return to [ Table " << Table->getID() << " ]" << endl;
                    cout << "\n Enter: ";
                    cin >> key;

                    bool invalidKey = (key != 1) && (key != 0);

                    if (invalidKey) {
                        ERROR("Invalid input")
                        continue;
                    }
                    else break;
                }
                
                if (chooseReturn) break;
            }

            if (Table->getDatabaseDishOnTable().empty()){
                Table->setStatus(0);
            }
        }

        // staff - option 3
        void showDishListOnTable(list<table>::iterator& Table)
        {
            list<dishOnTable> DishListOnTable = Table->getDatabaseDishOnTable();
            int thisTableID = Table->getID();
            int key;

            while (1)
            {
                line(20);
                
                bool isDishListOnTableEmpty = DishListOnTable.empty();

                // return if dish list on table is empty
                if (isDishListOnTableEmpty)
                {
                    cout << "# There is no dish in this table. Return to [ Table " << thisTableID << " ] option" << endl;
                    break;
                } // else continue to print

                cout << "- Dish list on [ Table " << thisTableID << " ] -" << endl;

                // print list of dish on table
                cout << "\n| No.\t| ID\t| Name\t| Price\t| Amount|" << endl;

                list<dishOnTable>::iterator begin = DishListOnTable.begin();
                list<dishOnTable>::iterator end = DishListOnTable.end();
                int numberOrder = 1;

                for (list<dishOnTable>::iterator DishOnTable = begin; DishOnTable != end; DishOnTable++)
                {
                    int id = DishOnTable->getID();
                    string name = DishOnTable->getNAME();
                    int price = DishOnTable->getPrice();
                    int amount = DishOnTable->getAmount();

                    cout << "| " << numberOrder << "\t| " << id << "\t| " << name << "\t| " << price << "\t| " << amount << "\t|";
                    cout << endl;

                    numberOrder++;
                }

                // comfirm to return
                cout << "\nEnter 0 to return to [ Table " << thisTableID << " ] option: ";
                cin >> key;

                bool returnToTableOption = key == 0;

                if (returnToTableOption) break;
                else {ERROR("Invalid input")}
            }
        }

        // staff - option 4
        void payForThisTable(list<table>::iterator& Table)
        {
            int key;
            int thisTableID = Table->getID();

            bool thisTableIsNotBooked = Table->getStatus() == false;

            // return if this table is not booked
            if (thisTableIsNotBooked) {
                line(20);
                cout << "\n# [ Table " << thisTableID << " ] is not booked. Return to this table option" << endl;
                return;
            }
            
            // else continue

            list<dishOnTable>& DishListOnTable = Table->getDatabaseDishOnTable();

            while (1)
            {
                line(20);
                
                cout << "[ Table " << thisTableID << " ] < Pay for this table >" << endl;
                cout << "\n- Bill of this table -" << endl;

                // print list of dish on table
                cout << "| No.\t| ID\t| Name\t| Price\t| Amount|" << endl;

                list<dishOnTable>::iterator begin = DishListOnTable.begin();
                list<dishOnTable>::iterator end = DishListOnTable.end();

                int numberOrder = 1;
                int totalBill = 0;

                for (list<dishOnTable>::iterator DishOnTable = begin; DishOnTable != end; DishOnTable++)
                {
                    int id = DishOnTable->getID();
                    string name = DishOnTable->getNAME();
                    int price = DishOnTable->getPrice();
                    int amount = DishOnTable->getAmount();

                    cout << "| " << numberOrder << "\t| " << id << "\t| " << name << "\t| " << price << "\t| " << amount << "\t|";
                    cout << endl;

                    numberOrder++;
                    totalBill += (price * amount);
                }

                // print total bill
                cout << "\nTotal bill: " << totalBill << " (VND)" << endl;

                // confirm pay or return
                line(10);
                cout << "1: Pay the bill\n0: Return to this table option" << endl;
                cout << "\nEnter: ";
                cin >> key;

                bool isKeyInvalid = (key != 1) && (key != 0);

                // loop if key is incorrect
                if (isKeyInvalid) {
                    ERROR("Invalid input")
                    continue;
                }
                // break if key is correct
                else break;
            }

            // if choosing pay
            bool choosePayTheBill = key == 1;

            if (choosePayTheBill) {
                DishListOnTable.clear();
                Table->setStatus(0);

                line(10);
                cout << "\n- Bill of [ Table " << thisTableID << " ] is paid successfully -" << endl;
                cout << "\n# Return to this table option." << endl;
            }
            // else do nothing and return
        }

        void modifyTable(list<table>::iterator& Table, list<dish> databaseDishOnMenu)
        {
            int key;

            while(1)
            {
                line(20);
                cout << "[ Table " << Table->getID() << " ]" << endl;
                cout << "\n1: Add dish on table " << Table->getID() << endl;
                cout << "2: Delete dish on table " << Table->getID() << endl;
                cout << "3: Dish list on table " << Table->getID() << endl;
                cout << "4: Pay for table " << Table->getID() << endl;
                cout << "0: Return to [ STAFF ]" << endl;
                cout << "\nEnter: ";
                cin >> key;

                if (key < 0 || key > 4)
                {
                    ERROR("Invalid input")
                    continue;
                }

                switch (key)
                {
                case 1:
                    addDishOnTable(Table, databaseDishOnMenu);
                    break;

                case 2:
                    deleteDishOnTable(Table);
                    break;

                case 3:
                    showDishListOnTable(Table);
                    break;

                case 4:
                    payForThisTable(Table);
                    break;
                }

                if (key == 0) break;
            }
        }

        // main - option 2
        void staff(list<dish> databaseDishOnMenu, list<table>& databaseTable)
        {
            int key;

            while(1)
            {
                line(50);
                cout << "[ STAFF ]\n" << endl;

                // return if there is no table
                if (databaseTable.empty()) {
                    cout << "# There is no table. Return to [ MAIN OPTION ]" << endl;
                    break;
                }

                // print list of table
                cout << "- Table list -" << endl;
                printTableList(databaseTable);
                cout << "\nEnter table ID, or 0 to return to [ MAIN OPTION ]: ";
                cin >> key;

                // if key is incorrect
                if (key < 0)
                {
                    ERROR("Invalid input")
                    continue;
                }
                else if (key > databaseTable.size())
                {
                    ERROR("Can't find any table")
                    continue;
                }

                // if choosing return
                else if (key == 0) break;

                // find the table if entering the table ID
                for (list<table>::iterator iter = databaseTable.begin(); iter != databaseTable.end(); iter++)
                {
                    if (iter->getID() == key)
                    {
                        modifyTable(iter, databaseDishOnMenu);
                        break;
                    }
                }

                // choose another table or return
                while(1) {
                    line(20);

                    cout << "1: Continue to modify another table" << endl;
                    cout << "0: Return to [ MAIN OPTION ]" << endl;
                    cout << "\nEnter: ";
                    cin >> key;

                    if (key != 1 && key != 0)
                    {
                        ERROR("Invalid input")
                        continue;
                    }
                    else break;
                }
                if (key == 0) break;
            }
        }
    /* staff - end */


    /* main */
        void option(list<dish>& databaseDishOnMenu, list<table>& databaseTable)
        {
            int key;

            while (1)
            {
                line(50);
                cout << "[ MAIN OPTION ]\n" << endl;
                cout << "1: Manager\n2: Staff\n0: Exit\n" << endl;
                cout << "Enter: ";
                cin >> key;

                if (key < 0 || key > 2)
                {
                    ERROR("Invalid input")
                    continue;
                }

                switch (key)
                {
                case MAGAGER:
                    manager(databaseDishOnMenu, databaseTable);
                    break;

                case STAFF:
                    staff(databaseDishOnMenu, databaseTable);
                    break;
                }

                if (key == EXIT) break;
            }
        }