/*
 * Chapter2Multiprocessor.hpp
 *
 *  Created on: 4 de abr de 2020
 *      Author: lucas
 */

#ifndef CHAPTER2MULTIPROCESSOR_HPP_
#define CHAPTER2MULTIPROCESSOR_HPP_
#include <bits/stdc++.h>
#include <thread>


namespace TwoThreads
{
class LockOne
{
public :
	LockOne(int Id, std::array<bool,2> & flags) : Id(Id), flags(flags)
{

}
	void Lock()
	{
		int j = 1 - Id;
		flags[Id]=true;
		while(flags[j]){}
		std::cout << "Thread: "<<Id<< " Lock" << std::endl;
	}
	void Unlock()
	{
		std::cout << "Thread: "<<Id<< " Unlock" << std::endl;

		flags[Id]=false;
	}
	~LockOne()=default;
private :
	std::array<int,2> threads={0,1};
	std::array<bool,2> & flags;//={false,false};
	int Id;
};

class LockTwo
{
public :
	LockTwo(int Id, int& victim) : Id(Id), victim(victim)
{

}
	void Lock()
	{
		int j = 1 - Id;
		victim=j;
		while(victim==j){}
		std::cout << "Thread: "<<Id<< " Lock" << std::endl;
	}
	void Unlock()
	{
		std::cout << "Thread: "<<Id<< " Unlock" << std::endl;
	}

	~LockTwo()=default;

private :
	int Id;
	int &victim;
};

class PetersonLock
{
public :
	PetersonLock(int Id, int& victim, std::array<bool,2> & flags) : Id(Id), victim(victim), flags(flags)
{

}
	void Lock()
	{
		int j = 1 - Id;
		flags[Id]=true;
		victim=j;
		while(flags[j]==true && victim==j){}
		std::cout << "Thread: "<<Id<< " Lock" << std::endl;
	}
	void Unlock()
	{
		std::cout << "Thread: "<<Id<< " Unlock" << std::endl;
		flags[Id]=false;

	}

	~PetersonLock()=default;
private :
	int Id;
	int &victim;
	std::array<int,2> threads={0,1};
	std::array<bool,2> & flags;
};
}



#endif /* CHAPTER2MULTIPROCESSOR_HPP_ */
