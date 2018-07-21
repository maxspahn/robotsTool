#include <stdio.h>

#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
private:
  double* currentJointPosition;
  int noJoints;
  double* lengths;

public:
  Robot(int);
  virtual ~Robot();
  void SetJointPositiion(double*);
  double* GetJointPosition();
};

#endif /* ROBOT_H */
