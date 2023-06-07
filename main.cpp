//https://www.google.ru/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwicqs_h0Iz7AhVIVfEDHRI_Ba8QFnoECBAQAQ&url=https%3A%2F%2Ftproger.ru%2Ftranslations%2Ffinite-state-machines-theory-and-implementation%2F&usg=AOvVaw0okPZou9d6Zo0w93UIxYMI
#include "fsm.h"
//Home on (0,0)
//Leaf on (rand, rand)
int main(){
point _home(0, 0);
vector3d home(0,0,0);
Ant ant = Ant(_home);
for(;;){
	ant.update(ant);
	//ant.position=home;//fsm.cpp:186
	ant._position=_home;
	cout<<"at home ";
	//ant.position.disp();//fsm.cpp:247
	ant._position.disp();
	cout<<endl;
	std::srand(std::time(0));
	//ant.leaf=vector3d((std::rand() % 10 +1), (std::rand() % 10 +1));
        ant._leaf=point((std::rand() % 10 +1), (std::rand() % 10 +1));
	cout<<"leaf coord ";
	//ant.leaf.disp();
	ant._leaf.disp();
	cout<<endl;
	findLeaf(ant);
	//for(int i = 0;i<50000;i++)for(int j = 0;j<50000;j++);;
}
return 0;
}
