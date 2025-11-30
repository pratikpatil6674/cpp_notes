#include "car.h"
/*
Constructor delegation
Copy/move constructor/assignment_operator
Overload =, ++, 

*/

int car::total_count = 0;
// usage of delegating constructors
car::car():car(0){
    /*below things are achieved by the delegated constructor*/

    // car_type = new int(0);
    // fuel=0;
    // speed=0;
    // passengers=0;
    // total_count++;
}

car::car(float fuel): car(fuel,0){
    /*below things are achieved by the delegated constructor*/

    // car_type = new int(0);
    // this->fuel=fuel;
    // speed=0;
    // passengers=0;
    // total_count++;
}

car::car(float fuel, int passengers){
    car_type = new int(0);
    this->fuel=fuel;
    speed=0;
    this->passengers=passengers;
    total_count++;
}

//copy constructor, create deep copy in this case
car::car(const car &obj){
    std::cout<<"car::car(const car &obj)"<<std::endl;
    car_type = new int(*obj.car_type);
    fuel = obj.fuel;
    speed = obj.speed;
    passengers = obj.passengers;
    total_count++;
}

// move constructor
car::car(car &&obj){
    // move the resources of obj to other,
    // note that obj is not being destroyed immediately, we can always reinitialize it
    // move assignment operator is also required
    std::cout<<"car::car(car &&obj)"<<std::endl;

    car_type = obj.car_type;
    fuel = obj.fuel;
    speed = obj.speed;
    passengers = obj.passengers; 
    obj.car_type = nullptr; 
}

car::~car(){
    std::cout<<"car::~car()"<<std::endl;
    total_count--;
    delete car_type;
}

void car::accelerate(){
    speed++;
    fuel-=0.5f;
}

void car::brake(){
    speed=0;
}

void car::add_passengers(int count){
    passengers=count;
}

void car::dashboard()const {
    std::cout<<"fuel = "<<fuel<<std::endl;
    std::cout<<"speed = "<<speed<<std::endl;
    std::cout<<"passengers = "<<passengers<<std::endl;

}

void car::show_count(){
    std::cout<<"Total cars = "<<total_count<<std::endl;

}

car car::operator+(const car &a)const{
    //add two cars, overload + operator
    car temp;
    *(temp.car_type) = *(this->car_type) + *(a.car_type);
    temp.fuel = this->fuel + a.fuel;
    temp.speed = this->speed + a.speed;
    temp.passengers = this->passengers + a.passengers;
    return temp;

}

//pre-increment operator
// this is more efficient than overloading post increment operator because temporary object is created in the latter.
car& car::operator++(){
    ++(*this->car_type);
    ++fuel;
    ++speed;
    ++passengers;
    return *this; //return the reference to current object
}


//post increment operator
car car::operator ++(int){
    car temp(*this); // copy this object, copy constructor
    std::cout<<"copied object\n";
    (*car_type)++;
    fuel++;
    speed++;
    passengers++;
    
    return temp;
}

//overload == operator
bool car::operator ==(const car &a)const {
     return *car_type==*(a.car_type) && fuel==a.fuel && speed==a.speed && passengers==a.passengers;
}  


// overload copy assignment operator
car& car::operator =(const car &a){
    if(this != &a){ // for cases like a=a
        std::cout<<"Copy Assignment operator"<<std::endl;
        *car_type = *(a.car_type);
        fuel = a.fuel;
        speed = a.speed;
        passengers = a.passengers;
}
    return *this;
}


// overload move assignment operator
car& car::operator =(car &&a){
    if(this != &a){ // for cases like a=a
        std::cout<<"Move Assignment operator\n";
        car_type = a.car_type; // move resources
        a.car_type = nullptr;

        fuel = a.fuel;
        speed = a.speed;
        passengers = a.passengers;
}
    return *this;
}

void car::operator()(){
    std::cout<<"function call overload"<<std::endl;
}

//friend function
std::ostream& operator<<(std::ostream& out, const car &c){ //c is const
    out<<c.fuel<<c.speed<<c.passengers;
    return out;
}
//friend function
std::istream& operator>>(std::istream& in, car &c){ //c is not const
    in>>c.fuel>>c.speed>>c.passengers;
    return in;
}