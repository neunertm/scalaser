#include "matching.h"
#include "matlabCppInterface/Engine.hpp"

// default constructor
matching::matching()
{

}

double matching::callStairparam(double x0,double z0,double v0)
{
  engine.executeCommand(stairparam.m(x0,z0,v0));
  engine.get("v_r",v_r);
  engine.get("se_r",se_r);
  engine.get("z_r",z_r);
  engine.get("xf",xi);
  engine.get("zf",zi);
}

