/* 
  Test d'un servo moteur à retour d'info, ici Batan S1123 avec module ESP
 
 Le montage, avec un module ESP :
 
 * Un servo-moteur sur la broche D1 du module ESP, et 
 * La broche du potentiomète interne au servo-moteur sur A0 du module ESP.
 
 créé le 30 novembre 2017
 par Mathieu Farges

  Ce code est en CC0 1.0 Universal
 */

// Introduit le servomoteur
#include <Servo.h> 
Servo myservo;  // créer un objet appelé myservo à partir du moule Servo

// Déclaration des variables :
int pos = 0;    // variable pour stocker la position courante du servo
int potentio;

// le code dans cette fonction est exécuté une fois au début
void setup() 
{ 
  // Initialise la communication avec l'ordinateur
  Serial.begin(9600); // attention à bien regler la vitesse d'affichage du moniteur à 9600 pour voir qqchose
  
  myservo.attach(D1);  // attacher notre objet myservo au servomoteur branché sur la broche D1
} 

// le code dans cette fonction est exécuté en boucle
void loop() 
{ 

   // fonctionnement servo  

for(pos = 0; pos < 90; pos += 1)  // aller de 0° à 90°
  {                                  // une étape à la fois
    myservo.write(pos);             // aller à la position stocké dans 'pos'
    int potentio = map(analogRead(A0), 0, 1023, 0, 179);
    Serial.print(pos);            // afficher
    Serial.print(" ; ");            // virgule
    Serial.println(potentio);         // valeur potentio
    delay(100);                       // attendre 15ms que le servomoteur se rende à 'pos'
  } 
   // fin sequence 1

  Serial.print("\t pos = ");      
  Serial.println(pos);

delay(2000); // attendre 2 secondes

for(pos = 90; pos < 180; pos += 1)  // aller de 90° à 180°
  {                                  // une étape à la fois
    myservo.write(pos);             // aller à la position stocké dans 'pos'
    potentio = map(analogRead(A0), 0, 1023, 0, 179);
    Serial.print(pos);            // afficher
    Serial.print(" ; ");            // virgule
    Serial.println(potentio);         // valeur potentio
    delay(100);                       // attendre 15ms que le servomoteur se rende à 'pos'
  } 
   // fin sequence 2

  Serial.print("\t pos = ");      
  Serial.println(pos);

delay(5000); // attendre 5 secondes

for(pos = 180; pos > 90; pos -= 1)  // aller de 180° à 90°
  {                                  // une étape à la fois
    myservo.write(pos);             // aller à la position stocké dans 'pos'
    int potentio = map(analogRead(A0), 0, 1023, 0, 179);
    Serial.print(pos);            // afficher
    Serial.print(" ; ");            // virgule
    Serial.println(potentio);         // valeur potentio
    delay(100);                       // attendre 15ms que le servomoteur se rende à 'pos'
  } 
   // fin sequence 3

  Serial.print("\t pos = ");      
  Serial.println(pos);

delay(2000); // attendre 2 secondes

// fonctionnement servo
  for(pos = 90; pos>=1; pos-=1)     /// aller de 90° à 0°
  {                                
    myservo.write(pos);             // aller à la position stocké dans 'pos'
    int potentio = map(analogRead(A0), 0, 1023, 0, 179);
    Serial.print(pos);            // afficher
    Serial.print(" ; ");            // virgule
    Serial.println(potentio);         // valeur potentio
    delay(100);                       // attendre 15ms que le servomoteur se rende à 'pos'
  } 
// fin sequence 4

  Serial.print("\t pos = ");      
  Serial.println(pos);

delay(5000); // attendre 5 secondes

}// fin void loop

