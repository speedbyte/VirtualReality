#include "Postrack.h"
#include <iostream>
#include <iomanip>

using get_time = std::chrono::steady_clock;
typedef std::chrono::microseconds mis;

Postrack::Postrack()
{
	this->start = get_time::now();
}


Postrack::~Postrack()
{

}

bool Postrack::updatePos(double accx, double accy, double accz, double rotx, double roty, double rotz){

	KinematicData newPoint;

	newPoint.acc[0] = accx;
	newPoint.acc[1] = accy;
	newPoint.acc[2] = accz;
	newPoint.rot_x = rotx;
	newPoint.rot_y = roty;
	newPoint.rot_z = rotz;
	newPoint.newtime = get_time::now();

	if (this->path.size() > 0){
		newPoint.oldTime = this->path.back().newtime;
		newPoint.initVel[0] = this->path.back().actVel[0];
		newPoint.initVel[1] = this->path.back().actVel[1];
		newPoint.initVel[2] = this->path.back().actVel[2];
		newPoint.pos_x = this->path.back().pos_x;
		newPoint.pos_y = this->path.back().pos_y;
		newPoint.pos_z = this->path.back().pos_z;
	}
	else{
		newPoint.oldTime = get_time::now();
	}


	if (this->calcTime(newPoint) && this->calcPos(newPoint)){
		this->path.push_back(newPoint);
		return true;
	}
	else{
		
		return false;
	}
}

bool Postrack::calcTime(KinematicData &h){

	if (h.newtime >= h.oldTime){
		h.diff = std::chrono::duration_cast<mis>(h.newtime - h.oldTime);
		return true;
	}
	else return false;
}

bool Postrack::calcPos(KinematicData &h){

	if (h.diff.count() >= 0){
		h.actVel[0] = this->getVel(h.diff.count(), h.initVel[0], h.acc[0]);
		h.actVel[1] = this->getVel(h.diff.count(), h.initVel[1], h.acc[1]);
		h.actVel[2] = this->getVel(h.diff.count(), h.initVel[2], h.acc[2]);
		h.trans_x = this->getMov(h.diff.count(), h.actVel[0]);
		h.trans_y = this->getMov(h.diff.count(), h.actVel[1]);
		h.trans_z = this->getMov(h.diff.count(), h.actVel[2]);
		h.pos_x += h.trans_x;
		h.pos_y += h.trans_y;
		h.pos_z += h.trans_z;
		return true;
	}
	else return false;
}

double Postrack::getVel(double time, double initVel, double acc){

	double velocity = 0;

	velocity = (acc * (time / 1000000)) + initVel;
	
	return velocity;
}

double Postrack::getMov(double time, double actVel){

	double move = 0;
	
	move = actVel * time;

	return move;
}

bool Postrack::printPath(){

	int pathSize = this->path.size();

	std::cout << std::fixed << std::setprecision(4);

	std::cout << std::endl;
	for (std::vector<KinematicData>::const_iterator i = this->path.begin(); i != this->path.end(); ++i)
	{
		std::cout << "Time = " << i->diff.count() * std::chrono::milliseconds::period::num / std::chrono::milliseconds::period::den << " ms";
		std::cout << "\tAcc_X = " << i->acc[0] << " mm/s^2";
		std::cout << "\tPos_X = " << i->pos_x << "mm";
		std::cout << std::endl;
		std::cout << "\t\tAcc_Y = " << i->acc[1] << " mm/s^2";
		std::cout << "\tPos_Y = " << i->pos_y << "mm";
		std::cout << std::endl;
		std::cout << "\t\tAcc_Z = " << i->acc[2] << " mm/s^2";
		std::cout << "\tPos_Z = " << i->pos_z << "mm";
		std::cout << std::endl;
	}

	return true;
}