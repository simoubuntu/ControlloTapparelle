const int sensor1Pin = A0;
const int sensor2Pin = A1;
const int outUpPin = 6;
const int outDownPin = 7;

int sensor1Val = 0;
int sensor2Val = 0;
int mean = 0;
int meanArray[5] = { 0, 0, 0, 0, 0 };
int counter = 0;

void setup()
{
	Serial.begin(9600);
	Serial.println("Serial Communication Initialized");

	pinMode(outUpPin, OUTPUT);
	pinMode(outDownPin, OUTPUT);

	/**TEST LED**/ /**DISATTIVARE ASSOLUTAMENTE PRIMA DI COLLEGARE I RELE'**/
	Serial.println("Accendo LED");
	digitalWrite(outUpPin, HIGH);
	digitalWrite(outDownPin, HIGH);
	delay(1000);
	digitalWrite(outUpPin, LOW);
	digitalWrite(outDownPin, LOW);
	Serial.println("Spengo LED");
	/**FINE TEST LED**/
}

void loop()
{
	sensor1Val = analogRead(sensor1Pin);
	sensor2Val = analogRead(sensor2Pin);

	Serial.print(counter);
	Serial.print(") ");
	Serial.print("S1 = ");
	Serial.print(sensor1Val);
	Serial.print(" - S2 = ");
	Serial.println(sensor2Val);

	mean = (sensor1Val + sensor2Val) / 2;

	meanArray[counter] = mean;

	if (counter == 4) {
		counter = 0;
	}
	else {
		counter++;
	}

	delay(1000);
}
