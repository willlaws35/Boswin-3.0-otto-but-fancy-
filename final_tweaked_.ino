/*N.E.A Boswin 3.0 project
 * 
 * servo notation diagram.
 * 
 * for pin locators use servo.attach functions.
 * 
 *        L          |         R
 *     --------------|-------------          

              --------------- 
      __     |     O   O     |     __
      \ \____|---------------|____/ /
       \-----|               |-----/  =s5(left arm)  /  s6(right arm)
              --------------- 
                 ||     ||            =s3(left leg)  /  s4(right leg)
                 ||     ||
               -----   ------  
              |-----   ------|        =s1(left foot) / s2(right foot)
                
 focus based around the devices receptivness of urtrasonic frequencies are allocated within the main loop.
*/

//libraries
#include <Servo.h>

//initialisers and variables

#define off_button 8

//assorted servo notation from diagram
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;

int pressed;// check state of button

int loop_counting = 0;

int pos = 90;// constant callibration value

const int trig = 10;
const int echo = 9;
long duration;
int distance;

int s1_set;
int s2_set;
int s3_set;
int s4_set;
int s5_set;
int s6_set;


//servo setting function, sets all servos using a single function.
void servo_collect_set(int s1_set, int s2_set, int s3_set, int s4_set, int s5_set, int s6_set){
    s1.write(s1_set);
    s2.write(s2_set);
    s3.write(s3_set);
    s4.write(s4_set);
    s5.write(s5_set);
    s6.write(s6_set);
    }

void setup() {

  //servo connections established
  //notation in brackets refer to physical connection on arduino nano.

  Serial.write("servo initialising");
  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
  s5.attach(6);
  s6.attach(7);

//initialise fail safe button.
pinMode(off_button, INPUT);
digitalWrite(off_button, HIGH); // connect internal pull-up resistor.

//create ultrasonic sensor connections to arduino.
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);

//start serial monitor for feedback results.
Serial.begin(9600); 

}

