#include "ros/ros.h"
#include <std_msgs/UInt16.h>
#include "Test/TestService.h"


double Request_Receive = 0;
double Response_Send = 0;


 bool Callback(Test::TestService::Request  &req,
          Test::TestService::Response &res)
 {
	Request_Receive = req.Request;
	Response_Send = ros::Time::now().toSec();

	ROS_INFO("Client->Server : %lf time spend", Response_Send - Request_Receive);
	return true;
 }
 

 
 int main(int argc, char **argv)
 {
   ros::init(argc, argv, "TestServer");
   ros::NodeHandle n;
 
   ros::ServiceServer service = n.advertiseService("/TestService", Callback);
   ROS_INFO("Network ping Test");


   ros::spin(); 
   return 0;
 }
