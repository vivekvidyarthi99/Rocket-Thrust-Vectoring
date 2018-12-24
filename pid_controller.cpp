/**
 * Thrust Vectoring PID Controller
 *\

#include "pid_controller.h"


int k_p = 1;
int k_i = 1;
int k_d = 1;


 // k_p = proportional constant
 // k_i = integrational constant
 // k_d = differential constant
 // err = expected output - actual output (error)
 // integ = integral error from previous loop + err (integral error)
 // der = erro - err from previous loop (differential error)
 // dt = execution time of loop

int err = 0;
int integ = 0;
int der = 0;
int dt = 0;

int t = 700;

while(t>0){
	output = k_p +err + (k_i * integ * dt) + (k_d * der / dt);
	t--;
}
