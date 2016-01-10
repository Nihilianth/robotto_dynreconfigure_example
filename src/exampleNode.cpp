#include <ros/ros.h>

#include <dynamic_reconfigure/server.h>
#include <robotto_dynreconfigure_example/ExampleConfig.h>

typedef robotto_dynreconfigure_example::ExampleConfig ConfigType;

void callback(ConfigType &config, uint32_t level) {
    config.groups.groups.hidden_group.state = config.groups.groups.show_hidden_group;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "robotto_dynreconfigure_example_node");

  // dynamic_reconfigure
  dynamic_reconfigure::Server<ConfigType> server;
  dynamic_reconfigure::Server<ConfigType>::CallbackType f;

  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

  ROS_INFO("Spinning node");
  ros::spin();
  return 0;
}
