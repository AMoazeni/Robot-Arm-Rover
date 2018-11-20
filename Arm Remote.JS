let point_thresh = 0
let swing_thresh = 0
let base = 0
let elbow = 0
let grip = 0
let shoulder = 0
basic.pause(500)
radio.setGroup(25)
shoulder = 54
elbow = 100
base = 74
grip = 128
swing_thresh = 300
point_thresh = 900
basic.showLeds(`
    . . . # #
    . . # . .
    # # # . .
    . . # . .
    . . . # #
    `)
basic.forever(function () {
    if (input.buttonIsPressed(Button.A)) {
        shoulder = pins.map(
        input.acceleration(Dimension.Y) * -1,
        -1023,
        1023,
        54,
        160
        )
        radio.sendValue("shoulder", shoulder)
        elbow = pins.map(
        input.acceleration(Dimension.Y),
        -1023,
        1023,
        70,
        150
        )
        radio.sendValue("elbow", elbow)
        base = pins.map(
        input.acceleration(Dimension.X),
        -1023,
        1023,
        10,
        140
        )
        radio.sendValue("base", base)
    } else if (input.buttonIsPressed(Button.B)) {
        if (grip == 86) {
            grip = 120
        } else {
            grip = 86
        }
        radio.sendValue("grip", grip)
        basic.pause(500)
    }
})
