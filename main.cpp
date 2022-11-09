//https://www.google.ru/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwicqs_h0Iz7AhVIVfEDHRI_Ba8QFnoECBAQAQ&url=https%3A%2F%2Ftproger.ru%2Ftranslations%2Ffinite-state-machines-theory-and-implementation%2F&usg=AOvVaw0okPZou9d6Zo0w93UIxYMI
#include "fsm.h"
//Home on (0,0)
//Leaf on (rand, rand)

double func(double x, double y)
{
        return y-x; }

int main(){
Ant* ant=new Ant(1,1);
std::cout<<"Ant x = "<<ant->position->x<<std::endl;
std::cout<<"Ant y = "<<ant->position->y<<std::endl;
std::cout<<"leaf x = "<<ant->leaf->x<<std::endl;
std::cout<<"leaf y = "<<ant->leaf->y<<std::endl;
ant->update();
ant->update();
ant->update();
float h = (ant->leaf->y)/(ant->leaf->x);
printf("%f\n",h);
for (int i=1;i<ant->leaf->x;i++){
	ant->position->y+=h*func(i,ant->leaf->y);
        ant->position->x+=h;
	std::cout<<"ant x= "<<ant->position->x<<" ant y= "<<ant->position->y<<std::endl;
	//ant->position->y+=h*func(i,ant->leaf->y);
	//ant->position->x+=i;
}

return 0;
}
