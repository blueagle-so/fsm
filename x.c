#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdio.h>
#include <stdlib.h>

Display *dis;
int screen;
Window win;
GC gc;
unsigned long white, black;





void cloze();
void init();
void draw();

int main(){
init();
XEvent event;
while(1){

	XNextEvent(dis, &event);
	if(event.type==Expose && event.xexpose.count==0){draw();}



}
return 0;
}
void init(){
dis=XOpenDisplay(NULL);
screen=DefaultScreen(dis);
black=BlackPixel(dis,screen);
white=WhitePixel(dis,screen);
win=XCreateSimpleWindow(dis, DefaultRootWindow(dis),0,0,300,300,5,white,black);
XSetStandardProperties(dis, win, "Hi", "hi", None, NULL, 0, NULL);
XSelectInput(dis, win, ExposureMask | ButtonPressMask | KeyPressMask);
gc=XCreateGC(dis, win, 0, 0);
XSetBackground(dis, gc, white);
XSetForeground(dis, gc, black);
XClearWindow(dis, win);
XMapRaised(dis, win);


}
void draw(){
XClearWindow(dis, win);
}

void cloze(){






}
