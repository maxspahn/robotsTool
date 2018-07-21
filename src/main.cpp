#include <stdio.h>
#include "robot.h"
#include "util.h"

int main(int argc, char *argv[])
{
  int n = 2;
  Robot *myRobot = new Robot(n);
  double* jointPos = new double[n];
  jointPos[0] = 0.5;
  jointPos[1] = 0.3;
  myRobot->SetJointPositiion(jointPos);
  myRobot->UpdateKinematics();
  double*** tforms = myRobot->GetTForms();
  for (int i = 0; i < n; ++i) {
    printMatrix(tforms[i]);
    printf("----------------------\n");
  }
  double** end = myRobot->ForwardKinematics();
  printMatrix(end);


  // Free memory
  delete myRobot;
  delete[] jointPos;
  return 0;
}
