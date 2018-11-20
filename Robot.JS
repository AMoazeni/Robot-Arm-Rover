let point_thresh = 0
let swing_thresh = 0
let grip = 0
let base = 0
let distance = 0
let elbow = 0
let shoulder = 0
radio.onReceivedValue(function (name, value) {
    led.toggle(0, 0)
    if (name == "shoulder") {
        pins.servoWritePin(AnalogPin.P13, value)
    } else if (name == "elbow") {
        pins.servoWritePin(AnalogPin.P14, value)
    } else if (name == "base") {
        pins.servoWritePin(AnalogPin.P1, value)
    } else if (name == "grip") {
        pins.servoWritePin(AnalogPin.P15, value)
    } else if (name == "forward") {
        pins.analogWritePin(AnalogPin.P0, 1023)
        pins.analogWritePin(AnalogPin.P16, 0)
        pins.analogWritePin(AnalogPin.P8, 1023)
        pins.analogWritePin(AnalogPin.P12, 0)
    } else if (name == "left") {
        pins.analogWritePin(AnalogPin.P0, 0)
        pins.analogWritePin(AnalogPin.P16, 1023)
        pins.analogWritePin(AnalogPin.P8, 1023)
        pins.analogWritePin(AnalogPin.P12, 0)
    } else if (name == "right") {
        pins.analogWritePin(AnalogPin.P0, 1023)
        pins.analogWritePin(AnalogPin.P16, 0)
        pins.analogWritePin(AnalogPin.P8, 0)
        pins.analogWritePin(AnalogPin.P12, 1023)
    } else if (name == "left_swing") {
        pins.analogWritePin(AnalogPin.P0, 1023 - value)
        pins.analogWritePin(AnalogPin.P16, 0)
        pins.analogWritePin(AnalogPin.P8, 1023)
        pins.analogWritePin(AnalogPin.P12, 0)
    } else if (name == "right_swing") {
        pins.analogWritePin(AnalogPin.P0, 1023)
        pins.analogWritePin(AnalogPin.P16, 0)
        pins.analogWritePin(AnalogPin.P8, 1023 - value)
        pins.analogWritePin(AnalogPin.P12, 0)
    } else if (name == "reverse") {
        pins.analogWritePin(AnalogPin.P0, 0)
        pins.analogWritePin(AnalogPin.P16, 1023)
        pins.analogWritePin(AnalogPin.P8, 0)
        pins.analogWritePin(AnalogPin.P12, 1023)
    } else if (name == "rev_L_swing") {
        pins.analogWritePin(AnalogPin.P0, 0)
        pins.analogWritePin(AnalogPin.P16, 1023 - value)
        pins.analogWritePin(AnalogPin.P8, 0)
        pins.analogWritePin(AnalogPin.P12, 1023)
    } else if (name == "rev_R_swing") {
        pins.analogWritePin(AnalogPin.P0, 0)
        pins.analogWritePin(AnalogPin.P16, 1023)
        pins.analogWritePin(AnalogPin.P8, 0)
        pins.analogWritePin(AnalogPin.P12, 1023 - value)
    } else if (name == "obstacle") {
        for (let i = 0; i < 100; i++) {
            distance = pins.analogReadPin(AnalogPin.P2)
            if (distance > 450) {
                pins.analogWritePin(AnalogPin.P0, 0)
                pins.analogWritePin(AnalogPin.P16, 0)
                pins.analogWritePin(AnalogPin.P8, 0)
                pins.analogWritePin(AnalogPin.P12, 0)
                basic.pause(500)
                if (Math.randomBoolean()) {
                    pins.analogWritePin(AnalogPin.P0, 0)
                    pins.analogWritePin(AnalogPin.P16, 1023)
                    pins.analogWritePin(AnalogPin.P8, 0)
                    pins.analogWritePin(AnalogPin.P12, 300)
                } else {
                    pins.analogWritePin(AnalogPin.P0, 0)
                    pins.analogWritePin(AnalogPin.P16, 300)
                    pins.analogWritePin(AnalogPin.P8, 0)
                    pins.analogWritePin(AnalogPin.P12, 1023)
                }
                basic.pause(1000)
            } else {
                pins.analogWritePin(AnalogPin.P0, 800)
                pins.analogWritePin(AnalogPin.P16, 0)
                pins.analogWritePin(AnalogPin.P8, 800)
                pins.analogWritePin(AnalogPin.P12, 0)
            }
        }
    } else {
        pins.analogWritePin(AnalogPin.P0, 0)
        pins.analogWritePin(AnalogPin.P16, 0)
        pins.analogWritePin(AnalogPin.P8, 0)
        pins.analogWritePin(AnalogPin.P12, 0)
    }
})
basic.pause(500)
radio.setGroup(25)
shoulder = 54
elbow = 100
base = 74
grip = 128
swing_thresh = 300
point_thresh = 900
