# Robot Arm Rover
Gesture controlled Robot Arm mounted on a Buggy chassis using the BBC Microbit board.
<br><br>

[![Robot Arm Rover]()](https://www.youtube.com/watch?v=7o0pC0yS0pI)

# Materials list
You make the Buggy Chassis and Robot Arm from scratch using a laser cutter (cardboard, plywood or plastic) or a 3D printer. The following is a list of materials needed for this project, purchase URLs included:

1. [BBC Microbit board](https://microbit.org/resellers/)
2. Motor Driver Board for the Microbit: [Adafruit Crikit Board](https://www.adafruit.com/product/3928) or [Kitronik All-In-One Robotics Board](https://www.kitronik.co.uk/5641-all-in-one-robotics-board-for-bbc-microbit.html)
3. [Buggy Chassis](https://www.sparkfun.com/products/13301), [Motors](https://www.sparkfun.com/products/13302), [Wheels](https://www.sparkfun.com/products/13259)
4. [meArm Robot Arm](https://bit.ly/2DA4IzO) (Laser Cutter file included in this repository)


# Build instructions
Go to the following links to get build instructions for the [Chassis](https://learn.sparkfun.com/tutorials/microbot-kit-experiment-guide/assembling-your-robot) and [Robot Arm](https://learn.mime.co.uk/assets/docs/control-your-mearm-from-arduino/MeArm_v1.0_Manual_for_Arduino_v1.0.pdf). 
<br>
<br>
If you're using the Kitronic All-In-One Robotics board, the [datasheet](https://www.kitronik.co.uk/pdf/5641-microbit-robotics-board-datasheet.pdf) shows that PINs 0, 8, 12, and 16 are used to control the wheels. You can flip the RED/BLACK motor wires to reverse motor direction to match software commands.
<br>
<br>
The Robot Arm uses four 9g Servo motors connected directly to the Microbit GPIO PINs and driven by PWM signals. You may need to solder on some female header pins to access the full GPIO of the Microbit board.
<br>
<br>


| Robot Arm Servo | PIN    |
| ------------- |:-------------:|
| Base Servo      | PIN 1  |
| Shoulder Servo  | PIN 13 |
| Elbow Servo     | PIN 14 |
| Gripper Servo   | PIN 15 |

# Code
The BBc Microbit has built in Bluetooth which makes wireless communication possible. This means you can control the robot with other Microbit board, as well as a smartphone!

## Smartphone App Control (C++)
1. Install the Microbit App for [iPhone](https://itunes.apple.com/us/app/micro-bit/id1092687276?mt=8) or [Android](https://play.google.com/store/apps/details?id=com.samsung.microbit).
2. Download Robot [C++ code](https://github.com/AMoazeni/Robot-Arm-Rover/blob/master/C%2B%2B%20Code/Robot%20Arm%20Rover.cpp) from this repository or the [compiled .hex file](https://github.com/AMoazeni/Robot-Arm-Rover/blob/master/C%2B%2B%20Code/Robot%20Arm%20Rover.hex).
3. Upload C++ code to Microbit using the [YOTTA offline compiler](https://lancaster-university.github.io/microbit-docs/offline-toolchains/). More info at [BBC Microbit C++ Documentation](https://lancaster-university.github.io/microbit-docs/ble/profile/).
4. Bluetooth pair the Microbit with your phone.
5. Drive it around using the D-PAD Joystick built into the app.

## Microbit Radio Control (Code Blocks)
Refer to the video at the top of this page for a guide to the Drive Gestures. One Microbit Controls the Robot electronics (Reciever), another sends Arm commands (Transmitter), and the third one sends Drive commands (Drive Remote).

1. Download [Buggy.hex](https://github.com/AMoazeni/Robot-Arm-Rover/blob/master/Javascripts%20Code%20Blocks/Robot.hex) onto the Robot.
2. Download [Arm Remote.hex](https://github.com/AMoazeni/Robot-Arm-Rover/blob/master/Javascripts%20Code%20Blocks/Arm%20Remote.hex) onto the Arm Remote Microbit.
3. Download [Drive Remote.hex](https://github.com/AMoazeni/Robot-Arm-Rover/blob/master/Javascripts%20Code%20Blocks/Drive%20Remote.hex) onto the Drive Remote Microbit.


