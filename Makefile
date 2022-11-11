all:
	g++ main.cpp fsm.cpp -o ant -fpermissive
	g++ euler.cpp -o euler
	gcc xwind.c -o helloxwind -lX11 
	gcc simple-drawing.c -o drawing -lX11
	gcc x.c -o draw -lX11
