int E1 = 5;     //����M1ʹ�ܶ�
int E2 = 6;     //����M2ʹ�ܶ�
int M1 = 4;    //����M1���ƶ�
int M2 = 7;    //����M1���ƶ�
void stop(void){                 //ֹͣ
       digitalWrite(E1,LOW);   
       digitalWrite(E2,LOW);      
}  
 
void advance(char a,char b){           //ǰ��
       analogWrite (E1,a);             //PWM����
       digitalWrite(M1,HIGH);    
       analogWrite (E2,b);    
       digitalWrite(M2,HIGH);
}  
void back_off (char a,char b) {          //����
       analogWrite (E1,a);
       digitalWrite(M1,LOW);   
       analogWrite (E2,b);    
       digitalWrite(M2,LOW);
}
void turn_L (char a,char b) {           //��ת
       analogWrite (E1,a);
       digitalWrite(M2,LOW);    
       analogWrite (E2,b);    
       digitalWrite(M1,HIGH);
}
void turn_R (char a,char b) {           //��ת
       analogWrite (E1,a);
       digitalWrite(M2,HIGH);    
       analogWrite (E2,b);    
       digitalWrite(M1,LOW);
}

void setup(void) { 
    int i;
    for(i=6;i<=9;i++)
    pinMode(i, OUTPUT);
    Serial.begin(9600);   //������9600
} 

void loop(void) { 
   if(Serial.available()){
    char val = Serial.read(); 
    Serial.write(Serial.read()
); 
     if(val!=-1){
          switch(val){
             case 'w'://ǰ��
                     advance (255,255);   //PWM����
                     break;
             case 's'://����
                     back_off (255,255);
                     break;
             case 'd'://��ת
                     turn_L (255,255);
                     break;       
             case 'a'://��ת
                     turn_R (255,255);
                     break;
             case 'q'://ֹͣ
                     stop();
                     break;          
            }     
          delay(40); 
       }
      else stop();  
   }
   }
