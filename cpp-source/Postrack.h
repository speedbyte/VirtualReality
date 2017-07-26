#pragma once
#include <vector>
<<<<<<< HEAD
=======

>>>>>>> refs/heads/master
#include <chrono>

struct KinematicData;

<<<<<<< HEAD
// xml_summary_tag.cpp
// compile with: /LD /clr /doc
// post-build command: xdcmake xml_summary_tag.dll

/// Class Postrack can track a Object based on acceleration and timestamps, or based on the time the next update will arrive. 

class Postrack
{
public:
		
	/// <summary>Postrack Constructor.
	/// </summary>
	Postrack();
	~Postrack();

	/// Creates a new point (KinematicData) in the objects path and calculates the new position. Point pets pushed to path then.
	bool updatePos(double accx, double accy, double accz, double rotx, double roty, double rotz);
	
	/// Returns the whole path in KinematicData objects
	std::vector<KinematicData> getPath();

	/// Prints the whole path to std::cout
=======
class Postrack
{
public:
	
	Postrack();
	~Postrack();

	bool updatePos(double acc);
	
	std::vector<KinematicData> getPath();

>>>>>>> refs/heads/master
	bool printPath();

private:
	
<<<<<<< HEAD
	/// Path of the object to track
	std::vector<KinematicData> path;

	/// Start time when te class is created
	std::chrono::steady_clock::time_point start;

	/// Help function that will calculate the difference of two time points and manipulate it in the KinematicData object
	bool calcTime(KinematicData &h);
	
	/// Help function that will calculate the new position based on acceleration and time elapsed since last update and manipulates it in the KinematicData object
	bool calcPos(KinematicData &h);

	/// Help function that will calculate the velocity based on acceleration, initial velocity and time
	double getVel(double time, double initVel, double acc);

	/// Help function that will calculate the movement based on velocity and time
=======
	std::vector<KinematicData> path;
	std::chrono::steady_clock::time_point start;

	bool calcTime(KinematicData &h);
	bool calcPos(KinematicData &h);

	double getVel(double time, double initVel, double acc);
>>>>>>> refs/heads/master
	double getMov(double time, double actVel);

};

struct KinematicData
{
<<<<<<< HEAD
	KinematicData(){
		for (int i = 0; i < 3; i++){
			acc[i] = 0.0;
			initVel[i] = 0.0;
			actVel[i] = 0.0;
		}
	}

	int    typ = 0;			// not in use atm - Achstyp translatorisch (TRANS_X, TRANS_Y, TRANS_Z) oder rotatorisch (ROT_X, ROT_Y, ROT_Z)
	
	std::chrono::steady_clock::time_point oldTime;
	std::chrono::steady_clock::time_point newtime;
	std::chrono::microseconds diff;
	
=======
	int    typ;         // Achstyp translatorisch (TRANS_X, TRANS_Y, TRANS_Z) oder rotatorisch (ROT_X, ROT_Y, ROT_Z)
>>>>>>> refs/heads/master
	double trans_x = 0;     // Translation um trans_x in mm
	double trans_y = 0;     // Translation um trans_y in mm
	double trans_z = 0;     // Translation um trans_z in mm
	double rot_x = 0;       // Rotation um rot_x in rad
	double rot_y = 0;       // Rotation um rot_y in rad
	double rot_z = 0;       // Rotation um rot_z in rad

<<<<<<< HEAD
	double acc[3];			// Acceleration in mm/s²
	double initVel[3];		// Velocity in mm/s
	double actVel[3];		// Velocity in mm/s
	double pos_x = 0;					// Position on x-axis in mm 
	double pos_y = 0;					// Position on y-axis in mm
	double pos_z = 0;					// Position on z-axis in mm
=======
	std::chrono::steady_clock::time_point oldTime;
	std::chrono::steady_clock::time_point newtime;
	std::chrono::microseconds diff;

	double acc = 0;			// Acceleration in mm/s²
	double initVel = 0;		// Velocity in mm/s
	double actVel = 0;		// Velocity in mm/s
	double pos_x = 0;		// Position on x-axis in mm 
	double pos_y = 0;		// Position on y-axis in mm
	double pos_z = 0;		// Position on z-axis in mm
>>>>>>> refs/heads/master
};