# coding: utf-8 
####################################################
# Comunicação serial entre o python e o arduino    #
# 	2016, Adísio, Laryssa e Wendell                #
# 	UFCG, Iniciação à Computação                   #
# 	Profª Joseana Fechine                          #
####################################################

import serial
import time

while True:
	try:
		arduino = serial.Serial("com4", 9600, timeout = 1)
		print "Arduino conectado"
		break

	except serial.SerialException, e:
		print "Arduino não conectado. tentando novamente em 5 segundos..."
		time.sleep(5)
	
		
print "Status da conexao: %s" % arduino.isOpen()
print "Arduino conectado na porta: %s" % arduino.name
print "Dump da configuracaoo: %s\n\n" % arduino
print "Esperando 5 segundos para o reset do arduino"

time.sleep(5) # delay de 5 segundos para o reset do arduino

print "*********************************************"
print"* Para piscar um led, digite 1               *"
print"* Para deixar um led aceso, digite 2         *"
print"* Para tocar o buzzer, digite 3              *"
print"* Para piscar todos os leds, digite 4        *"
print"* Para piscar dois leds e tocar o buzzer,    *"
print"* digite 5                                   *"
print"* Para encerrar a conexao, digite -1         *"
print"**********************************************"

while True: # laço indefinido para manter a conexão ativa
	codigo = int(raw_input("Entre com o codigo: "))

	if codigo == 1: # se o código for igual a 1:
		arduino.write('1') # escreve '1' na porta serial do arduino
		resposta = arduino.read(64) # lê a resposta do arduino com no máximo 64 bytes e atribui à variável resposta
		print "Arduino disse: %s" % resposta # imprime a resposta do arduino
		print "O led piscara durante 60 segundos"
		

	elif codigo == 2:
		arduino.write('2')
		resposta = arduino.read(64)
		print "Arduino disse: %s" % resposta
		print "O led ficara aceso durante 5 segundos"		

	elif codigo == 3:
		arduino.write('3')
		resposta = arduino.read(64)
		print "Arduino disse: %s" % resposta
		print "O buzzer tocara durante 10 segundos" 
		

	elif codigo == 4:
		arduino.write('4')
		resposta = arduino.read(64)
		print "Arduino disse: %s" % resposta
		print "Os leds piscarao durante 60 segundos"
		

	elif codigo == 5:
		arduino.write('5')
		resposta = arduino.read(64)
		print "Arduino disse: %s" % resposta
		print "Os leds piscarao durante 60 segundos"
		print "O buzzer tocara durante 60 segundos"
		
	
	elif codigo == -1:
		print "Voce encerrou a conexao."
		arduino.close()
		break
