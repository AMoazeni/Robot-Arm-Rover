

#include "MicroBit.h"
#include <stdlib.h> 
#include <math.h> 

MicroBit uBit;
MicroBitImage pattern(5,5);

const uint8_t car[] {
                          0, 0, 0, 0, 0,
                          0, 0, 0, 1, 0,
                          1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1,
                          0, 1, 0, 1, 0, };

const uint8_t claw[] {
                          0, 0, 0, 1, 1,
                          0, 0, 1, 0, 0,
                          1, 1, 1, 0, 0,
                          0, 0, 1, 0, 0,
                          0, 0, 0, 1, 1, };


MicroBitImage show_car(5,5,car);
MicroBitImage show_claw(5,5,claw);

// Left Wheel
int pin0, pin16 = 0;
// Right Wheel
int pin8, pin12 = 0;

// Arm Base Pin 1, Sholder (Extend) Pin 13, Elbow (Height) Pin14, Grip Pin15
bool drive = false;

int sholder = 54;
bool extend_go_back = false;
bool extend_go_forward = false;

int elbow = 80;
bool height_go_down = false;
bool height_go_up = false;

int pivot = 74;
bool pivot_go_right = false;
bool pivot_go_left = false;

// Grip open = 86, close = 125
int grip = 86;
bool grip_closed = false;

int bwd_fwd = 0;
int lft_rgt = 0;
int connected = 0;

void setLEDIndicatorsOff() {
//    uBit.serial.printf("fwd:%d bwd:%d lft:%d rgt:%d bwd_fwd_lvl:%d lft_rgt_lvl:%d\r\n",fwd,bwd,lft,rgt,bwd_fwd_lvl,lft_rgt_lvl); 
    pattern.clear();
    uBit.display.image.paste(pattern);
}

void stop() {
  pin0 = 0;
  pin16 = 0;
  pin8 = 0;
  pin12 = 0;
  if (drive) setLEDIndicatorsOff();
  else uBit.display.print(show_claw);
}


void setLEDIndicatorForward() {
    pattern.clear();
    pattern.setPixelValue(2,0, 255);
    pattern.setPixelValue(2,1, 255);
    uBit.display.image.paste(pattern);
}

void setLEDIndicatorLeft() {
    pattern.clear();
    pattern.setPixelValue(0,2, 255);
    pattern.setPixelValue(1,2, 255);
    uBit.display.image.paste(pattern);
}

void setLEDIndicatorRight() {
    pattern.clear();
    pattern.setPixelValue(4,2, 255);
    pattern.setPixelValue(3,2, 255);
    uBit.display.image.paste(pattern);
}

void setLEDIndicatorBack() {
    pattern.clear();
    pattern.setPixelValue(2,3, 255);
    pattern.setPixelValue(2,4, 255);
    uBit.display.image.paste(pattern);
}


void writePinsDigital() {
  if(drive){
    // Buggy
    uBit.io.P0.setDigitalValue(pin0);
    uBit.io.P8.setDigitalValue(pin8);
    uBit.io.P12.setDigitalValue(pin12);
    uBit.io.P16.setDigitalValue(pin16);
  }
}

void armMode() {
    if (!drive) {
        stop();
        drive = true;
        uBit.display.print(show_car);
        uBit.sleep(100);
    } else{
        drive = false;
        uBit.display.print(show_claw);
        uBit.sleep(100);
    }
}

void armExtend() {
    if (!drive){
        if (extend_go_forward) {
            for (int i = 0; i < 20; i++){
                sholder = sholder + 1;
                if (sholder > 170) sholder = 170;
                uBit.io.P13.setServoValue(sholder);
                uBit.sleep(8);
            }
        } else if (extend_go_back){
            for (int i = 0; i < 20; i++){
                sholder = sholder - 1;
                if (sholder < 60) sholder = 60;
                uBit.io.P13.setServoValue(sholder);
                uBit.sleep(8);
            } 
        }
    }
}

void armHeight() {
    if (!drive){
        if (height_go_up) {
            for (int i = 0; i < 20; i++){
                elbow = elbow + 1;
                if (elbow > 150) elbow = 150;
                uBit.io.P14.setServoValue(elbow);
                uBit.sleep(8);
            }
        } else if (height_go_down){
            for (int i = 0; i < 20; i++){
                elbow = elbow - 1;
                if (elbow < 65) elbow = 65;
                uBit.io.P14.setServoValue(elbow);
                uBit.sleep(8);
            } 
        }
    }
}

void armPivot() {
    if (pivot_go_left) {
      for (int i = 0; i < 20; i++){
        pivot = pivot + 1;
        if (pivot > 145) pivot = 145;
        uBit.io.P1.setServoValue(pivot);
        uBit.sleep(8);
      }
    } else if (pivot_go_right){
      for (int i = 0; i < 20; i++){
        pivot = pivot - 1;
        if (pivot < 0) pivot = 0;
        uBit.io.P1.setServoValue(pivot);
        uBit.sleep(8);
     } 
    }
    pivot_go_left = 0;
    pivot_go_right = 0;
}

