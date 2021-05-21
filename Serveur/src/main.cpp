#include <Arduino.h>

/**
 * Exemple de code pour la bibliothèque Mirf – Serveur Ping Pong
 */
#include <SPI.h>      // Pour la communication via le port SPI
#include <Mirf.h>     // Pour la gestion de la communication
#include <nRF24L01.h> // Pour les définitions des registres du nRF24L01
#include <MirfHardwareSpiDriver.h> // Pour la communication SPI

void setup() {

  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  Mirf.cePin = 9; // Broche CE sur D9
  Mirf.csnPin = 10; // Broche CSN sur D10
  Mirf.spi = &MirfHardwareSpi; // On veut utiliser le port SPI hardware
  Mirf.init(); // Initialise la bibliothèque
// Mirf.configRegister(RF_SETUP, 0x26);  //Lower transmission
  Mirf.channel = 124; // Choix du canal de communication (128 canaux disponibles, de 0 à 127)
  Mirf.payload = sizeof(long); // Taille d'un message (maximum 32 octets)
  Mirf.config(); // Sauvegarde la configuration dans le module radio
  Mirf.configRegister(RF_SETUP, 0x2F); //0x07
  Mirf.setTADDR((byte *) "nrf01"); // Adresse de transmission
  Mirf.setRADDR((byte *) "d@@r_"); // Adresse de réception

}
unsigned long counter=0;
void loop() {
  byte message[sizeof(long)];

  if(Mirf.dataReady()){

    tone(6, 4000, 100);
    digitalWrite(4, HIGH);
    Mirf.getData(message); // Réception du paquet
    //Mirf.send(message); // Et on le renvoie tel quel
    delay(600);
    digitalWrite(4, LOW);
    tone(6, 3000, 2500);
    delay(1500);
  }
}
