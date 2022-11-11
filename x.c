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
Drawable d;




void cloze();
void init();
void draw();

int main(){
init();
XEvent event;
KeySym key;
char *text[255];
while(1){

	XNextEvent(dis, &event);
	if(event.type==Expose && event.xexpose.count==0)draw();
	if(event.type==KeyPress && XLookupString(&event.xkey, text, 255, &key, 0)==1){
		if(text[0]=='q')close(0);
		printf("You presed %c key\n", text[0]);}
	if(event.type==ButtonPress){
		XSetForeground(dis, gc, white);
		XDrawPoint(dis, win ,gc, event.xbutton.x, event.xbutton.y);
		
	}

	

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
XFreeGC(dis, gc);
XDestroyWindow(dis, win);
XCloseDisplay(dis);
exit(0);
}
