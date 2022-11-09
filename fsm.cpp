#include "fsm.h"
#include <iostream>
using namespace std;
FSM * Ant::brain;

//Ant::Ant(int posX, int posY){
	//position=position(posX, posY);
        //velocity=velocity(-1,-1);
  //      brain = new FSM();
    //    brain->setState(findLeaf);
//}

Point::Point(float posX, float posY){
x=posX;
y=posY;
}


static void Ant::findLeaf(){
    //velocity = new Vector3D(Game.instance.leaf.x - position.x, Game.instance.leaf.y - position.y);

    //if (distance(Game.instance.leaf, this) <= 10)  
brain->setState(goHome);

    //if (distance(Game.mouse, this) <= MOUSE_THREAT_RADIUS) brain.setState(runAway);

cout<<"findLeaf"<<endl;


}


static void Ant::goHome() {
    //velocity = new Vector3D(Game.instance.home.x - position.x, Game.instance.home.y - position.y);

    //if (distance(Game.instance.home, this) <= 10) 
brain->setState(findLeaf);
cout<<"goHome"<<endl;
}


static void Ant::runAway(){
   // velocity = new Vector3D(position.x - Game.mouse.x, position.y - Game.mouse.y);

   // if (distance(Game.mouse, this) > MOUSE_THREAT_RADIUS) brain.setState(findLeaf);
}
static void _Ant::findLeaf(){
        // Перемещает муравья к листу.
        //velocity = new Vector3D(Game.instance.leaf.x - position.x, Game.instance.leaf.y - position.y);

        /*if (distance(Game.instance.leaf, this) <= 10) {
             brain.popState(); // removes "findLeaf" from the stack.
            brain.pushState(goHome); // push "goHome" state, making it the active state.
        }
 
         if (distance(Game.mouse, this) <= MOUSE_THREAT_RADIUS) brain.pushState(runAway;
         */
    }
 
static    void _Ant::goHome(){
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
     }
 
 
static     void _Ant::runAway(){
         // Перемещает муравья подальше от курсора
         //velocity = new Vector3D(position.x - Game.mouse.x, position.y - Game.mouse.y);
 
         // Курсор все еще рядом?
         /*if (distance(Game.mouse, this) > MOUSE_THREAT_RADIUS) {
             // Нет, уже далеко. Пора возвращаться к поискам листочков.
             brain.popState();
         }*/
     }

