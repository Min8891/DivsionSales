//  Program6DivsionSales
//  Created by Minjing Liang on 10/2/20.
//  Copyright © 2020 Minjing Liang. All rights reserved.
#include <iostream>
#include <iomanip>
using namespace std;
class DivSales{     // declare divition sale class
private:
    static double totalSales;  // two private members
    double quaterSales[4];
public:
    DivSales(){              // default constructor to initial sales to 0
        for(int i = 0; i < 4; i++)
            quaterSales[i] = 0.0;
    }
    // set function
    void setQuaterSales(double q1,double q2, double q3, double q4){
            quaterSales[0] = q1;
            quaterSales[1] = q2;
            quaterSales[2] = q3;
            quaterSales[3] = q4;
            totalSales += q1 + q2 +q3 + q4;
    }
    //get quater sales function
    double getQuaterSales(int n){
        if(n < 0 || n > 3){
            cout << "Error,number need to be from 0-3" << endl;
            return 0;
        }
        else
            return quaterSales[n];
    }
    // get total sales function
    double getTotalSales(){
        return totalSales;
    }
};
double DivSales::totalSales = 0.0;   // static member initialize
int main() {
    DivSales div[6];  // array of objects
    double q1, q2, q3, q4;
        for(int i = 0; i < 6; i++){   // for loop to enter quater sales
            cout << "Enter sales for Division " << (i + 1);
            cout << ": \n";
            cout << "Q1: ";
            cin >> q1;
            if (q1 < 0){
            cout << "Negative number is invalid.\n";
            cout << "Please re-enter" << endl;
                cin >> q1;
            }
            cout << "\nQ2: ";
            cin >> q2;
            if (q2 < 0){
            cout << "Negative number is invalid.\n";
            cout << "Please re-enter" << endl;
                cin >> q2;
            }
            cout << "\nQ3: ";
            cin >> q3;
            if (q3 < 0){
            cout << "Negative number is invalid.\n";
            cout << "Please re-enter" << endl;
                cin >> q3;
            }
            cout << "\nQ4: ";
            cin >> q4;
            if (q4 < 0){
            cout << "Negative number is invalid.\n";
            cout << "Please re-enter" << endl;
                cin >> q4;
            }
            //set the values just read to current object
            div[i].setQuaterSales(q1, q2, q3, q4); // call set function store value
        }
        //display information
        cout << "\n--------------Quarter Sales-------------\n";
        cout << "\t\t" << setw(8) << "Q1"<< setw(8) << "Q2"<< setw(8) << "Q3"<< setw(8) << "Q4\n";
        cout << "-------------------------------------------\n";
        cout << fixed << setprecision(2);
        for(int i = 0; i < 6; i++){
            cout << "Division " << (i + 1);

            //use loop to display quarter sales
            for(int n = 0; n< 4; n++){
                cout << "\t$" << div[i].getQuaterSales(n);
            }
            cout << endl;
        }
        //use an object to get corporate total sales
        cout << "\nCorporate total sales: $" << div[3].getTotalSales() << endl;
        return 0;
}
