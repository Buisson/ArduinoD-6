void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


  for(int i=8;i<=13;i++)
    pinMode(i, OUTPUT);
  pinMode(2, INPUT);
  attachInterrupt(0, ISR_Button, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  offAll();//eteind toutes les LED toutes les 5 secondes (fais mal aux yeux)
}

void offAll(){
  for(int k=8;k<=13;k++)
    digitalWrite(k, LOW);  
}

void launchDice(){
  offAll();
  int tmp = random(1,7);
  //Serial.println(tmp);
  for(int j=8;j<(8+tmp);j++)
    digitalWrite(j, HIGH);
}

/*Interuption button*/
void ISR_Button(){
  launchDice();
}

