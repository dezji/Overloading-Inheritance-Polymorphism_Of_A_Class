//Created By: Deziallia Morris
//Program Purpose: To demonstrate operator overloading, inheritance, and polymorphism by utilizing a class hierarchy of shapes

#include <iostream>
using namespace std;


/******************Rectangle Class****************************/
//class declaration section
class Rectangle {
protected:
    //data members
    int sideA;
    int sideB;
public:
    Rectangle(int, int);
    void setSideA(int);
    void setSideB(int);
    int getSideA();
    int getSideB();
    int computePerimeter();
    int computeArea();
    void operator++(); //overloaded increment operator
    void operator--(); //overloaded decrement operator
    bool operator==(Rectangle &); //overloaded is equal to operator
};

// sets sides
Rectangle::Rectangle(int sideA, int sideB) {
    setSideA(sideA);
    setSideB(sideB);
}

// validate the side input, default to 1 if less than 0
void Rectangle::setSideA(int a) {
    if (a <= 0) {
        a = 1;
    }
    sideA = a;
}

void Rectangle::setSideB(int b) {
    if (b <= 0) {
        b = 1;
    }
    sideB = b;
}

// get statements
int Rectangle::getSideA() {return sideA;}
int Rectangle::getSideB() {return sideB;}

// compute statements
int Rectangle::computePerimeter() {return (2 * (sideA + sideB));}
int Rectangle::computeArea() {return sideA * sideB;}

// overload the operator to increment
void Rectangle::operator++() {
    sideA++;
    sideB++;
}

// overload the operator to decrement
void Rectangle::operator--() {
    sideA--;
    sideB--;
}

// validates if two shapes are equal to each other
bool Rectangle:: operator==(Rectangle &shape) {
    if (sideA == shape.getSideA() && sideB == shape.getSideB() ){
        return true;
    }
    else
        return false;

}

/******************Square Class****************************/
//class declaration section
// add relationship to rectangle base class
class Square : public Rectangle
{
public:
    Square(int); //constructor
    void setSideA(int);
    void setSideB(int);
};

// set sides
Square::Square(int side) : Rectangle(side, side){
    setSideA(side);
    setSideB(side);
}

// validate sides
void Square::setSideA(int a) {
    if (a <= 0)
        a = 1;
}

void Square::setSideB(int b) {
    if (b <= 0)
        b = 1;
}

void displayData(Rectangle); // function prototype

int main()
{

    // variables for the shape constructors
    int squareSide;
    int rectangleSideA, rectangleSideB;

    cout << "Please enter a side length for Square: ";
    cin >> squareSide;

    Square square(squareSide);
    displayData(square);
    ++square;

    cout << "After incrementing by 1:";
    displayData(square);

    cout << "Please enter the first side length for Rectangle: ";
    cin >> rectangleSideA;

    cout << "Please enter the second side length for Rectangle: ";
    cin >> rectangleSideB;

    Rectangle rectangle(rectangleSideA, rectangleSideB);
    displayData(rectangle);
    --rectangle;

    cout << "After decrementing by 1:";
    displayData(rectangle);

    if (square == rectangle)
        cout << "The two objects have equal sides";
    else
        cout << "The two objects do not have equal sides";
}

/****************************************************************************/
/* Because of inheritance and polymorphism the displayData function can be
   passed either a Rectangle object or a Square object to display each
   object's data.                                                           */
void displayData(Rectangle shape)
{
    cout << "\nThe length of side A is " << shape.getSideA() << endl;
    cout << "The length of side B is " << shape.getSideB() << endl;
    cout << "The perimeter is " << shape.computePerimeter() << endl;
    cout << "The area is " << shape.computeArea() << endl << endl;
}