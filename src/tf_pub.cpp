#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "forbot_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;

  while(n.ok()){

    tf::Quaternion laser_quat = tf::createQuaternionFromRPY(3.1415 , 0.0, 0.0);
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(laser_quat, tf::Vector3(0.42, 0.0, 0.1)),
        ros::Time::now(),"base_link", "base_laser_link"));
    r.sleep();
  }
}