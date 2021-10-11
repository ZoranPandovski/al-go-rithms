/**
 *  Copyright 2018 Siddhesh Rane
 *  @file    main.cpp
 *  @author  Siddhesh Rane (srane96)
 *  @date    9/22/2018
 *
 *  @brief C++ program to implement PID controller
 *  for mobile robot
 *
 */
#include <iostream>
#include "pid.h"

using std::cout;	using std::cin;

int main() {
	double currVel, desVel;
	PID dummyPID(0.1, 0.5, 0.01);
	cout << "Enter Current and desired velocity: ";
	cin >> currVel >> desVel;
	cout << "The necessary control input: "<< dummyPID.compute(desVel, currVel) << std::endl;
	return 0;
}
