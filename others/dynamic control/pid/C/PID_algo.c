/*
Compute() is called either regularly or irregularly, and it works pretty well. This series isn’t about “works pretty well” though. If we’re going to turn this code into something on par with industrial PID controllers, 
we’ll have to address a few things:

Sample Time – The PID algorithm functions best if it is evaluated at a regular interval. If the algorithm is aware of this interval, we can also simplify some of the internal math.
Derivative Kick – Not the biggest deal, but easy to get rid of, so we’re going to do just that.
On-The-Fly Tuning Changes – A good PID algorithm is one where tuning parameters can be changed without jolting the internal workings.
Reset Windup Mitigation –We’ll go into what Reset Windup is, and implement a solution with side benefits
On/Off (Auto/Manual) – In most applications, there is a desire to sometimes turn off the PID controller and adjust the output by hand, without the controller interfering
Initialization – When the controller first turns on, we want a “bumpless transfer.” That is, we don’t want the output to suddenly jerk to some new value
Controller Direction – This last one isn’t a change in the name of robustness per se. it’s designed to ensure that the user enters tuning parameters with the correct sign.
NEW: Proportional on Measurement – Adding this feature makes it easier to control certain types of processes

Once we’ve addressed all these issues, we’ll have a solid PID algorithm. 


You can tune the values of Kp, Ki and Kd using the following mathematical/non-mathematical methods:
Help for the same can be found out online at https://en.wikipedia.org/wiki/PID_controller

Manual tuning  
Ziegler–Nichols
Tyreus Luyben  
Software tools Consistent tuning
Cohen–Coon  
Åström-Hägglund
*/


//working variables
unsigned long lastTime;
double Input, Output, Setpoint;
double errSum, lastErr;
double kp, ki, kd;
void Compute()
{
   /*How long since we last calculated*/
   unsigned long now = millis();
   double timeChange = (double)(now - lastTime);
  
   /*Compute all the working error variables*/
   double error = Setpoint - Input;
   errSum += (error * timeChange);
   double dErr = (error - lastErr) / timeChange;
  
   /*Compute PID Output*/
   Output = kp * error + ki * errSum + kd * dErr;
  
   /*Remember some variables for next time*/
   lastErr = error;
   lastTime = now;
}
  
void SetTunings(double Kp, double Ki, double Kd)
{
   kp = Kp;
   ki = Ki;
   kd = Kd;
}

