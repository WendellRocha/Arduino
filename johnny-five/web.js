var five = require('johnny-five');
var http = require('http');

var board = new five.Board();

// Quando o node disparar o 'ready' os isReady será true
var isReady = false;

// isOn guarda o estado do led
var isOn = false;

var led;

// quando a comunicação estiver estabelecida
board.on('ready', function() {
    led = new five.Led(13);
    led.off();
    isReady = true;
});

// Servidor http escutando na porta 3000
http.createServer(function(req, res) {
    // em todas as requisições chegamos se é a rota raiz
    if(req.url == '/') {
        // função que muda o estado do led
        led.toggle();
        // a requisição será encerrada com a variável isOn
        // informando se o led está aceso ou não
        // a concatenação com uma string se dar porque
        // o método end precisa de uma string ou um buffer
        res.end(isOn + '');
    } else {
        // caso a requisição não seja pela rota raiz
        // a conexão será encerrada
        res.end();
    }
}).listen(3000);

console.log('listening at 3000');