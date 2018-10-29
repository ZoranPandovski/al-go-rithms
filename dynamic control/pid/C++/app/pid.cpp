/**
 *  Copyright 2018 Siddhesh Rane
 *  @file    pid.cpp
 *  @author  Siddhesh Rane (srane96)
 *  @date    9/22/2018
 *
 *  @brief PID controller class implementation
 *
 *  @section DESCRIPTION
 *
 *  This source file implements a PID controller class.
 *  The class contains methods to compute target velocity
 *  given setpoint, current velocity and gain parameters.
 *
 */
#include "pid.h"
/**
 * Initialize all values to 0.0
 * if default constructor is called.
 */
PID::PID() {
	this->kp = 0;  				///< proportional gain
	this->ki = 0;  				///< integral gain
	this->kd = 0;  				///< differential gain
	this->prevError = 0;  		///< error at previous time step
	this->integralError = 0;  	///< Accumulation of error over time
	this->ctrlOp = 0;			///< Control Output from the PID controller
}
/**
 * Initialize controller gains
 */
PID::PID(const double &kp, const double& ki, const double& kd) {
	this->kp = kp;  			///< proportional gain
	this->ki = ki;  			///< integral gain
	this->kd = kd;  			///< differential gain
	this->prevError = 0;  		///< error at previous time step
	this->integralError = 0;  	///< Accumulation of error over time
	this->ctrlOp = 0;			///< Control Output from the PID controller

}
/// Default destructor
PID::~PID() {
}
/**
 * Calculate target velocity using Kp, Ki
 * and Kd member variables
 */
double PID::compute(const double& setPoint, const double& currentVel) {
	double error = setPoint - currentVel;
	this->integralError += error;
	this->ctrlOp = kp * error + ki * integralError + (kd/dt) * (error - prevError);
	this->prevError = error;
	return ctrlOp;
}
/**
 * Set new values to member variables of the class
 */
void PID::setParameters(const double &kp, const double& ki, const double& kd) {
	this->kp = kp;
	this->ki = ki;
	this->kd = kd;
}

/**
 * Set the kp variable to new value
 */
void PID::setKp(const double &kp) {
	this->kp = kp;
}

/**
 * Set the kd variable to new value
 */
void PID::setKd(const double &kd) {
	this->kd = kd;
}

/**
 * Set the kd variable to new value
 */
void PID::setKi(const double &ki) {
	this->ki = ki;
}

/**
 * Set the dt variable to new value
 */
void PID::setDt(const double &dt) {
	this->dt = dt;
}

/// Return value of Ki member variable
double PID::getKi() {
  return this->ki;
}
/// Return value of Kp member variable
double PID::getKp() {
  return this->kp;
}
/// Return value of Kd member variable
double PID::getKd() {
  return this->kd;
}
/// Return the current control output of the PID controller
double PID::getCtrlOp(){
	return this->ctrlOp;
}
///	Return the value of dt member variable
double PID::getDt() {
	return this->dt;
}
