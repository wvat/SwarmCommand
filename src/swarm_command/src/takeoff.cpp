#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cstdio>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

class Takeoff : public rclcpp::Node
{
    public:
        Takeoff()
        : Node("takeoff")
        {
            publisher_ = this->create_publisher<std_msgs::msg::String>("takeoff", 10);
            timer_ = this->create_wall_timer(500ms, std::bind(&Takeoff::timer_callback, this));
        }

    private:
        void timer_callback()
        {
            auto message = std_msgs::msg::String();
            message.data = "takeoff";
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
            publisher_->publish(message);
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        size_t count_;
};

int main(int argc, char ** argv)
{
    printf("Starting takeoff node\n");
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Takeoff>());
    rclcpp::shutdown();
    return 0;
}
