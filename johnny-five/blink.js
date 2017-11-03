var five = require('johnny-five');

// instanciando a placa
var board = new five.Board();

/*O evento ready é disparado quando a comunicação entre
o node e o arduino é estabelicida*/
board.on('ready', function() {
    led = new five.Led(13);
    led.blink(500);
});