#include <iostream>
#include <Customer.h>
#include <Teller.h>
#include <BQMS.h>
using namespace std;

int main()
{
    BQMS b;
    b.addCustomer();
    b.Simulate();
    return 0;
}
