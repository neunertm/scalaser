#include "matlabCppInterface/Engine.hpp"

class matching
{
 private:
  
  double v0;
  double v_r;

  double se_r;
  double xf;
  double zf;
  double z_r;

  double fov_s;
  double fov_e;
  double phi;
  double dz;

 public:
  
  void callStairparam(x0,z0,v0);
  double getResultVector() {return v_r;}

}