void loop() {
  
Serial.write("loop run count: ",loop_counting);  
loop_counting = (loop_counting+1);

servo_collect_set(pos, pos, pos, pos, pos, pos);

//set arm values to stationary position.
delay(500);
s5.write(pos-90);
s6.write(pos+90);
delay(200);

//sets ultrasonic sensor to start state.
digitalWrite(trig, LOW);
delay (2);
digitalWrite(trig, HIGH);
delay (10);
digitalWrite(trig, LOW);

duration = pulseIn(echo, HIGH);
distance= duration*0.0343/2;//distance using speed of sound constant, cna be varied ffor accuracy.

if (distance != 0){
  
   Serial.print(distance);
   Serial.print("cm ,");
   
    if (distance<25){
      
    servo_collect_set(pos, pos, pos, pos, pos, pos);
    
    delay(500);  
    s5.write(0);
    s6.write(180);
    delay(500);
    
    }
    
    else if (distance>25){
      
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     servo_collect_set(pos-85, pos, pos, pos, pos-90, 180);
     delay(50);
     servo_collect_set(pos-85, pos-40, pos, pos, pos-90, 180);
     delay(625);
     servo_collect_set(pos-30, pos-40, pos, pos, pos-90, 180);
     delay(1250);
     servo_collect_set(pos-30, pos-40, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos, pos, pos+30, pos+30, pos-90, 180);
     delay(1000);
     
     // step 1
     
     servo_collect_set(pos, pos+85, pos+30, pos+30, pos-90, 180);
     delay(50);
     servo_collect_set(pos+40, pos+85, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(1250);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     delay(1000);
     
     //step 2
     
     servo_collect_set(pos, pos+85, pos, pos, pos-90, 180);
     delay(50);
     servo_collect_set(pos+40, pos+85, pos, pos, pos, pos);
     delay(625);
     servo_collect_set(pos+40, pos+30, pos, pos, pos, pos);
     delay(1250);
     servo_collect_set(pos+40, pos+30, pos-10, pos-10, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos-20, pos-20, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos-30, pos-30, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos-30, pos-30, pos, pos);
     delay(625);
     servo_collect_set(pos, pos, pos-30, pos-30, pos-90, 180);
     delay(1000);
     
     //step 3
     
     servo_collect_set(pos-85, pos, pos-30, pos-30, pos-90, 180);
     delay(50);
     servo_collect_set(pos-85, pos-40, pos-30, pos-30, pos, pos);
     delay(625);
     servo_collect_set(pos-30, pos-40, pos-30, pos-30, pos, pos);
     delay(1250);
     servo_collect_set(pos-30, pos-40, pos-20, pos-20, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos-10, pos-10, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos, pos, pos, pos);
     delay(50);
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     delay(1000);\
     
     //step 4
     
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     servo_collect_set(pos-85, pos, pos, pos, pos-90, 180);
     delay(50);
     servo_collect_set(pos-85, pos-40, pos, pos, pos-90, 180);
     delay(625);
     servo_collect_set(pos-30, pos-40, pos, pos, pos-90, 180);
     delay(1250);
     servo_collect_set(pos-30, pos-40, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos, pos, pos+30, pos+30, pos-90, 180);
     delay(1000);
     
     //step 5
      
     servo_collect_set(pos, pos+85, pos+30, pos+30, pos-90, 180);
     delay(50);
     servo_collect_set(pos+40, pos+85, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(1250);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     delay(1000);

     //step 6
     
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     servo_collect_set(pos-85, pos, pos, pos, pos-90, 180);
     delay(50);
     servo_collect_set(pos-85, pos-40, pos, pos, pos-90, 180);
     delay(625);
     servo_collect_set(pos-30, pos-40, pos, pos, pos-90, 180);
     delay(1250);
     servo_collect_set(pos-30, pos-40, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos, pos, pos+30, pos+30, pos-90, 180);
     delay(1000);

     //step 7
     
     servo_collect_set(pos, pos+85, pos+30, pos+30, pos-90, 180);
     delay(50);
     servo_collect_set(pos+40, pos+85, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(1250);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     delay(1000);

    }
    
}

delay(500);
  
  digitalWrite(trig, LOW);
  delay (50);
  digitalWrite(trig, HIGH);
  delay (50);
  digitalWrite(trig, LOW);

//buuton check

 pressed = digitalRead(off_button);
  if (pressed==LOW)
  {
    
    Serial.write("end error 1");
    delay(2000);
    exit(0);

  }
  if (distance<25)// if area is not clear rotate right approximately 90 degrees.
   {
         servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     servo_collect_set(pos-85, pos, pos, pos, pos-90, 180);
     delay(50);
     servo_collect_set(pos-85, pos-40, pos, pos, pos-90, 180);
     delay(625);
     servo_collect_set(pos-30, pos-40, pos, pos, pos-90, 180);
     delay(1250);
     servo_collect_set(pos-30, pos-40, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos, pos, pos+30, pos+30, pos-90, 180);
     delay(1000);

     //step 1
     
     servo_collect_set(pos, pos+85, pos+30, pos+30, pos-90, 180);
     delay(50);
     servo_collect_set(pos+40, pos+85, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(1250);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     delay(1000);

     //step 2
     
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     servo_collect_set(pos-85, pos, pos, pos, pos-90, 180);
     delay(50);
     servo_collect_set(pos-85, pos-40, pos, pos, pos-90, 180);
     delay(625);
     servo_collect_set(pos-30, pos-40, pos, pos, pos-90, 180);
     delay(1250);
     servo_collect_set(pos-30, pos-40, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos, pos, pos+30, pos+30, pos-90, 180);
     delay(1000);

     //step 3
     
     servo_collect_set(pos, pos+85, pos+30, pos+30, pos-90, 180);
     delay(50);
     servo_collect_set(pos+40, pos+85, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(1250);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     delay(1000);

     if (distance<25)// if distance 90 degrees to right not clear turn 90 degrees further.
     {
      
     //step 1
     
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     servo_collect_set(pos-85, pos, pos, pos, pos-90, 180);
     delay(50);
     servo_collect_set(pos-85, pos-40, pos, pos, pos-90, 180);
     delay(625);
     servo_collect_set(pos-30, pos-40, pos, pos, pos-90, 180);
     delay(1250);
     servo_collect_set(pos-30, pos-40, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos, pos, pos+30, pos+30, pos-90, 180);
     delay(1000);

     //step 2
     
     servo_collect_set(pos, pos+85, pos+30, pos+30, pos-90, 180);
     delay(50);
     servo_collect_set(pos+40, pos+85, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(1250);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     delay(1000);

     //step 3
     
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     servo_collect_set(pos-85, pos, pos, pos, pos-90, 180);
     delay(50);
     servo_collect_set(pos-85, pos-40, pos, pos, pos-90, 180);
     delay(625);
     servo_collect_set(pos-30, pos-40, pos, pos, pos-90, 180);
     delay(1250);
     servo_collect_set(pos-30, pos-40, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos, pos, pos+30, pos+30, pos-90, 180);
     delay(1000);

     //step 4
     
     servo_collect_set(pos, pos+85, pos+30, pos+30, pos-90, 180);
     delay(50);
     servo_collect_set(pos+40, pos+85, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(1250);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     delay(1000);

     if (distance<25)//if distance 180 degrees from original direction turn 90 degrees.
     {

     //step 1
      
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     servo_collect_set(pos-85, pos, pos, pos, pos-90, 180);
     delay(50);
     servo_collect_set(pos-85, pos-40, pos, pos, pos-90, 180);
     delay(625);
     servo_collect_set(pos-30, pos-40, pos, pos, pos-90, 180);
     delay(1250);
     servo_collect_set(pos-30, pos-40, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos, pos, pos+30, pos+30, pos-90, 180);
     delay(1000);

     //step 2
     
     servo_collect_set(pos, pos+85, pos+30, pos+30, pos-90, 180);
     delay(50);
     servo_collect_set(pos+40, pos+85, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(1250);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     delay(1000);

     //step 3
     
     servo_collect_set(pos, pos, pos, pos, pos-90, 180);
     servo_collect_set(pos-85, pos, pos, pos, pos-90, 180);
     delay(50);
     servo_collect_set(pos-85, pos-40, pos, pos, pos-90, 180);
     delay(625);
     servo_collect_set(pos-30, pos-40, pos, pos, pos-90, 180);
     delay(1250);
     servo_collect_set(pos-30, pos-40, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos-30, pos-40, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos, pos, pos+30, pos+30, pos-90, 180);
     delay(1000);

     //step 4
     
     servo_collect_set(pos, pos+85, pos+30, pos+30, pos-90, 180);
     delay(50);
     servo_collect_set(pos+40, pos+85, pos+30, pos+30, pos, pos);
     delay(625);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(1250);
     servo_collect_set(pos+40, pos+30, pos+30, pos+30, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+20, pos+20, pos, pos);
     delay(50);
     servo_collect_set(pos+40, pos+30, pos+10, pos+10, pos, pos);
     delay(50);
     servo_collect_set(pos, pos, pos, pos, pos-90, pos+90);
     delay(1000);

     if (distance<25)// if distance is completely obstructed end procedure.
     {
      servo_collect_set(pos, pos, pos, pos, pos-90, pos+90);
      delay(2000);
      servo_collect_set(pos, pos, pos, pos, pos, pos);
      delay(2000);
      servo_collect_set(pos, pos, pos, pos, pos+90, pos-90);
      delay(2000);
      Serial.write("end error 2");
      delay(2000);
      exit(0);
     }
     }     
     }
   }
   }       
