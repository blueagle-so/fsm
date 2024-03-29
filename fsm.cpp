#include "fsm.h"
#include <iostream>
using namespace std;
void goHome(Ant& obj);

point::point(float posX, float posY){
x=posX;
y=posY;
}
point::point(const point &p){
x=p.x;
y=p.y;
}
point &point::operator=(const point &p){
x=p.x;
y=p.y;
return *this;
}
point point::operator-(const point &p){
return point(x-p.x, y-p.y);
}
point point::operator+(const point &p){
return point(x+p.x, y+p.y);
}

point &point::operator+=(const point &p){
x+=p.x;
y+=p.y;
return *this;
}

point &point::operator-=(const point &p){
x-=p.x;
y-=p.y;
return *this;
}



f point::distance(const point &p){
	point dist=*this-p;
	return dist.magnitude();
}
f point::square(){

return x*x+y*y;

}

f point::magnitude(){

return sqrt(square());
}

void point::disp(){
cout<<x<<" "<<y<<endl;
}

point point::operator/(f value){

return point(x/value, y/value);

}

point &point::operator/=(f value){
x/=value;
y/=value;
return *this;
}
point point::normalization(){
*this/=magnitude();
return *this;
}


void findLeaf(Ant& obj){
//cout<<"findLeaf"<<endl;
///obj._position.disp();

//velocity = normalize(target - position) * max_velocity
//obj._position=point(1,1);
obj._position+=(obj._leaf-obj._position).normalization();

for(int k = 0;k<50000;k++)for(int j = 0;j<5000;j++);;

std::cout<<obj._position.distance(obj._leaf)<<std::endl;
if((obj._position.distance(obj._leaf))<1){obj._position=point(1,0);cout<<"goHome"<<endl;obj.brain->setState(goHome);}

    //if (distance(Game.mouse, this) <= MOUSE_THREAT_RADIUS) brain.setState(runAway);

//cout<<"findLeaf"<<endl;


}


void goHome(Ant& obj) {
    //velocity = new Vector3D(Game.instance.home.x - position.x, Game.instance.home.y - position.y);
 	//std::srand(std::time(0));
        //ant.leaf=vector3d((std::rand() % 10 +1), (std::rand() % 10 +1));
        //obj._leaf=point((std::rand() % 10 +1), (std::rand() % 10 +1));
        //ant.brain->setState(findLeaf);
	//obj._position=point(1,0);
	
	std::cout<<obj._leaf.distance(obj._position)<<std::endl;
	obj._position-=(obj._position-obj._leaf).normalization();
	if((obj._leaf.distance(obj._position))<1){std::srand(std::time(0));obj._leaf=point((std::rand() % 10 +1), (std::rand() % 10 +1));
cout<<"findLeaf"<<endl; obj.brain->setState(findLeaf);};


    //if (distance(Game.instance.home, this) <= 10) 
//obj.brain->setState(findLeaf);
//cout<<"goHome"<<endl;
for(int i = 0;i<50000;i++)for(int j = 0;j<5000;j++);;
}


void runAway(){
   // velocity = new Vector3D(position.x - Game.mouse.x, position.y - Game.mouse.y);

   // if (distance(Game.mouse, this) > MOUSE_THREAT_RADIUS) brain.setState(findLeaf);
}

Ant::Ant(point& vec)
        {
        _position=vec;
        _velocity=point(-1,-1);
	//std::srand(std::time(0));
        //leaf=vector3d((std::rand() % 10 +1), (std::rand() % 10 +1));
        brain = new FSM();
        brain->setState(findLeaf);
        }



//static void _Ant::findLeaf(){
	
        // Перемещает муравья к листу.
        //velocity = new Vector3D(Game.instance.leaf.x - position.x, Game.instance.leaf.y - position.y);

        /*if (distance(Game.instance.leaf, this) <= 10) {
             brain.popState(); // removes "findLeaf" from the stack.
            brain.pushState(goHome); // push "goHome" state, making it the active state.
        }
 
         if (distance(Game.mouse, this) <= MOUSE_THREAT_RADIUS) brain.pushState(runAway;
         */
