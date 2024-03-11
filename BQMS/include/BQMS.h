#ifndef BQMS_H
#define BQMS_H
#include<Customer.h>
#include<Teller.h>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


struct CompareByArrivalTime
{
    bool operator()( Customer& c1,  Customer& c2)
    {
        if (c1.getArrival() == c2.getArrival())
        {
            return c1.getVip() < c2.getVip(); // VIP has priority if arrival time is the same
        }
        return c1.getArrival() > c2.getArrival(); // Sort by arrival time
    }
};

class BQMS
{
private:
    Teller tellers[3];
public:
    priority_queue<Customer, vector<Customer>, CompareByArrivalTime> customers;

    int currentTime = 0;
    BQMS()
    {
        tellers[0].setTellerName("Num1");
        tellers[1].setTellerName("Num2");
        tellers[2].setTellerName("Num3");
        tellers[0].setWorking(0);
        tellers[1].setWorking(0);
        tellers[2].setWorking(0);


    }
 void enqueue(Customer const& custm)
    {
        customers.push(custm);
    }
    void addCustomer() {
        string name;
        int  arrival, service;
        bool vip;
        int numOfCustomer;
        cout << "Enter Number of Customers : ";
        cin>>numOfCustomer;
        for(int i=0;i<numOfCustomer;i++){
        cout << "Enter customer Name: ";
        cin >> name;
        cout << "Enter arrival time: ";
        cin >> arrival;
        cout << "Enter service time: ";
        cin >> service;
        cout << "If the customer has special needs or elderly customer or premium account  ? (1 for Yes, 0 for No):  ";
        cin >> vip;
        Customer newCustomer(name, arrival, service, vip);
        enqueue(newCustomer);
        }
    }

    void dequeue()
    {
        if (!customers.empty())
        {

        }            customers.pop();
    }
    int Size()
    {
        return customers.size();
    }
    Customer const & first()
    {
        return customers.top();
    }
    bool isempty()
    {
        if (customers.empty())
            return true;
    }
    void printTableRow(const string& col1, const string& col2, const string& col3,const string& col4, const string& col5) {
    cout << "| " << setw(20) << left << col1 << " | " << setw(13) << left << col2 << " | " << setw(13) << left << col3 << " | " << setw(13) << left << col4  << " | " << setw(13) << left << col5<< endl;
}
void printTableRow1(const string& col1, const string& col2, const string& col3, const string& col4) {
    cout << "| " << setw(20) << left << col1 << " | " << setw(25) << left << col2 << " | " << setw(15) << left << col3 << " | " << setw(15) << left << col4 << " |" << endl;
}
void printTableHeader() {
    cout << "+----------------------+---------------+---------------+---------------+---------------+" << endl;
    printTableRow("Customer Name", "Arrival Time","Waiting Time" ,"Service Time", "Leave Time");
    cout << "+----------------------+---------------+---------------+---------------+---------------+" << endl;
}
void printTableHeader2() {
    cout << "+--------------------------------------------------------------------------------+" << endl;
    printTableRow1("Teller Name", "Total Service Time", "Utilization", "Num of Services");
    cout << "+--------------------------------------------------------------------------------+" << endl;
}

    void Simulate()
    {
        int numCus=Size();
        double avgWaiting=0;
        while(!customers.empty())
        {
            Customer curCustomer= first();
            customers.pop();
            int minTime=tellers[0].getWorkingTime();
            int indexMin=0;
            for(int i=0; i<3; i++)
            {
                if(minTime>tellers[i].getWorkingTime())
                {
                    minTime=tellers[i].getWorkingTime();
                    indexMin=i;
                }
            }

            if(!tellers[indexMin].isBusy())
            {
                avgWaiting+=curCustomer.getWaitingTime();
                tellers[indexMin].setBusy(true);
                curCustomer.setExit(curCustomer.getArrival()+curCustomer.getService()+curCustomer.getWaitingTime());
                tellers[indexMin].setWorking(curCustomer.getArrival()+curCustomer.getService()+curCustomer.getWaitingTime());
                tellers[indexMin].numService++;
                printTableHeader();
                printTableRow(curCustomer.getName(), to_string(curCustomer.getArrival()),to_string(curCustomer.getWaitingTime()), to_string(curCustomer.getService()), to_string(curCustomer.getExit()));
                cout << "+----------------------+---------------+---------------+---------------+---------------+" << endl;

            }
            else // tellers are full
            {
                if(tellers[indexMin].getWorkingTime()<=curCustomer.getArrival())  //newcustomer
                {
                    curCustomer.setwaitingTime(0);
                }
                else // less one is busy  all are busy
                {
                    // waiting_que.push(curCustomer);
                    curCustomer.setwaitingTime(tellers[indexMin].getWorkingTime()-curCustomer.getArrival());
                }
                avgWaiting+=curCustomer.getWaitingTime();
                tellers[indexMin].setBusy(false);
                enqueue(curCustomer);
            }
        }

        cout<<"\n\nAverage Waiting Time: "<<avgWaiting/numCus<<"\n\n";
        printTableHeader2();

        for (int i = 0; i < 3; ++i) {
        cout << "| " << setw(20) << left << tellers[i].getTellerName() << " | "
             << setw(18) << left << tellers[i].getWorkingTime() << " | "
             << setw(10) << left << ((tellers[i].numService) / numCus) * 100 << "% | "
             << setw(10) << left << tellers[i].numService << endl;
    }

    cout << "+--------------------------------------------------------------------------------+" << endl;

    }

};

#endif
