#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <iostream>

double Published_time = 0;
double Subscribed_time = 0;



void Test_SubCallback(const std_msgs::Float64 &str_msg)
{	
	Subscribed_time = ros::Time::now().toSec();	
	ROS_INFO("Return time : %lf sec", Subscribed_time -  Published_time);
}


int main(int argc, char** argv)
{

	ros::init(argc, argv, "Test_Pub");

	int Hertz = 0;
	ROS_INFO("Put Hertz (Float64, 64Bits)");
	std::cin>>Hertz;

	ros::NodeHandle n;
	std_msgs::Float64 PubSub;
	ros::Publisher publisher = n.advertise<std_msgs::Float64>("PubSub", 100);
	ros::Subscriber subscriber = n.subscribe("SubPub", 1000, Test_SubCallback);  
	ros::Rate rate(Hertz);

	ROS_INFO("Publishing %d bits per sec", 64 * Hertz);


	
	while(ros::ok())
	{
	Published_time = ros::Time::now().toSec();
	PubSub.data = Published_time;
	publisher.publish(PubSub);
	ros::spinOnce();
	rate.sleep();
	}


	return 0;


}
