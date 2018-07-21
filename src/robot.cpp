#include "robot.h"

Robot::Robot(int noJoints){
  this->noJoints = noJoints;
  lengths = new double[noJoints];
  currentJointPosition = new double[noJoints];
  for (int i = 0; i < noJoints; ++i) {
    lengths[i] = 1;
  }
}

Robot::~Robot(){
  delete[] currentJointPosition;
  delete[] lengths;
}

void Robot::SetJointPositiion(double* jointPositions){
  for (int i = 0; i < noJoints; ++i) {
    currentJointPosition[i] = jointPositions[i];
  }
}

double* Robot::GetJointPosition(){
  return currentJointPosition;
}
