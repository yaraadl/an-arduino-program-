//yara adel hassan mohamed
//19100683
//emb section assignmnet
// a program to display digit number from 0 till 99 using bit read , and applying functons concept .



void setup()
{
  for (int   i = 0; i <= 13; i++)
    pinMode(i, OUTPUT); // all pins from 0 to 13 are considered  OUTPUTs as a high or low value
}
// array having  binary representation  for our  digits on 7 segment    from 0 to 9
const int number[11] = {0b1000000, 0b1111001, 0b0100100, 0b0110000,   0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};


void loop()
{
   for (int tens = 0; tens < 10; tens++)

  {
    snd_digit(tens);
   }
}

void snd_digit(const int tens)
{
  int pin1, a, ones;     
   //pin1  used to deal with pins of   the 1st 7 segemnet through which  the  digit of the first place appear
// from pin 1 till 7  on arduino uno

   for (pin1 = 0, a = 0; pin1 < 7; pin1++, a++)
  {
    digitalWrite(pin1,   bitRead(number[tens], a));//bte2ra eltenth digit 
    //bitRead(x, index) where, x is the number whose bits you are reading,
    //index is the bit to read. 0 corresponds to least significant (right-most) bit,
    //This function returns either 0 or 1 depending on the value of that bit in that number.that wiil be displayed as a high or a low on 7 segment ledsr
  }
  for (ones = 0; ones < 10; ones++)
  {
     fst_digit(ones);
    delay(300); 
    //I have given a delay of 300   milliseconds. You can put your own Time!!
  }
}

void fst_digit(const   int x)
{ int pin2, b;             
//pin2  used to deal with pins of   the 2nd 7 segemnet through which  the  digit of the first place appear
// from pin 7 till 13  on arduino uno
  for (pin2 = 7, b = 0; pin2 <=   13; pin2++, b++)
  {
    digitalWrite(pin2, bitRead(number[x], b));

   }
}
