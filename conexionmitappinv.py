#Joel Jordán Freire
import os
import socket

from http.server import BaseHTTPRequestHandler, HTTPServer
import RPi.GPIO as GPIO
from time import*

sotano = 18
jardin = 27
garaje = 22
atico = 23

myip=socket.gethostbyname(socket.gethostname())
print(myip) 

def peripheral_setup():
 GPIO.setmode(GPIO.BCM)
 GPIO.setup(sotano, GPIO.OUT)
 GPIO.setup(jardin, GPIO.OUT)
 GPIO.setup(garaje, GPIO.OUT)
 GPIO.setup(atico, GPIO.OUT)
 
def servidor():
 Request = None

 class RequestHandler_httpd(BaseHTTPRequestHandler):
   def do_GET(self):
    global Request

    messagetosend = bytes('Solicitando',"utf")
    self.send_response(200)
    self.send_header('Content-Type', 'text/plain')
    self.send_header('Content-Length', len(messagetosend))
    self.end_headers()
    self.wfile.write(messagetosend)
    Request = self.requestline
    Request = Request[5 : int(len(Request)-9)]
    #print(Request)
    if Request == 'on1':
      print('Luz del jardin encendida')
      GPIO.output(jardin,True)
  
    if Request == 'off1':
      print('Luz del garaje apagada')
      GPIO.output(jardin,False)
 
    if Request == 'on2':
      print('Luz del garaje encendida')
      GPIO.output(garaje,True)
      
    if Request == 'off2':
      print('Luz del garaje apagada')
      GPIO.output(garaje,False)

    if Request == 'on3':
      print('Luz del sotano encendida')
      GPIO.output(sotano,True)
  
    if Request == 'off3':
      print('Luz del sotano apagada')
      GPIO.output(sotano,False)
      
    if Request == 'on4':
      print('Luz del atico encendida')
      GPIO.output(atico,True)
  
    if Request == 'off4':
      print('Luz del atico apagada')
      GPIO.output(atico,False)
 

 server_address_httpd = (myip,8001)
 httpd = HTTPServer(server_address_httpd, RequestHandler_httpd)
 print('conectando a servidor')
 print(httpd.fileno())
 httpd.serve_forever()
 
def main () :

# Setup
 peripheral_setup()

# Infinite loop
 try:
  while 1 :  
   servidor()
 except(KeyboardInterrupt,SystemExit):
  print ("BYE")
  GPIO.cleanup()
# Command line execution
if __name__ == '__main__' :
   main()