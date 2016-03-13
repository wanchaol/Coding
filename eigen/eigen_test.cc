#include "../utils.h"
#include <math.h>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace Eigen;
//using namespace std;

int main()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
  //double test = 4.4;
  //cout<<round(test)<<endl;
  //cout<<ceil(test)<<endl;
  //cout<<floor(test)<<endl;
}
