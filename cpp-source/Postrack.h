#pragma once
#include <vector>
#include <chrono>

struct KinematicData;

class Postrack
{
public:
	
	Postrack();
	~Postrack();

	bool updatePos(double acc);
	
	std::vector<KinematicData> getPath();

	bool printPath();

private:
	
	std::vector<KinematicData> path;
	std::chrono::steady_clock::time_point start;

	bool calcTime(KinematicData &h);
	bool calcPos(KinematicData &h);

	double getVel(double time, double initVel, double acc);
	double getMov(double time, double actVel);

};

struct KinematicData
{
	int    typ;         // Achstyp translatorisch (TRANS_X, TRANS_Y, TRANS_Z) oder rotatorisch (ROT_X, ROT_Y, ROT_Z)
	double trans_x = 0;     // Translation um trans_x in mm
	double trans_y = 0;     // Translation um trans_y in mm
	double trans_z = 0;     // Translation um trans_z in mm
	double rot_x = 0;       // Rotation um rot_x in rad
	double rot_y = 0;       // Rotation um rot_y in rad
	double rot_z = 0;       // Rotation um rot_z in rad

	std::chrono::steady_clock::time_point oldTime;
	std::chrono::steady_clock::time_point newtime;
	std::chrono::microseconds diff;

	double acc = 0;			// Acceleration in mm/s²
	double initVel = 0;		// Velocity in mm/s
	double actVel = 0;		// Velocity in mm/s
	double pos_x = 0;		// Position on x-axis in mm 
	double pos_y = 0;		// Position on y-axis in mm
	double pos_z = 0;		// Position on z-axis in mm
};