int vet[10][4] = {
    {0,0,0,0},
    {0,0,0,1},
    {0,0,1,0},
    {0,0,1,1},
    {0,1,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {0,1,1,1},
    {1,0,0,0},
    {1,0,0,1}
};

int buttonState, buttonState2;             // O valor atual da chave no circuito
int lastButtonState = HIGH;   // O valor prévio da chave no circuito
int lastButtonState2 = HIGH;
long lastDebounceTime = 0;   // Variável utilizada na temporização
long lastDebounceTime2 = 0;
long debounceDelay = 100;     // tempo para estabilizar e minimizar o efeito bouncing

int pin[2][4] = {
  {0,3,4,1},
  {6,8,9,5}
};

const byte decimalPin = 10;
const byte numeralPin = 11;
int numeral = -1;
int decimal = -1;

void decimal_up() 
{
  decimal++;
  if (decimal > 9) 
  {
    decimal = 0;
  }
  mostrar(0, decimal);
}

void numeral_up() 
{
  numeral++;
  if (numeral > 9) {
    numeral = 0;
  }
  mostrar(1, numeral);
}

void mostrar(int iDisplay, int iDigito) 
{
  digitalWrite(pin[iDisplay][0], vet[iDigito][0]);
  digitalWrite(pin[iDisplay][1], vet[iDigito][1]);
  digitalWrite(pin[iDisplay][2], vet[iDigito][2]);
  digitalWrite(pin[iDisplay][3], vet[iDigito][3]);
}

void setup() {
  for (byte x = 0; x < sizeof(pin) - 1; x++) {
    for (byte y = 0; y < sizeof(pin) - 1; y++) {
      pinMode(pin[x][y], OUTPUT);
    }
  }
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(decimalPin, INPUT);
  pinMode(numeralPin, INPUT);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void loop() {
  // faz a leitura da chave e armazena na variável
  int reading = digitalRead(10);
 
  // Verifica se houve alterações com o valor prévio da chave
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // Reset na variável de temporização
  }
 
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Verifica se o estado atual da chave mudou
    if (reading != buttonState) {
      buttonState = reading;
 
      // Troca o estado para ser atribuido para o valor do led
      // Só altera se o novo estado for HIGH
      if (buttonState == HIGH) {
        decimal_up();
      }
    }
  } 
  // Atualiza a variável com o valor lido na chave
  lastButtonState = reading;
  
  // faz a leitura da chave e armazena na variável
  int reading2 = digitalRead(11);
 
  // Verifica se houve alterações com o valor prévio da chave
  if (reading2 != lastButtonState2) {
    lastDebounceTime2 = millis();  // Reset na variável de temporização
  }
 
  if ((millis() - lastDebounceTime2) > debounceDelay) {
    // Verifica se o estado atual da chave mudou
    if (reading2 != buttonState2) {
      buttonState2 = reading2;
 
      // Troca o estado para ser atribuido para o valor do led
      // Só altera se o novo estado for HIGH
      if (buttonState2 == HIGH) {
        numeral_up();
      }
    }
  } 
  // Atualiza a variável com o valor lido na chave
  lastButtonState2 = reading2;
}
