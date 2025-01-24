//By valdemir DSW 2025
#include <PID_v1.h>




// configurações de setup
const int potPinX = A0;
const int potPinY = A1;
const int potPinZ = A2;
////////////////////////
/*

Kp (Proporcional):
Controla a reação proporcional ao erro atual. Aumentar o 
Kp faz com que o sistema reaja mais rapidamente, mas se for muito alto, pode gerar oscilações.


Ki (Integral):
Compensa o erro acumulado ao longo do tempo, ou seja, corrige desvios pequenos e persistentes. Um 
Ki alto pode tornar o sistema mais sensível a erros pequenos, mas pode causar instabilidade se for muito grande.


Kd (Derivativo):
Ajuda a suavizar a resposta do sistema, reagindo à taxa de mudança do erro. Isso pode evitar oscilações ou sobrecarga do sistema, mas um 
Kd muito alto pode tornar o sistema lento.

*/
double Kp = 25.0, Ki = 15.0, Kd = 2.0;
////////////////////////////////////////
// ajustes complementares
int debug = 0;
int min_sens = 1;
int max_sens = 1023;





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double inputX, inputY, inputZ;
double outputX, outputY, outputZ;
double setPointX = 0.0; 
double setPointY = 0.0;
double setPointZ = 0.0;
PID pidX(&inputX, &outputX, &setPointX, Kp, Ki, Kd, DIRECT);
PID pidY(&inputY, &outputY, &setPointY, Kp, Ki, Kd, DIRECT);
PID pidZ(&inputZ, &outputZ, &setPointZ, Kp, Ki, Kd, DIRECT);

double mapPotToRange(int potValue) {
  if (potValue > max_sens){
    potValue = max_sens;
  }
  if (potValue < min_sens){
    potValue = min_sens;
  }
  return map(potValue,min_sens,max_sens,-100,100);
}

void setup() {
  Serial.begin(115200);
  pidX.SetMode(AUTOMATIC);
  pidY.SetMode(AUTOMATIC);
  pidZ.SetMode(AUTOMATIC);
  pidX.SetOutputLimits(-100, 100);
  pidY.SetOutputLimits(-100, 100);
  pidZ.SetOutputLimits(-100, 100);
  setup_act();
}

void loop() {
  loop_act();
  if (Serial.available() > 0) {
    String dadosRecebidos = Serial.readStringUntil('\n');
    int primeiroPontoVirgula = dadosRecebidos.indexOf(';');
    int segundoPontoVirgula = dadosRecebidos.indexOf(';', primeiroPontoVirgula + 1);
    String xStr = dadosRecebidos.substring(0, primeiroPontoVirgula);
    String yStr = dadosRecebidos.substring(primeiroPontoVirgula + 1, segundoPontoVirgula);
    String zStr = dadosRecebidos.substring(segundoPontoVirgula + 1);
    setPointX = xStr.toFloat();
    setPointY = yStr.toFloat();
    setPointZ = zStr.toFloat();
  }
  
  int potValueX = analogRead(potPinX);
  int potValueY = analogRead(potPinY);
  int potValueZ = analogRead(potPinZ);
  
  inputX = mapPotToRange(potValueX);
  inputY = mapPotToRange(potValueY);
  inputZ = mapPotToRange(potValueZ);
  
  pidX.Compute();
  pidY.Compute();
  pidZ.Compute();
  go_act(outputX,outputY,outputZ);
  if(debug != 0){
  Serial.print("Input X: ");
  Serial.print(inputX);
  Serial.print(" Output X: ");
  Serial.println(outputX);

  Serial.print("Input Y: ");
  Serial.print(inputY);
  Serial.print(" Output Y: ");
  Serial.println(outputY);
  
  Serial.print("Input Z: ");
  Serial.print(inputZ);
  Serial.print(" Output Z: ");
  Serial.println(outputZ);
  }
  
  
}
