#include <chrono>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class Publisher : public rclcpp::Node {
public:
  Publisher() : Node("publisher") {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    std::chrono::duration<int> seconds(1);
    timer_ = this->create_wall_timer(seconds, std::bind(&Publisher::timer_callback, this));
  }

private:
  void timer_callback(){
    auto message = std_msgs::msg::String();
    message.data = "Hello, ROS 2!";
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Publisher>());
  rclcpp::shutdown();
  return 0;
}
