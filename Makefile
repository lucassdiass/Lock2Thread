all:
	g++ -std=c++11 Chapter2Multiprocessor.cpp  Chapter2Multiprocessor.hpp -lpthread -o Lock2Thread
clean :
	rm Lock2tThread
