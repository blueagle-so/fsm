//https://www.google.ru/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwicqs_h0Iz7AhVIVfEDHRI_Ba8QFnoECBAQAQ&url=https%3A%2F%2Ftproger.ru%2Ftranslations%2Ffinite-state-machines-theory-and-implementation%2F&usg=AOvVaw0okPZou9d6Zo0w93UIxYMI
#include "fsm.h"
//Home on (0,0)
//Leaf on (rand, rand)


int main(){
Ant* ant=new Ant(0,0);
std::cout<<"Ant x = "<<ant->position->x<<std::endl;
std::cout<<"Ant y = "<<ant->position->y<<std::endl;
std::cout<<"leaf x = "<<ant->leaf->x<<std::endl;
std::cout<<"leaf y = "<<ant->leaf->y<<std::endl;
ant->update();
ant->update();
ant->update();
return 0;
}
