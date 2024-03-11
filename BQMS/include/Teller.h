#ifndef TELLER_H
#define TELLER_H
#include <string>
#include <iostream>
using namespace std;

class Teller
{
private:
    string tellerName;
    bool busy;
    int workingTime;

public:
    double numService;
    Teller() {numService=0;}
    Teller(string name)
    {
      numService=0;
      setBusy(false);
      setTellerName(name);
      setWorking(0);
    }

    string getTellerName()
    {
        return tellerName;
    }
    int getWorkingTime()
    {
        return workingTime;
    }


    bool isBusy()
    {
        return busy;
    }
    void setWorking(int working)
    {
        workingTime = working;
    }

    void setTellerName(string newName)
    {
        tellerName = newName;
    }

    void setBusy(bool newbusy)
    {
        busy = newbusy;
    }

};

#endif // TELLER_H
