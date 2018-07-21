#include <stdio.h>

#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
private:
  double* currentJointPosition;
  int noJoints;
  double* lengths;
  double*** tForms;
  double** tEnd;

public:
  Robot(int);
  virtual ~Robot();
  void SetJointPositiion(double*);
  double* GetJointPosition();
  void UpdateKinematics();
  double** ForwardKinematics();
  double*** GetTForms();
};

#endif /* ROBOT_H */