void armGrip() {
if (grip_closed) {
    grip = 118;
    grip_closed = false;
    uBit.io.P15.setServoValue(grip);
} else{
        grip = 84;
        grip_closed = true;
        uBit.io.P15.setServoValue(grip);
        }
}

void onConnected(MicroBitEvent)
{
    connected = 1;

    if (connected == 1) {
        uBit.display.print("C");
    } else {
        uBit.display.print("D");
    }
}

void onDisconnected(MicroBitEvent)
{
    connected = 0;
    stop();
    uBit.io.P1.setAnalogValue(0);
    uBit.io.P13.setAnalogValue(0);
    uBit.io.P14.setAnalogValue(0);
    uBit.io.P15.setAnalogValue(0);

    if (connected == 1) {
        uBit.display.print("C");
    } else {
        uBit.display.print("D");
    }
    uBit.reset();
}


void onDpadControllerEvent(MicroBitEvent e)
{
    
  uBit.serial.printf("event %d\n",e.value); 

  // Button 1 - Forward
  if (e.value == MES_DPAD_BUTTON_1_DOWN) {
    if (drive){
      pin0 = 1;
      pin16 = 0;
      pin8 = 1;
      pin12 = 0;
      setLEDIndicatorForward();
    } else {
        ::height_go_up = true;
        armHeight();
      }

  } else if (e.value == MES_DPAD_BUTTON_1_UP) {
      stop();
      ::height_go_up = false;
 
  }

  // Button 2 - Reverse
  if (e.value == MES_DPAD_BUTTON_2_DOWN) {
    if (drive){
      pin0 = 0;
      pin16 = 1;
      pin8 = 0;
      pin12 = 1;
      setLEDIndicatorBack();
    } else {
        ::height_go_down = true;
        armHeight();
    }

  } else if (e.value == MES_DPAD_BUTTON_2_UP) {
      stop();
      ::height_go_down = false;
  }

  // Button 3 - Turn Left
  if (e.value == MES_DPAD_BUTTON_3_DOWN) {
      if (drive){
        pin0 = 0;
        pin16 = 1;
        pin8 = 1;
        pin12 = 0;
        setLEDIndicatorLeft();
      } else {
        ::extend_go_back = true;
        armExtend();
      }

  } else if (e.value == MES_DPAD_BUTTON_3_UP) {
      stop();
      ::extend_go_back = false;

  }
  
  // Button 4 - Turn Right
  if (e.value == MES_DPAD_BUTTON_4_DOWN) {
      if (drive){
      pin0 = 1;
      pin16 = 0;
      pin8 = 0;
      pin12 = 1;
      setLEDIndicatorRight();
      } else {
        ::extend_go_forward = true;
        armExtend();
      }

  } else if (e.value == MES_DPAD_BUTTON_4_UP) {
      stop();
      ::extend_go_forward = false;
  }

  // Button A - Arm Mode / Car Mode
  if (e.value == MES_DPAD_BUTTON_A_DOWN) {
      armMode();
  } else if (e.value == MES_DPAD_BUTTON_A_UP) {
      uBit.sleep(100);
  }

  // Button B - Gripper
  if (e.value == MES_DPAD_BUTTON_B_DOWN) {
      armGrip();
  } else if (e.value == MES_DPAD_BUTTON_B_UP) {
      uBit.sleep(100);
  }

  // Button C - Arm Pivot Left (persistent through Arm Mode and Drive Mode)
  if (e.value == MES_DPAD_BUTTON_C_DOWN) {
    pivot_go_left = true;
    
  } else if (e.value == MES_DPAD_BUTTON_C_UP) {
    pivot_go_left = false;
    //pivot_go_right = 0;
    //uBit.sleep(100);
  }

  // Button D - Arm Pivot Right
  if (e.value == MES_DPAD_BUTTON_D_DOWN) {
    ::pivot_go_right = true;

  } else if (e.value == MES_DPAD_BUTTON_D_UP) {
    //pivot_go_left = 0;
    ::pivot_go_right = false;
    //uBit.sleep(100);
  }

  // Write To Buggy
  writePinsDigital();
  armPivot();

}

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    //uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_EVT_ANY, onDpadControllerEvent);
    //uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_EVT_ANY, onDpadControllerEvent);

    uBit.display.print(show_car);

    uBit.messageBus.listen(MES_DPAD_CONTROLLER_ID, 0, onDpadControllerEvent); 

    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, onDisconnected);

    //uBit.display.setDisplayMode();
    
    // Write To Robot Arm
    // Robot Arm P15=grip, P1=pivot, P13=sholder, P14=elbow

    //uBit.io.P13.setServoValue(sholder);
    //uBit.io.P14.setServoValue(elbow);
    
    release_fiber();
}