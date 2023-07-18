//logik für die Eingänge des 7 Segment Displays beim 3 Bit Addierer

/*  L3 = MSB = 2^3, L2 = 2^2, L1 = 2^1, L0 = LSB = 2^0
 *   
 *  a, 7 - (L3 == 0 || L2 == 0 || L1 == 0 || L0 == 1) && (L3 == 0 || L2 == 1 || L1 == 0 || L0 == 0)
 *  b, 6 - (L3 == 0 || L2 == 1 || L1 == 0 || L0 == 1) && (L3 == 0 || L2 == 1 || L1 == 1 || L0 == 0) && (L3 == 1 || L2 == 1 || L1 == 0 || L0 == 0) && (L3 == 1 || L2 == 1 || L1 == 1 || L0 == 1)
 *  c, 4 - (L3 == 0 || L2 == 0 || L1 == 1 || L0 == 0) && (L3 == 1 || L2 == 1 || L1 == 0 || L0 == 0) && (L3 == 1 || L2 == 1 || L1 == 1 || L0 == 0) && (L3 == 1 || L2 == 1 || L1 == 1 || L0 == 1)
 *  d, 2 - (L3 == 0 || L2 == 0 || L1 == 0 || L0 == 1) && (L3 == 0 || L2 == 1 || L1 == 0 || L0 == 0) && (L3 == 0 || L2 == 1 || L1 == 1 || L0 == 1) && (L3 == 1 || L2 == 0 || L1 == 1 || L0 == 0) && (L3 == 1 || L2 == 1 || L1 == 1 || L0 == 1)
 *  e, 1 - (L3 == 0 || L2 == 0 || L1 == 0 || L0 == 1) && (L3 == 0 || L2 == 0 || L1 == 1 || L0 == 1) && (L3 == 0 || L2 == 1 || L1 == 0 || L0 == 0) && (L3 == 0 || L2 == 1 || L1 == 0 || L0 == 1) && (L3 == 0 || L2 == 1 || L1 == 1 || L0 == 1) && (L3 == 1 || L2 == 0 || L1 == 0 || L0 == 1)
 *  f, 9 - (L3 == 0 || L2 == 0 || L1 == 0 || L0 == 1) && (L3 == 0 || L2 == 0 || L1 == 1 || L0 == 0) && (L3 == 0 || L2 == 0 || L1 == 1 || L0 == 1) && (L3 == 0 || L2 == 1 || L1 == 1 || L0 == 1)
 *  g, 10 - (L3 == 0 || L2 == 0 || L1 == 0 || L0 == 0) && (L3 == 0 || L2 == 0 || L1 == 0 || L0 == 1) && (L3 == 0 || L2 == 1 || L1 == 1 || L0 == 1) && (L3 == 1 || L2 == 1 || L1 == 0 || L0 == 0) && (L3 == 1 || L2 == 1 || L1 == 0 || L0 == 1)
 *  dp, 5 - ungenutzt
 */
 
//Zum Einlesen der Summe (die 4 Bits)
const int L3 = 2;
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

void setup() {
 
  pinMode(L3, INPUT);
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

void withBooleanLogic()
{
  
}

int convertBinaryNumber(int l3, int l2, int l1, int l0)
{
  int result = -(pow(2, 3) * l3) + pow(2, 2) * l2 + pow(2, 1) * l1 + pow(2, 0) * l0; 
  Serial.println(-(pow(2, 3) * l3));
  return result; 
}

void setDisplayPositive(int number);

void setDisplayNegative(int number);

void loop() 
{
  int valueL3 = digitalRead(L3); 
  int valueL2 = digitalRead(L2); 
  int valueL1 = digitalRead(L1); 
  int valueL0 = digitalRead(L0); 
   
  int decimal = convertBinaryNumber(valueL3, valueL2, valueL1, valueL0);
  //setDisplayPositive(decimal);
  
  setDisplayNegative(decimal);
 
  delay(2000);
  Serial.println(decimal); 

}


void setDisplayPositive(int number)
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
    case 7:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(dp, LOW);
      break;
    case 8: 
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    case 9: 
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    case 10: 
      //Hex A
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    case 11: 
      //Hex B
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    case 12: 
      //Hex C
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(dp, LOW);
      break;
    case 13: 
      //Hex D
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(dp, LOW);
      break;
    case 14: 
      //Hex E
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    case 15: 
      //Hex F
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, LOW);
      break;
    default: 
      break; 
  }
  
}


void setDisplayNegative(int number)
{
  switch (number)
  {
    case -8: 
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, HIGH);
      break;
    case -7: 
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(dp, HIGH);
      break;
    case -6: 
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, HIGH);
      break;
    case -5: 
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, HIGH);
      break;
    case -4: 
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(dp, HIGH);
      break;
    case -3: 
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      digitalWrite(dp, HIGH);
      break;
    case -2: 
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      digitalWrite(dp, HIGH);
      break;
    case -1: 
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(dp, HIGH);
      break;
    




    
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
    case 7:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(dp, LOW);
      break;
    default: 
      break; 
  }
}
