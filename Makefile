all:
	g++ main.cpp fsm.cpp xorg.cpp -o ant -fpermissive -g -lX11;./ant
	##g++ euler.cpp -o euler
	##gcc xwind.c -o helloxwind -lX11 
	##gcc simple-drawing.c -o drawing -lX11;./drawing
	##gcc x.c -o draw -lX11
