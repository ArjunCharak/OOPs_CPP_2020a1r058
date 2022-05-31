//c++ program to add two classes data using friend function.
#include <iostream>
using namespace std;

// forward declaration
class Classy;

class Classx {

    public:
        // constructor to initialize numA to 12
        Classx() : numx(20) {}

    private:
        int numx;

         // friend function declaration
         friend int add(Classx, Classy);
};

class Classy {

    public:
        // constructor to initialize numB to 1
        Classy() : numy(10) {}

    private:
        int numy;

        // friend function declaration
        friend int add(Classx, Classy);
};

// access members of both classes
int add(Classx objectx, Classy objecty) {
    return (objectx.numx + objecty.numy);
}

int main() {
    Classx objectx;
    Classy objecty;
    cout << "Sum: " << add(objectx, objecty);
    return 0;
}