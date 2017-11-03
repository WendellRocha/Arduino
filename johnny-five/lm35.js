var five = require('johnny-five');
var http = require('http');
var board = new five.Board();

var temperature;
var temp;

board.on('ready', function () {
    temperature = new five.Thermometer({
        controller: "LM35",
        pin: "A0"
    });

   /*  temperature.on("data", function () {
        console.log("celsius: %d", this.C);
        console.log("fahrenheit: %d", this.F);
        console.log("kelvin: %d", this.K);
    }); */
});

http.createServer(function(req, res) {
    res.writeHead(200, {
        'Content-Type' : 'text/plain; charset=utf-8'
    });
    temperature.on('change', function() {
       temp = this.celsius;
       res.write(temp + 'ºC');
    });
}).listen(3000);

console.log("listening on 3000");