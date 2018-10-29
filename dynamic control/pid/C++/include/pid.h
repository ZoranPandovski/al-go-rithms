/**
 *  Copyright 2018 Siddhesh Rane
 *  @file    pid.hpp
 *  @author  Siddhesh Rane (srane96)
 *  @date    9/22/2018
 *
 *  @brief PID controller for mobile robot
 *
 *  @section DESCRIPTION
 *
 *  Source header file for PID controller class.
 *
 */
#ifndef WEEK4_TDD_4B_INCLUDE_CONTROLLER_H_
#define WEEK4_TDD_4B_INCLUDE_CONTROLLER_H_
#include <iostream>
class PID {
 private:
  double dt = 0.01;  		///< time step
  double kp;  				///< proportional gain
  double ki;  				///< integral gain
  double kd;  				///< differential gain
  double prevError;  		///< error at previous time step
  double integralError;  	///< Accumulation of error over time
  double ctrlOp;			///< Control Output from the PID controller
 public:
  /**
   * @brief Default PID Controller
   */
  PID();
  /**
   * @brief Constructor with initial values
   * @param kp - proportional gain
   * @param ki - integral gain
   * @param kd - differential gain
   */
  PID(const double &kp, const double& ki, const double& kd);
  /// PID destructor
  ~PID();
  /**
   * @brief calculate new velocity using setpoint
   *        and current velocity
   * @param setPoint - target velocity
   * @param currentVel - current velocity
   * @return new velocity
   */
  double compute(const double& setPoint, const double& currentVel);
  /**
   * @brief set gain values for PID class
   * @param kp - proportional gain
   * @param ki - integral gain
   * @param kd - differential gain
   */
  void setParameters(const double &kp, const double& ki, const double& kd);
  /**
   * @brief set value of kp
   * @param Kp - proportional gain
   */
  void setKp(const double &kp);
  /**
   * @brief set value of kd
   * @param Kd - differential gain
   */
  void setKd(const double &kd);
  /**
   * @brief set value of ki
   * @param ki - integral gain
   */
  void setKi(const double &ki);
  /**
   * @brief set the dt value
   * @param dt - duration of each time step
   */
  void setDt(const double &dt);
  /**
     * @brief get value of ki
     * @return Ki value of PID
     */
  double getKi();
  /**
   * @brief get value of kp
   * @return kp value of PID
   */
  double getKp();
  /**
   * @brief get value of kd
   * @return kd value of PID
   */
  double getKd();
  /**
   * @brief get the value current value of Control Output from PID controller
   * @return ctrlOp value of PID
   */
  double getCtrlOp();
  /**
   * @brief get the value of dt
   * @return dt value of PID
   */
  double getDt();

};
#endif  // WEEK4_TDD_4B_INCLUDE_CONTROLLER_H_
