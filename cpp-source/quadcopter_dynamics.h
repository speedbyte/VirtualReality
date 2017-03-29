// This is start of the header guard.  ADD_H can be any unique name.  By convention, we use the name of the header file.
#ifndef QUADCOPTERDYNAMICS_H
#define QUADCOPTERDYNAMICS_H

#include <math.h>
#include <windows.h>
#include <iostream>


class QuadcopterDynamics{
	float gravity;
	float mass;
	
	float * calculateXYZAcceleration(){
		static float acc_xyz[3];	
		//calculation of x, y, z acceleration
	}
			
	float * calculateOmegaAcceleration(){
		static float omega_acc[3];	//For the 
	}
};
 
// This is the end of the header guard
#endif
