# Arduino
  Alguns códigos feitos por mim para o Arduino.

## Estacionamentov1.5
Sistema de estacionamento simples com controle da rotação do cooler de acordo com a temperatura ambiente. O controle da rotação do cooler foi adicionado pois, provavelmente o arduino ficará em uma caixa sem ventilação.
O ticket é impresso no seguinte formato:
Nome do Cliente;
bom dia/boa tarde/boa noite de acordo com o horário;
Segunda-Feira, 1 de Janeiro de 1969;
Horário de entrada: 21:59:10;
Para liberar a sua saída, passe no caixa e troque o ticket pelo cartão.

## estacionamento
Sistema de estacionamento simples (o sistema acima é um pouco mais complexo) com impressão do ticket na comunicação serial.
O ticket é impresso no seguinte formato:
Nome do Cliente;
bom dia/boa tarde/boa noite de acordo com o horário;
1/1/1969;
Horário de entrada: 21:59:10;
Para liberar a sua saída, passe no caixa e troque o ticket pelo cartão.
  
## led_pwm
Varia o brilho do led variando a tensão da porta PWM.

## semaforo
Sistema simples de semáforo sincronizado com o semáforo de pedestres. O vermelho para os carros pisca sinalizando que a contágem está nos últimos 10 segundos e o verde para os pedestres fica piscando nos últimos 10 segundos sinalizando de que o sinal irá fechar.

## semaforo_simples
Sistema simples de semáforo sincronizado com o semáforo de pedestres.

## temperatura
Sistema de controle da rotação do cooler de acordo com a temperatura (é o mesmo utilizado no Estacionamentov1.5).
Se a temperatura estiver abaixo dos 25ºC o cooler ficará desligado.
Se a temperatura estiver entre 25º e 27ºC o cooler ligará e ficará com 50% da rotação. (Um cooler de 3000 RPM estará com 1500 RPM).
Se a temperatura estiver acima de 27ºC o cooler irá para a rotação máxima.

Dúvidas? Entre em contato comigo! :)