//    }
 
//static    void _Ant::goHome(){
        // Перемещает муравья к дому
         //velocity = new Vector3D(Game.instance.home.x - position.x, Game.instance.home.y - position.y);

         /*if (distance(Game.instance.home, this) <= 10) {
             // Муравей уже дома. Пора искать новый лист.
             brain.popState(); // removes "goHome" from the stack.
             brain.pushState(findLeaf); // push "findLeaf" state, making it the active state
         }
 
         if (distance(Game.mouse, this) <= MOUSE_THREAT_RADIUS) {
             // Курсор мыши рядом. Надо бежать!
             // Состояние "runAway" добавляется перед "goHome", что означает,
             // что состояние "goHome" вновь будет активным при завершении состояния "runAway".
             brain.pushState(runAway);
         }*/
  //   }
 
 
//static     void _Ant::runAway(){
         // Перемещает муравья подальше от курсора
         //velocity = new Vector3D(position.x - Game.mouse.x, position.y - Game.mouse.y);
 
         // Курсор все еще рядом?
         /*if (distance(Game.mouse, this) > MOUSE_THREAT_RADIUS) {
             // Нет, уже далеко. Пора возвращаться к поискам листочков.
             brain.popState();
         }*/
    // }



vector3d::vector3d(const vector3d &vec)
{
    x=vec.x;
    y=vec.y;
    z=vec.z;
}

//addition

vector3d vector3d ::operator+(const vector3d &vec)
{
    return vector3d(x+vec.x,y+vec.y,z+vec.z);
}

vector3d &vector3d ::operator+=(const vector3d &vec)
{
    x+=vec.x;
    y+=vec.y;
    z+=vec.z;
    return *this;
}
//substraction//
vector3d vector3d ::operator-(const vector3d &vec)
{
    return vector3d(x-vec.x,y-vec.y,z-vec.z);
}

vector3d &vector3d::operator-=(const vector3d &vec)
{
    x-=vec.x;
    y-=vec.y;
    z-=vec.z;
    return *this;
}

//scalar multiplication

vector3d vector3d ::operator*(f value)
{
    return vector3d(x*value,y*value,z*value);
}



vector3d &vector3d::operator*=(f value)
{
    x*=value;
    y*=value;
    z*=value;
    return *this;
}

//scalar division
vector3d vector3d ::operator/(f value)
{
    assert(value!=0);
    return vector3d(x/value,y/value,z/value);
}

vector3d &vector3d ::operator/=(f value)
{
    assert(value!=0);
    x/=value;
    y/=value;
    z/=value;
    return *this;
}


vector3d &vector3d::operator=(const vector3d &vec)
{
    x=vec.x;
    y=vec.y;
    z=vec.z;
    return *this;
}

//Dot product
f vector3d::dot_product(const vector3d &vec)
{
    return x*vec.x+vec.y*y+vec.z*z;
}

//cross product
vector3d vector3d ::cross_product(const vector3d &vec)
{
    f ni=y*vec.z-z*vec.y;
    f nj=z*vec.x-x*vec.z;
    f nk=x*vec.y-y*vec.x;
    return vector3d(ni,nj,nk);
}

f vector3d::magnitude()
{
    return sqrt(square());
}

f vector3d::square()
{
    return x*x+y*y+z*z;
}

vector3d vector3d:: normalization()
{
    assert(magnitude()!=0);
    *this/=magnitude();
    return *this;
}

f vector3d::distance(const vector3d &vec)
{
    vector3d dist=*this-vec;
    return dist.magnitude();
}

f vector3d::show_X()
{
    return x;
}

f vector3d::show_Y()
{
    return y;
}

f vector3d::show_Z()
{
    return z;
}

void vector3d::disp()
{
    cout<<x<<" "<<y<<" "<<z<<endl;
}




