# Robot Arm Rover
Gesture controlled Robot Arm mounted on a Buggy chassis using the BBC Microbit board.
<br>
[![Robot Arm Rover]()]()

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
