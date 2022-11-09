all:
	g++ main.cpp fsm.cpp -o ant -fpermissive
	g++ euler.cpp -o euler
	gcc xwind.c -o helloxwind -lX11 
