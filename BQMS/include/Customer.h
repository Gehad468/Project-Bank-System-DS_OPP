#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;
class Customer
{
private:
    string nameCust;
    int arrivalTime;
    int serviceTime;
    int waitingTime;
    int exitTime;
    bool VIP;
public:
    Customer() {}
    Customer(string nameCust, int arrivalTime, int serviceTime, bool VIP)
    {
        this->nameCust = nameCust;
        this->arrivalTime = arrivalTime;
        this->serviceTime = serviceTime;
        this->VIP = VIP;
        this->waitingTime=0;
    }

    void setName(string name)
    {
        nameCust=name;
    }
    void setArrival(int arrival)
    {
        arrivalTime=arrival;
    }
    void setService(int service)
    {
        serviceTime=service;
    }
     void setExit(int exit)
    {
        exitTime=exit;
    }
    int getExit()
    {
        return exitTime;
    }
    void setVip(bool vip)
    {
        VIP=vip;
    }
    void setwaitingTime(int wait)
    {
        waitingTime=wait;
    }
    string getName()
    {
        return nameCust;
    }
    int getArrival()
    {
        return arrivalTime;
    }
    int getService()
    {
        return serviceTime;
    }
    bool getVip()
    {
        return VIP;
    }
    int getWaitingTime()
    {
        return waitingTime;
    }

};

#endif // CUSTOMER_H
