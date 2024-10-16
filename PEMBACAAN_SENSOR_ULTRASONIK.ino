#include <Servo.h> // Library untuk servo motor

// Pin untuk sensor ultrasonik
const int trigPin = 9;
const int echoPin = 10;

// Variabel untuk servo motor
Servo myServo;
int servoPin = 11;
int pos = 0; // Posisi servo

void setup() {
  // Inisialisasi komunikasi serial untuk monitoring
  Serial.begin(9600);
  
  // Set pin sensor ultrasonik
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Inisialisasi servo pada pin yang sesuai
  myServo.attach(servoPin);
}

void loop() {
  // Servo berputar dari 0 hingga 180 derajat
  for (pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos); // Gerakkan servo ke posisi
    int distance = measureDistance(); // Panggil fungsi untuk mengukur jarak
    Serial.print("Posisi Servo: ");
    Serial.print(pos);
    Serial.print(" derajat, Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(200); // Tunggu 200ms untuk stabilitas pengukuran
  }
  
  // Servo berputar balik dari 180 hingga 0 derajat
  for (pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    int distance = measureDistance();
    Serial.print("Posisi Servo: ");
    Serial.print(pos);
    Serial.print(" derajat, Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(200);
  }
}

// Fungsi untuk mengukur jarak menggunakan sensor ultrasonik
int measureDistance() {
  // Kirim sinyal ultrasonic (trig)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Hitung waktu yang dibutuhkan echo kembali
  long duration = pulseIn(echoPin, HIGH);
  
  // Hitung jarak berdasarkan waktu echo (kecepatan suara 343 m/s)
  int distance = duration * 0.034 / 2; // Konversi menjadi cm
  return distance;
}
