# Robot Arm Rover
Gesture controlled Robot Arm mounted on a Buggy chassis using the BBC Microbit board.
<br>
[![Robot Arm Rover](https://img.youtube.com/vi/7o0pC0yS0pI/0.jpg)](https://www.youtube.com/watch?v=7o0pC0yS0pI)

# Materials list
You make the Buggy Chassis and Robot Arm from scratch using a laser cutter (cardboard, plywood or plastic) or a 3D printer. The following is a list of materials needed for this project, purchase URLs included:

1. [BBC Microbit board]()
2. Motor Driver Board for the Microbit: [Sparkfun Crikit Board]() or [Kitronik All-In-One Robotics Board]()
3. [Buggy Chassis](), [Motors](), [Wheels]()
4. [meArm Robot Arm]() (Laser Cutter file included in this repository)


# Build instructions
Go to the following links to get build instructions for the [Chassis]() and [Robot Arm](). 
<br>
<br>
If you're using the Kitronic All-In-One Robotics board, the [datasheet]() shows that PINs 0, 8, 12, and 16 are used to control the wheels. You can flip the RED/BLACK motor wires to reverse motor direction to match software commands.
<br>
<br>
The Robot Arm uses four 9g Servo motors connected directly to the Microbit GPIO PINs and driven by PWM signals. You may need to solder on some female header pins to access the full GPIO of the Microbit board.
<br>
<br>
1. Robot Arm Base Servo -> PIN 1
2. Robot Arm Shoulder Servo -> PIN 13
3. Robot Arm Elbow Servo -> PIN 14
4. Robot Arm Gripper Servo -> PIN 15


# Code
The BBc Microbit has built in Bluetooth which makes wireless communication possible. This means you can control the robot with other Microbit board, as well as a smartphone!

## Smartphone App Control (C++)
1. Install the Microbit App for [iPhone]() or [Android]().
2. Download Robot [C++ code]() from this repository.
3. Upload C++ code to Microbit using the [YOTTA offline compiler](). More info at [BBC Microbit C++ Documentation]().
4. Bluetooth pair the Microbit with your phone.
5. Drive it around using the D-PAD Joystick built into the app.

## Microbit Radio Control (Code Blocks)
Refer to the video at the top of this page for a guide to the Drive Gestures. One Microbit Controls the Robot electronics ([Robot Reciever Blocks]()), another sends Arm commands ([Arm Remote Transmitter Blocks]()), and the third one sends Drive commands ([Drive Remote Transmitter]()).

1. Download [Buggy.hex]() onto the Robot.
2. Download [Arm Remote.hex]() onto the Arm Remote Microbit.
3. Download [Drive Remote.hex]() onto the Drive Remote Microbit.


