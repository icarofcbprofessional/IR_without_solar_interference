  /*
 * IR WITHOUT SOLAR INTERFERENCE FOR OUTDOORS APPLICATIONS - for both presence, distance or whatever your creativity can make yay...
 * Author: Ícaro Fernando
 * Linkedin: https://www.linkedin.com/in/%C3%ADcaro-fernando-46139919b/
 * Github: https://github.com/icarofcbprofessional
 * Date: 14/07/2020
 */

const uint8_t emissor  = 8; 
const uint8_t receptor = 5;

uint16_t a0,
         timer = 0,
         limite= 0;  
              
float x,
      y,
      z;

/*
* this is going to invert the signal received in the analog port of your choice, you can watch this better with the serial plotter
* on your arduino IDE... :)
*/

float inv(uint16_t sig);

void setup()
{
  pinMode(emissor,OUTPUT); // declare the emissor as an output
}

void loop()
{ 
    digitalWrite(emissor,LOW);
    delay(25);
    y = inv(analogRead(receptor));   /*
    delay(50);                        * it's going to check how is the signal WITHOUT the emissor being on...
                                      */
                           
    
    digitalWrite(emissor,HIGH);
    delay(25);
    z = inv(analogRead(receptor));    /*
    delay(50);                        * it's going to check how is the signal WITH the emissor being on...
                                      */
                                      
    x = y/z; /* if the difference is 0, then there is no sun, but if the difference isn't 0 then you can use the variation of 'x' as your analog signal,
             *   that way this code will adapt your arduino with IR to any environment, you can use as a presence or distance sensor...
             */
}
float inv_a(uint16_t sig)
{
//as i said, this is going to invert the signal
  int i;
  i = 1023-sig;

  return i;
}
