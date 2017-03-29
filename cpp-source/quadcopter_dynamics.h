// This file is not yet finish. The dynamics is needed for calculating different parameters of the quadcopter.
// This is start of the header guard. By convention, we use the name of the header file.
#ifndef QUADCOPTER_DYNAMICS_H
#define QUADCOPTER_DYNAMICS_H

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
	
	float * calculateXYZVelocity(){
	    static float velo_xyz[3];
	    //For calculating xyz velocities
	}
	
	float * calculateXYZPosition(){
	    static float pos_xyz[3];
	    //For calculating xyz positions
	}
    
	float * calculateOmegaAcceleration(){
		static float omega_acc[3];	
		//For calculating the angular acceleration of the quadcopter 
	}
};
 
// This is the end of the header guard
#endif
