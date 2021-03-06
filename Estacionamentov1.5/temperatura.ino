/************************************************************************
 *  Feito por: Wendell Stanley Araújo Rocha                             *
 * Link para o repositório: https://github.com/WendellRocha/Arduino     *
 * Código desponibilizado para ser utilizado e alterado para se adequar *
 * ao seu código.                                                       *
 * Sistema de estacionamento com controle da rotação do cooler de acordo*
 * com a temperatura ambiente.                                          *
 * Controle da rotação do cooler de acordo com a temperatura, pois o    *
 * arduino, provavelmente, ficará em uma caixa sem circulação de ar.    *
 * Por favor, não retire os créditos.                                   *
 ************************************************************************/

void verificaTemperatura() {
  for (int i = 0; i <= 7; i++) {
    samples[i] = (5.0 * analogRead(lm35) * 100.0) / 1024.0;
    temperatura += samples[i];
    delay(100);
  }

  temperatura /= 8.0;

  if (temperatura > 27.0) {
    analogWrite(cooler, 255);
  }

  else if (temperatura >= 25.0 && temperatura <= 27.0) {
    analogWrite(cooler, 127);
  }

  else {
    analogWrite(cooler, 0);
  }
  
  temperatura = 0;
  delay(50);
}
