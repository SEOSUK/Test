#include "ros/ros.h"
#include <std_msgs/UInt16.h>
#include "Test/TestService.h"

double Request_Send = 0;
double Response_Receive = 0;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Test_Client");


	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<Test::TestService>("/TestService");
	Test::TestService Service;

  Request_Send = ros::Time::now().toSec();
  Service.request.Request = Request_Send;

  if (client.call(Service))
   {
	  Response_Receive = ros::Time::now().toSec();
    ROS_INFO("Total process : %lf time spend", Response_Receive - Request_Send);
   }
  else
   {
    ROS_ERROR("Failed");
    return 1;
  }
  
 return 0;
}
