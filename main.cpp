//https://www.google.ru/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwicqs_h0Iz7AhVIVfEDHRI_Ba8QFnoECBAQAQ&url=https%3A%2F%2Ftproger.ru%2Ftranslations%2Ffinite-state-machines-theory-and-implementation%2F&usg=AOvVaw0okPZou9d6Zo0w93UIxYMI
#include "fsm.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>             /* getenv(), etc. */
#include <unistd.h>             /* sleep(), etc.  */
Window
create_simple_window(Display* display, int width, int height, int x, int y);
GC
create_gc(Display* display, Window win, int reverse_video);

//Home on (0,0)
//Leaf on (rand, rand)
//void main_();
int main(){
  Display* display;             /* pointer to X Display structure.           */
  int screen_num;               /* number of screen to place the window on.  */
  Window win;                   /* pointer to the newly created window.      */
  unsigned int display_width,
               display_height;  /* height and width of the X display.        */
  unsigned int width, height;   /* height and width for the new window.      */
  char *display_name = getenv("DISPLAY");  /* address of the X display.      */
  GC gc;                        /* GC (graphics context) used for drawing    */
                                /*  in our window.                           */
  display = XOpenDisplay(display_name);

  /* get the geometry of the default screen for our display. */
  screen_num = DefaultScreen(display);
  display_width = DisplayWidth(display, screen_num);
  display_height = DisplayHeight(display, screen_num);

  /* make the new window occupy 1/9 of the screen's size. */
  width = (display_width / 3);
  height = (display_height / 3);
  printf("window width - '%d'; height - '%d'\n", width, height);

  win = create_simple_window(display, width, height, 100, 100);

  /* allocate a new GC (graphics context) for drawing in the window. */
  gc = create_gc(display, win, 0);
  XSync(display, False);





point _home(1, 0);
//vector3d home(0,0,0);
Ant ant = Ant(_home);

        std::srand(std::time(0));
        //ant.leaf=vector3d((std::rand() % 10 +1), (std::rand() % 10 +1));
        ant._leaf=point((std::rand() % 10 +1), (std::rand() % 10 +1));
        //ant.brain->setState(findLeaf);
        //ant.brain->setState(findLeaf);
        ant._position=point(1,0);


for(;;){
	ant.update(ant);
        //XDrawPoint(display, win, gc, x, y);
        point p = ant._position;
        XDrawPoint(display, win, gc, ant._position.x*50+1,ant._position.y*50+1);
        XDrawPoint(display, win, gc, ant._position.x*50-1,ant._position.y*50+1);
        XDrawPoint(display, win, gc, ant._position.x*50+1,ant._position.y*50-1);
        XDrawPoint(display, win, gc, ant._position.x*50-1,ant._position.y*50-1);
        XDrawPoint(display, win, gc, ant._position.x*50,ant._position.y*50);
        XFlush(display);
  XSync(display, False);


        for(int i = 0;i<50000;i++)for(int j=0;j<200;j++);;






	//ant.position=home;//fsm.cpp:186
	//ant._position=_home;
	//cout<<"at home ";
	//ant.position.disp();//fsm.cpp:247
	//ant._position.disp();
	//cout<<endl;
	//std::srand(std::time(0));
	//ant.leaf=vector3d((std::rand() % 10 +1), (std::rand() % 10 +1));
        //ant._leaf=point((std::rand() % 10 +1), (std::rand() % 10 +1));
	//cout<<"leaf coord ";
	//ant.leaf.disp();
	//ant._leaf.disp();
	//cout<<endl;
	//findLeaf(ant);
	//for(int i = 0;i<50000;i++)for(int j = 0;j<50000;j++);;
}
return 0;
}
