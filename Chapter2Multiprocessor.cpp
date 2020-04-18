/*
 * Chapter2Multiprocessor.cpp
 *
 *  Created on: 4 de abr de 2020
 *      Author: lucas
 */
#include "Chapter2Multiprocessor.hpp"
int main()
{
	int A=0, B=1, victim;
	std::array<bool,2> pointer=std::array<bool,2>{false,false};
	TwoThreads::PetersonLock ThreadA{A,victim,pointer},ThreadB{B,victim,pointer};

	std::thread t0([&ThreadA]()
			{
		for(int x = 0; x<10;x++)
		{
			ThreadA.Lock();
			ThreadA.Unlock();
			//std::this_thread::sleep_for(std::chrono::nanoseconds(1));
		}
			});
	std::thread t1([&ThreadB]()
			{
		for(int x = 0; x<10;x++)
		{
			ThreadB.Lock();
			ThreadB.Unlock();
			//std::this_thread::sleep_for(std::chrono::nanoseconds(1));
		}
			});

	t0.join();
	t1.join();
	std::thread t2([&ThreadA]()
			{
		for(int x = 0; x<10;x++)
		{
			std::this_thread::sleep_for(std::chrono::nanoseconds(1));
			ThreadA.Lock();
			ThreadA.Unlock();
		}
			});
	std::thread t3([&ThreadB]()
			{
		for(int x = 0; x<10;x++)
		{
			std::this_thread::sleep_for(std::chrono::nanoseconds(5));

			ThreadB.Lock();
			ThreadB.Unlock();
		}
			});
	t2.join();
	t3.join();

}


