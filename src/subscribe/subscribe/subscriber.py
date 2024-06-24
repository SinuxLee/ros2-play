import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time

class Subscriber(Node):
    def __init__(self):
        super().__init__('subscriber')
        self.subscription = self.create_subscription(String, 'topic', self.listener_callback, 10)
        self.subscription  # 防止订阅者被垃圾收集


    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)


    def run(self):
        while rclpy.ok():
            rclpy.spin(self)
            time.sleep(1)  # Sleep for 1 second

def main(args=None):
    rclpy.init(args=args)
    node = Subscriber()
    try:
        node.run()
    except KeyboardInterrupt:
        pass  # Allow graceful shutdown on Ctrl+C
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
