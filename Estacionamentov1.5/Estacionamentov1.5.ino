/************************************************************************
 *  Sistema de data e hora retirado do site Labotarório de Garagem      *
 * (http://arduino.labdegaragem.com/Guia_preview/SMK_11_dataehora.html) *
 * Sistema adaptado para se adequar ao uso.                             *
 * Feito por: Wendell Stanley Araújo Rocha                              *
 * Link para o repositório: https://github.com/WendellRocha/Arduino     *
 * Código desponibilizado para ser utilizado e alterado para se adequar *
 * ao seu código.                                                       *
 * Sistema de estacionamento com controle da rotação do cooler de acordo*
 * com a temperatura ambiente.                                          *
 * Controle da rotação do cooler de acordo com a temperatura, pois o    *
 * arduino, provavelmente, ficará em uma caixa sem circulação de ar.    *
 * Por favor, não retire os créditos.                                   *
 ************************************************************************/

// sensor de teperatura, cooler, botão, estado do botão, temperatura, e array de temperaturas

const int botao = 12;
const int lm35 = 0;
const int cooler = 11;
int estadodobotao = 0;
int temperatura = 0;
int samples[8];

// -----------------

// data/hora/dias da semana/meses
int segundo, minuto, hora, dia, mes, ano, DiaDaSemana;
unsigned long UtlTime;
char* DiasDaSemana[] = {"", "Domingo", "Segunda-Feira", "Terça-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sabado"};
char* Meses[] = {"", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

//----------------
void setup() {

  pinMode(botao, INPUT);


  UtlTime = 0;
  minuto = -1;
  hora = 0;
  dia = 0;
  mes = 0;
  ano = 0;


  // iniciando o arduino
  Serial.begin(9600);
  Serial.print("Inicializando...\n");
  delay(1000);
  Serial.print("Observacoes:\n");
  Serial.print("Digite as horas no formato hh.\n"
               "Digite o dia no formato dd.\n"
               "Digite o mes no formato m.\n"
               "Digite o ano no formato aaaa.\n");
   delay(1000);


  // configura os minutos
  Serial.print("Digite os minutos: \n");
  while (minuto == -1) {
    if (Serial.available() > 0) {
      minuto = Serial.parseInt();
    }
  }

  Serial.print("Gravando os minutos...\n");
  Serial.print(minuto);
  delay(1000);
  Serial.print("\nMinutos gravados.\n");
  delay(1000);

  // configura a hora
  Serial.print("Digite a hora: \n");
  while (hora == 0) {
    if (Serial.available() > 0) {
      hora = Serial.parseInt();
    }
  }

  Serial.print("Gravando a hora...\n");
  Serial.print(hora);
  delay(1000);
  Serial.print("\nHora gravada.\n");
  delay(1000);

  //configura o dia
  Serial.print("Digite o dia: \n");
  while (dia == 0) {
    if (Serial.available() > 0) {
      dia = Serial.parseInt();
    }
  }

   Serial.print("Gravando o dia...\n");
   Serial.print(dia);
   delay(1000);
   Serial.print("\nDia gravado.\n");
   delay(1000);

  //configura o dia da semana
  Serial.print("Digite o dia da semana: \n");
  while (DiaDaSemana == 0) {
    if (Serial.available() > 0) {
      DiaDaSemana = Serial.parseInt();
    }
  }

   Serial.print("Gravando o dia da sema...\n");
   Serial.print(DiaDaSemana);
   delay(1000);
   Serial.print("\nDia da semana gravado.\n");
   delay(1000);

   // configura o mês
   Serial.print("Digite o mes: \n");
   while (mes == 0) {
    if (Serial.available() > 0) {
      mes = Serial.parseInt();
    }
   }

   Serial.print("Gravando o mes...\n");
   Serial.print(mes);
   delay(1000);
   Serial.print("\nMes gravado.\n");
   delay(1000);

   // configura o ano
   Serial.print("Digite o ano: \n");
   while (ano == 0) {
    if (Serial.available() > 0) {
      ano = Serial.parseInt();
    }
   }

   Serial.print("Gravando o ano...\n");
   Serial.print(ano);
   delay(1000);
   Serial.print("\nAno gravado.\n\n");
   delay(1000);

}

void loop() {
  if(millis() - UtlTime < 0) {
    UtlTime = millis();
  }

  else {
    segundo = int((millis() - UtlTime) / 1000);
  }

  if(segundo > 59) {
    segundo = 0;
    minuto++;
    UtlTime = millis();
  }

  if(minuto > 59) {
    hora++;
    minuto = 0;
  }

  if(hora > 23) {
    dia++;
    DiaDaSemana++;
    hora = 0;
  }

  if (mes > 12) {
    mes--;
    mes = 1;
  }

  if(mes == 1||mes == 3||mes == 5||mes == 7||mes == 8||mes == 10||mes == 12) {
    if(dia > 31) {
      dia = 1;
      mes++;
      if(mes > 12){
        ano++;
        mes = 1;
      }
    }
  }

  else if(mes == 2) {
    if(ano % 400 == 0) {
      if(dia > 29) {
        dia = 1;
        mes++;
      }
    }
  }

  else if((ano % 4 == 0) && (ano % 100 != 0)) {
    if(dia>29) {
      dia = 1;
      mes++;
    }
  }

  else if(dia > 28){
      dia = 1;
      mes++;
    }

  else if(dia > 30) {
      dia = 1;
      mes++;
    }

    verificaTemperatura();

  estadodobotao = digitalRead(botao);
  if (estadodobotao == HIGH) {
    Serial.write("UNIVERSIDADE FEDERAL DE CAMPINA GRANDE\n");
    Serial.write("Ticket de estacionamento\n\n");

    if (hora < 23 && hora <= 12) {
      Serial.write("Bom dia, seja bem-vindo\n\n");
    }

    else if (hora > 12 && hora < 18) {
      Serial.write("Boa tarde, seja bem-vindo\n\n");
    }

    else if (hora >= 18 && hora <= 23) {
      Serial.write("Boa noite, seja bem-vindo\n\n");
    }



    Serial.write(DiasDaSemana[DiaDaSemana]);
    Serial.write(", ");
    Serial.write(dia);
    Serial.write(" de ");
    Serial.write(Meses[mes]);
    Serial.write(" de ");
    Serial.write(ano);
    Serial.write("\n");
    Serial.write("Horario de entrada: ");
    Serial.write(hora);
    Serial.write(":");
    Serial.write(minuto);
    Serial.write(":");
    Serial.write(segundo);
    Serial.write(" \n\n");
    Serial.write("Para liberar a sua saida,\n");
    Serial.write("passe no caixa e troque o ticket pelo cartao.\n\n");
  }
}
