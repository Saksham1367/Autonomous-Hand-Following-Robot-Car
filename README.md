# Autonomous Hand-Following Robot Car

## Overview

The **Autonomous Hand-Following Robot Car** is a simple yet advanced robotics project that enables a robot to follow a moving hand or object using ultrasonic sensors. The project is built with **Arduino Uno** as the microcontroller, **HC-SR04 ultrasonic sensors** for distance measurement, and **L293D motor driver** to control the robot's movement. The car autonomously follows the detected object and avoids obstacles in its path.

## Features
- **Hand Following**: The robot follows a hand using ultrasonic sensors.
- **Obstacle Avoidance**: The robot detects obstacles and avoids them by changing direction.
- **Autonomous Movement**: The robot can move autonomously based on hand proximity.

## Components Used

- **Arduino Uno**: Microcontroller that processes sensor data and controls motors.
- **HC-SR04 Ultrasonic Sensors**: Used for measuring distances from objects and hands.
- **L293D Motor Driver**: A dual H-Bridge motor driver used to control the DC motors.
- **DC Motors**: Used for driving the robot's wheels.
- **Robot Chassis**: A frame to hold and organize all components.
- **Jumper Wires**: For connecting components.
- **Power Supply**: A battery pack to power the Arduino and motors.

## Code Explanation

The code uses **HC-SR04 ultrasonic sensors** to detect the proximity of objects. If the distance is below a certain threshold, the robot will stop or change direction to avoid obstacles. The robot moves forward when no obstacle is detected.

### Key Functions:
- **moveForward()**: Moves the robot forward.
- **stopCar()**: Stops the car if an obstacle is detected.
- **getDistance()**: Measures the distance using the ultrasonic sensor.
# Hardware Setup for Autonomous Hand-Following Robot Car

## Required Components

1. **Arduino Uno**: The main microcontroller that controls the car.
2. **HC-SR04 Ultrasonic Sensors (3 units)**: For detecting obstacles and hand movements.
3. **L293D Motor Driver**: A dual H-Bridge motor driver for controlling DC motors.
4. **DC Motors (2 units)**: Motors for driving the wheels of the robot.
5. **Robot Chassis**: A frame that houses all the components.
6. **Jumper Wires**: For connecting various components together.
7. **Power Supply**: A 9V battery or a 12V power pack to power the Arduino and motors.
8. **Wheels (2 units)**: Attached to the DC motors to move the robot.

## Wiring the Components

### 1. **HC-SR04 Ultrasonic Sensors**

The **HC-SR04** ultrasonic sensors will be used to detect the proximity of objects or hands. In this project, three sensors will be used.

| **HC-SR04 Pin**  | **Arduino Pin** |
|------------------|-----------------|
| VCC              | 5V              |
| GND              | GND             |
| Trig (Sensor 1)  | Pin 9           |
| Echo (Sensor 1)  | Pin 10          |
| Trig (Sensor 2)  | Pin 11          |
| Echo (Sensor 2)  | Pin 12          |
| Trig (Sensor 3)  | Pin 13          |
| Echo (Sensor 3)  | Pin A0          |

### 2. **L293D Motor Driver**

The **L293D** motor driver is used to control the movement of the robot by driving the motors. Connect the motor driver to the Arduino Uno as follows:

| **L293D Pin**    | **Arduino Pin** |
|------------------|-----------------|
| IN1              | Pin 3           |
| IN2              | Pin 4           |
| IN3              | Pin 5           |
| IN4              | Pin 6           |
| EN1              | 5V              |
| EN2              | 5V              |
| Motor A (Out1)   | Motor A         |
| Motor B (Out2)   | Motor B         |

- **Motor A (Out1 & Out2)**: Connect the two terminals of **DC Motor 1**.
- **Motor B (Out3 & Out4)**: Connect the two terminals of **DC Motor 2**.
- **IN1, IN2**: Control the forward and backward movement of **Motor 1**.
- **IN3, IN4**: Control the forward and backward movement of **Motor 2**.
- **EN1, EN2**: Enable the motors by connecting them to 5V to power the motors.

### 3. **DC Motors**

The **DC motors** are used to drive the wheels. Each motor is connected to the **L293D** motor driver as described above. Ensure that the motors are securely attached to the robot chassis and that they are powered through the L293D motor driver.

### 4. **Power Supply**

The **Arduino Uno** requires a power supply to operate, and the motors need a higher current for movement. You can use a **9V battery** or a **12V DC power pack** to power both the Arduino and the motors. Connect the positive terminal of the battery or power supply to the **VIN** pin on the Arduino, and connect the ground to the **GND** pin.

### 5. **Final Setup**

Once all the components are wired correctly:

- Place the **ultrasonic sensors** at the front, sides, and back of the robot to detect objects and your hand.
- Attach the **DC motors** to the wheels of the robot chassis.
- Ensure that the **L293D motor driver** is properly connected to the motors and Arduino.

Now, your robot is ready for action!

## Conclusion

This section covers the hardware setup for the Autonomous Hand-Following Robot Car. After completing this setup, you'll be able to run the robot autonomously. The next step would be to upload the code to the Arduino and test the robot’s behavior.

For further details, please check the **code.c file** section of the repository.
