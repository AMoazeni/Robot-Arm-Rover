let grip = 0
let base = 0
let point_thresh = 0
let swing_thresh = 0
let elbow = 0
let shoulder = 0
basic.pause(500)
radio.setGroup(25)
shoulder = 54
elbow = 100
base = 74
grip = 128
swing_thresh = 300
point_thresh = 850
basic.showLeds(`
    . . # . .
    . . . # .
    # # # # #
    # # # # #
    . # . # .
    `)
basic.forever(function () {
    if (input.buttonIsPressed(Button.A)) {
        if (Math.abs(input.acceleration(Dimension.X)) < swing_thresh) {
            radio.sendValue("reverse", 1)
        } else if (Math.abs(input.acceleration(Dimension.X)) < point_thresh && Math.abs(input.acceleration(Dimension.X)) > swing_thresh) {
            if (input.acceleration(Dimension.X) < 0) {
                radio.sendValue("rev_L_swing", pins.map(
                Math.abs(input.acceleration(Dimension.X)),
                swing_thresh,
                point_thresh,
                0,
                1023
                ))
            } else {
                radio.sendValue("rev_R_swing", pins.map(
                Math.abs(input.acceleration(Dimension.X)),
                swing_thresh,
                point_thresh,
                0,
                1023
                ))
            }
        } else if (input.acceleration(Dimension.X) < point_thresh * -1) {
            radio.sendValue("right", 1)
        } else if (input.acceleration(Dimension.X) > point_thresh) {
            radio.sendValue("left", 1)
        }
        basic.pause(100)
    } else if (input.buttonIsPressed(Button.B)) {
        if (Math.abs(input.acceleration(Dimension.X)) < swing_thresh) {
            radio.sendValue("forward", 1)
        } else if (Math.abs(input.acceleration(Dimension.X)) < point_thresh && Math.abs(input.acceleration(Dimension.X)) > swing_thresh) {
            if (input.acceleration(Dimension.X) > 0) {
                radio.sendValue("left_swing", pins.map(
                Math.abs(input.acceleration(Dimension.X)),
                swing_thresh,
                point_thresh,
                0,
                1023
                ))
            } else {
                radio.sendValue("right_swing", pins.map(
                Math.abs(input.acceleration(Dimension.X)),
                swing_thresh,
                point_thresh,
                0,
                1023
                ))
            }
        } else if (input.acceleration(Dimension.X) < point_thresh * -1) {
            radio.sendValue("right", 1)
        } else if (input.acceleration(Dimension.X) > point_thresh) {
            radio.sendValue("left", 1)
        }
        basic.pause(100)
    } else if (input.lightLevel() > 150) {
        radio.sendValue("obstacle", 1)
        basic.showIcon(IconNames.Heart)
        basic.pause(100)
        basic.showIcon(IconNames.SmallHeart)
        basic.pause(100)
    } else {
        radio.sendValue("drive", 0)
        basic.showLeds(`
            . . # . .
            . . . # .
            # # # # #
            # # # # #
            . # . # .
            `)
    }
})
