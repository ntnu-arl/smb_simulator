#include <ros/ros.h>
#include <sensor_msgs/Joy.h>

sensor_msgs::Joy joy_msg;

void joyCb(const sensor_msgs::Joy &msg)
{
    joy_msg = msg;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher repub_pub = n.advertise<sensor_msgs::Joy>("joy_republished", 1);
    ros::Subscriber sub = n.subscribe("joy", 1, joyCb);
    ros::Rate loop_rate(20);
    while (ros::ok())
    {
        repub_pub.publish(joy_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
}