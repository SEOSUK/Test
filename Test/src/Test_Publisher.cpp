#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <iostream>






int main(int argc, char** argv)
{

	ros::init(argc, argv, "Test_Pub");

	int Hertz = 0;
	ROS_INFO("Put Hertz (Float64, 64Bits)");
	std::cin>>Hertz;

	ros::NodeHandle n;
	std_msgs::Float64 data;
	ros::Publisher publisher = n.advertise<std_msgs::Float64>("data", 100);
	ros::Rate rate(Hertz);   

	ROS_INFO("Publishing %d bits per sec", 64 * Hertz);


	
	while(ros::ok())
	{

	data.data = ros::Time::now().toSec();
	publisher.publish(data);
	ros::spinOnce();
	rate.sleep();
	}


	return 0;


}
