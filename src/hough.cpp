#include "ros/ros.h"
#include "sensor_msgs/PointCloud.h"
#include "laser_geometry/laser_geometry.h"
#include "geometry_msgs/Point32.h"

class Hough{

public:

  ros::NodeHandle n_;
  ros::Publisher lines_pub_;
  ros::Subscriber sub;
  Hough(ros::NodeHandle n) :
  n_(n)
{
  lines_pub_ = n_.advertise<geometry_msgs::Point32>("edge",1000);
 
}

void cloudCallback(const sensor_msgs::PointCloud::ConstPtr& msg)
{

  geometry_msgs::Point32 edge;
  edge.x = msg->points[1].x;
  edge.y = msg->points[1].y;
  edge = manipEdge(edge);
  lines_pub_.publish(edge);

} 

geometry_msgs::Point32 manipEdge( geometry_msgs::Point32 edge)
{
  edge.x = edge.x+100;
  edge.y = edge.y+100;
  return edge;
}

/*
int Transform(const sensor_msgs::PointCloud::ConstPtr& msg)
{
  int w = 20;
  int h = 20;

// Crate the accumulator

double hough_h = ((sqrt(2) * (double)(h>w?h:w)) / 2);
double accu_h = hough_h * 2;
double accu_w = 180;
unsigned int * _accu;
 _accu = (unsigned int*)calloc(accu_h * accu_w, sizeof(unsigned int));  

double center_x = w/2;  
double center_y = h/2;  
    
for(int y=0; y<h; y++)
{
  for(int x=0;x<w;x++)
  {  
     if(
       for(int t=0; t<180;t++)
       {
         double r = ( ((double)x - center_x) * cos((double)t * 3.14 / 180)) + (((double)y - center_y) * sin((double)t * 3.14 / 180));  
         _accu[ (int)((round(r + hough_h) * 180.0)) + t]++;
       }
  }
}
  return 0;
}
*/

};




int main(int argc, char **argv)
{

  ros::init(argc,argv,"hough");
  ros::NodeHandle n;
  Hough go(n);
  ros::Subscriber sub = n.subscribe("cloud_1",1000, &Hough::cloudCallback,&go);

  ros::spin();

  return 0;

}
