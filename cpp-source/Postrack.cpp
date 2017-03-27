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

bool Postrack::updatePos(double acc){

	KinematicData newPoint;

	newPoint.acc = acc;
	newPoint.newtime = get_time::now();

	if (this->path.size() > 0){
		newPoint.oldTime = this->path.back().newtime;
		newPoint.initVel = this->path.back().actVel;
		newPoint.pos_x = this->path.back().pos_x;
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
		h.actVel = this->getVel(h.diff.count(), h.initVel, h.acc);
		h.trans_x = this->getMov(h.diff.count(), h.actVel);
		h.pos_x += h.trans_x;
		return true;
	}
	else return false;
}

double Postrack::getVel(double time, double initVel, double acc){

	double velocity = 0;

	velocity = (acc * time) + initVel;
	
	return velocity/1000;
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
		std::cout << "\tAcceleration = " << i->acc << " mm/s^2";
		std::cout << "\tPosition_X = " << i->pos_x << "mm";
		std::cout << std::endl;
	}

	return true;
}