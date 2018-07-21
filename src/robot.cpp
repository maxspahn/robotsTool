#include "robot.h"
#include "util.h"

Robot::Robot(int noJoints){
  this->noJoints = noJoints;
  lengths = new double[noJoints];
  currentJointPosition = new double[noJoints];
  tForms = new double**[noJoints];
  tEnd = new double*[4];
  for (int i = 0; i < noJoints; ++i) {
    lengths[i] = 1;
    tForms[i] = new double*[4];
    for (int j = 0; j < 4; ++j) {
      tForms[i][j] = new double[4];
    }
  }
  for (int i = 0; i < 4; ++i) {
      tEnd[i] = new double[4];
  }
}

Robot::~Robot(){
  delete[] currentJointPosition;
  delete[] lengths;
  for (int i = 0; i < noJoints; ++i) {
    for (int j = 0; j < 4; ++j) {
      delete[] tForms[i][j];
    }
    delete[] tForms[i];
  }
  delete[] tForms;
  for (int i = 0; i < 4; ++i) {
    delete[] tEnd[i];
  }
  delete[] tEnd;
}

void Robot::SetJointPositiion(double* jointPositions){
  for (int i = 0; i < noJoints; ++i) {
    currentJointPosition[i] = jointPositions[i];
  }
}

double* Robot::GetJointPosition(){
  return currentJointPosition;
}

void Robot::UpdateKinematics(){
  for (int i = 0; i < noJoints; ++i) {
    this->tForms[i] = computeTransformationMatrix(currentJointPosition[i], lengths[i]); 
  }
  this->tEnd = multiplyMatrices(this->tForms[0], this->tForms[1]);
}

double** Robot::ForwardKinematics(){
  return this->tEnd;
}

double*** Robot::GetTForms(){
  return this->tForms;
}

