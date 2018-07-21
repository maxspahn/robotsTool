#include <stdio.h>
#include "robot.h"
#include "util.h"

int main(int argc, char *argv[])
{
  Robot *myRobot = new Robot(3);
  double* jointPos = new double[3];
  for (int i = 0; i < 3; ++i) {
    jointPos[i] = i;
  }
  myRobot->SetJointPositiion(jointPos);
  double* test = myRobot->GetJointPosition();
  printf("Joint Positions : [%1.4f, %1.4f, %1.4f]\n",test[0], test[1], test[2] );
  double** trans = computeTransformationMatrix(0.5, 2);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      printf("%1.4f\t", trans[i][j]);
    }
    printf("\n");
  }
  
  printf("-----------------Multiplication----------\n");

  double** res = multiplyMatrices(trans, trans);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      printf("%1.4f\t", res[i][j]);
    }
    printf("\n");
  }


  // Free memory
  for (int i = 0; i < 4; ++i) {
    delete[] trans[i];
    delete[] res[i];
  }
  delete[] res;
  delete[] trans;
  delete myRobot;
  delete[] jointPos;
  return 0;
}
