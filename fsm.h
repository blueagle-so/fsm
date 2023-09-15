#include <cstddef>
#include <stack>
#include <map>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include<math.h>
#include<assert.h>
using namespace std;
typedef float f;
class Ant;
class vector3d
{
public:
    f x,y,z;
    vector3d()  //constructor
    {
        x=0;
        y=0;
        z=0;
    }

    vector3d(f x1,f y1,f z1=0)     //initializing object with values.
    {
        x=x1;
        y=y1;
        z=z1;
    }
    vector3d(const vector3d &vec);    //copy constructor
    vector3d operator+(const vector3d &vec);    //addition
    vector3d &operator+=(const vector3d &vec);  ////assigning new result to the vector
    vector3d operator-(const vector3d &vec);    //substraction
    vector3d &operator-=(const vector3d &vec);  //assigning new result to the vector
    vector3d operator*(f value);    //multiplication
    vector3d &operator*=(f value);  //assigning new result to the vector.
    vector3d operator/(f value);    //division
    vector3d &operator/=(f value);  //assigning new result to the vector
    vector3d &operator=(const vector3d &vec);
    f dot_product(const vector3d &vec); //scalar dot_product
    vector3d cross_product(const vector3d &vec);    //cross_product
    f magnitude();  //magnitude of the vector
    vector3d normalization();   //nor,malized vector
    f square(); //gives square of the vector

    f distance(const vector3d &vec);    //gives distance between two vectors
    f show_X(); //return x
    f show_Y(); //return y
    f show_Z(); //return z
    void disp();    //display value of vectors
};
using AbstractState = void(*)(Ant& obj);
using namespace std;
class FSM{
	private:
	AbstractState activeState;
	public:
	FSM(){}
	void setState(AbstractState state){
	activeState=state;
	}
	void update(Ant& obj){
	if(activeState!=NULL)
	activeState(obj);
	}
};
class point{
	public:
	float x;
	float y;
	public:
	point(){};
	point(float, float);
	point(const point &p);
	point &operator=(const point &p);
	point operator-(const point &p); 
	point &operator+=(const point &p);
	point operator/(f value);
        point &operator/=(f value);
	point normalization();
	point &operator-=(const point &p);
	point operator+(const point &p);
	f distance(const point &p);
	f square();
	f magnitude();
	void disp();
	
};
class Ant{
	public:
	point _position, _leaf, _velocity;
	vector3d position;
	vector3d velocity;
	vector3d leaf;
	//FSM* brain;
	Ant(point&);
	Ant()=default;
	friend void findLeaf(Ant& obj);
	friend void goHome(Ant& obj);
	friend void runAway(Ant& obj);
	void update(Ant& obj){
	brain->update(obj);
        //moveBasedOnVelocity();
	}
	private:
        FSM* brain;


};
/*
class StackFSM {
    stack<Func> _stack;
    Func currentStateFunction;
    public:
    StackFSM() {
        //this.stack = new stack();
    }

    void update(){
        //currentStateFunction = getCurrentState();

        if (currentStateFunction != NULL) 
            currentStateFunction();
    }

    Func popState(){
	Func t = _stack.top();
	_stack.pop();
        return t;
    }

    void pushState(Func state){
        if(getCurrentState() != state) {
            _stack.push(state);
        }
    }

    Func getCurrentState(){
        return _stack.top();
    }

};




class _Ant {
    StackFSM *brain;
     public:
    _Ant(int posX, int posY) {
        brain = new StackFSM();
        brain->pushState(findLeaf);
    }

   static void findLeaf();

   static void goHome();
     
   static void runAway();
};

*/
