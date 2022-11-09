//https://www.google.ru/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwicqs_h0Iz7AhVIVfEDHRI_Ba8QFnoECBAQAQ&url=https%3A%2F%2Ftproger.ru%2Ftranslations%2Ffinite-state-machines-theory-and-implementation%2F&usg=AOvVaw0okPZou9d6Zo0w93UIxYMI
#include "fsm.h"
//Home on (0,0)
//Leaf on (rand, rand)

int main(){
Ant ant=Ant(0,0);
std::cout<<"Ant x = "<<ant.position.x<<std::endl;
std::cout<<"Ant y = "<<ant.position.y<<std::endl;
std::cout<<"leaf x = "<<ant.leaf.x<<std::endl;
std::cout<<"leaf y = "<<ant.leaf.y<<std::endl;
ant.update();
ant.update();
ant.update();
	//ant.position+=ant.leaf/10;
        //ant->position->x+=ant->leaf->x;
	//std::cout<<"ant x= "<<ant->position->x<<" ant y= "<<ant->position->y<<std::endl;

std::cout<<ant.position.distance(ant.leaf)<<std::endl;
for(int i=10;i>0;i--){
ant.position+=ant.leaf/i;
if((ant.position.distance(ant.leaf)-1)<1) break;
std::cout<<ant.position.distance(ant.leaf)<<std::endl;
}
/*
vector3d a=vector3d(2,5);
    vector3d b=vector3d(3,7);
    vector3d c=a+b;
    c.disp();
   f ff=c.distance(a);
    cout<<ff<<endl;
    //provide any operation.

*/

return 0;
}
