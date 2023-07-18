 //Zum Einlesen der Summe (die 3 Bits)
const int L2 = 3;
const int L1 = 4;
const int L0 = 5;

//Für die Ausgabe bzw EIngabe am 7 Segment Display
const int a = 7;
const int b = 8;
const int c = 9;
const int d = 10;
const int e = 11;
const int f = 12;
const int g = 13;
const int dp = 6;

void setup() 
{
 
  pinMode(L2, INPUT);
  pinMode(L1, INPUT);
  pinMode(L0, INPUT);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  
  Serial.begin(9600);
}

int convertBinaryNumber(int l2, int l1, int l0)
{
  int result = pow(2, 2) * l2 + pow(2, 1) * l1 + pow(2, 0) * l0; 
  return result; 
}

void setDisplayPositive(int number);

void loop() 
{
  int valueL2 = digitalRead(L2); 
  int valueL1 = digitalRead(L1); 
  int valueL0 = digitalRead(L0); 
   
  int decimal = convertBinaryNumber(valueL2, valueL1, valueL0);
  setDisplay(decimal);
  
  Serial.println(decimal); 
}


void setDisplay(int number)
{
  switch (number)
  {
    case 0:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(dp, LOW);
      break;
    case 1:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(dp, LOW);
      break; 
    case 2: 
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    case 3: 
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    case 4: 
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    case 5: 
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    case 6: 
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    default: 
      break; 
  }
  
}
