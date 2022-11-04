#include <cstddef>
#include <stack>
#include <map>
#include <cstdlib>
#include <iostream>
#include <ctime>
using Func = void (*)();
using namespace std;
class FSM{
	private:
	Func activeState;
	public:
	FSM(){}
	void setState(Func state){
	activeState=state;
	}
	void update(){
	if(activeState!=NULL)
	activeState();
	}
};
class Point{
	public:
	int x;
	int y;
	Point(){};
	Point(int,int);
	//Point(int posX, int posY){
	//x=posX;
	//y=posY;
	//}
};
class Ant{
	public:
	Point *position;
	Point *velocity;
	Point *leaf;
	static FSM* brain;
	Ant(int posX, int posY)
	{
	position=new Point(posX, posY);
	velocity=new Point(-1,-1);
	std::srand(std::time(0));
	leaf=new Point((std::rand() % 10 +1), (std::rand() % 10 +1));
	brain = new FSM();
	brain->setState(findLeaf);
	}
	static void findLeaf();
	static void goHome();
	static void runAway();
	void update(){
        brain->update();
        //moveBasedOnVelocity();
	}

};

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
