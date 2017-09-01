const int sensor1Pin = A0;
const int sensor2Pin = A1;

int sensor1Val = 0;
int sensor2Val = 0;

void setup()
{
	Serial.begin(9600);
	Serial.println("Serial Communication Initialized");
}

void loop()
{
	sensor1Val = analogRead(sensor1Pin);
	sensor2Val = analogRead(sensor2Pin);

	Serial.print("S1 = ");
	Serial.print(sensor1Val);
	Serial.print(" - S2 = ");
	Serial.println(sensor2Val);

	delay(1000);
}
