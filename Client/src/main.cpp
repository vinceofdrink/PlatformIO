#include <Arduino.h>

/**
 * Exemple de code pour la bibliothèque Mirf – Client Ping Pong
 */
#include <SPI.h>      // Pour la communication via le port SPI
#include <Mirf.h>     // Pour la gestion de la communication
#include <nRF24L01.h> // Pour les définitions des registres du nRF24L01
#include <MirfHardwareSpiDriver.h> // Pour la communication SPI

void setup() {

 pinMode(4, INPUT_PULLUP);
  Mirf.cePin = 9; // Broche CE sur D9
  Mirf.csnPin = 10; // Broche CSN sur D10
  Mirf.spi = &MirfHardwareSpi; // On veut utiliser le port SPI hardware
  Mirf.init(); // Initialise la bibliothèque
  // Mirf.configRegister(RF_SETUP, 0x26);  //Lower transmission

  Mirf.channel = 124; // Choix du canal de communication (128 canaux disponibles, de 0 à 127)
  Mirf.payload = sizeof(long); // Taille d'un message (maximum 32 octets)
  Mirf.config(); // Sauvegarde la configuration dans le module radio
  Mirf.configRegister(RF_SETUP, 0x2F); //0x07

  Mirf.setTADDR((byte *) "d@@r_"); // Adresse de transmission
  Mirf.setRADDR((byte *) "nrf01"); // Adresse de réception
  
}

void loop() {
  unsigned long time_message = millis(); // On garde le temps actuel retourné par millis()
  if(digitalRead(4) == LOW ) {
    Mirf.send((byte *) &time_message); // On envoie le temps actuel en utilisant une astuce pour transformer le long en octets
    while(Mirf.isSending()); // On attend la fin de l'envoi
  delay(600);
  }
}
