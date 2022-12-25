#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <SimpleKalmanFilter.h>

Adafruit_MPU6050 mpu1;
Adafruit_MPU6050 mpu2;
// Adafruit_MPU6050 mpu3;
// Adafruit_MPU6050 mpu4;

// typedef struct struct_message {
//   double SentRoll1;
//   double SentPitch1;
// } struct_message;

// float AcX_kalman;
// float AcY_kalman;
// float AcZ_kalman;
// float roll1;
// float pitch1;
// float roll2;
// float pitch2;


// SimpleKalmanFilter simpleKalmanFilter1(1, 1, 10);
// SimpleKalmanFilter simpleKalmanFilter2(1, 1, 10);
// SimpleKalmanFilter simpleKalmanFilter3(1, 1, 10);

// Select I2C BUS
void TCA9548A(uint8_t bus){
  Wire.beginTransmission(0x70);  // TCA9548A address
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
}

//It is theorized something is wrong with this function
void printValues(Adafruit_MPU6050 mpu, int bus) {
  TCA9548A (bus);
  Serial.print("Sensor number on bus");
  Serial.println(bus);
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.println(a.acceleration.z);
}
  

void setup() {
  Serial.begin(115200);
  
  // Start I2C communication with the Multiplexer
  Wire.begin();

  // Init sensor on bus number 2
  TCA9548A(2);
  if (!mpu1.begin()) {
    Serial.println("Sensor 1 init failed");
    // while (1){
    //   yield();
    //   }
  }
  
  // Init sensor on bus number 3
  TCA9548A(3);
  if (!mpu2.begin()) {
    Serial.println("Sensor 2 init failed");
  }
  
//   // Init sensor on bus number 4
//   TCA9548A(4);
//   if (!mpu3.begin(0x76)) {
//     Serial.println("Could not find a valid MPU6050 sensor on bus 4, check wiring!");
//     while (1);
//   }
//   Serial.println();

//   TCA9548A(5);
//   if (!mpu4.begin(0x76)) {
//     Serial.println("Could not find a valid MPU6050 sensor on bus 5, check wiring!");
//     while (1);
//   }
//   Serial.println();
}
 
void loop() {
  // unsigned long currentMillis = millis();
  // if (currentMillis - previousMillis >= interval) {
  //   // save the last time you updated the DHT values
  //   previousMillis = currentMillis;

    // sensors_event_t a, g, temp;

    // TCA9548A (2);
    // Serial.print("Sensor number on bus");
    // Serial.println(2);
    // mpu1.getEvent(&a, &g, &temp);
    // Serial.print(a.acceleration.x);
    // Serial.print(a.acceleration.y);
    // Serial.print(a.acceleration.z);

    // TCA9548A (3);
    // Serial.print("Sensor number on bus");
    // Serial.println(3);
    // mpu2.getEvent(&a, &g, &temp);
    // Serial.print(a.acceleration.x);
    // Serial.print(a.acceleration.y);
    // Serial.print(a.acceleration.z);

    printValues(mpu1, 2);
    delay(1000);
    printValues(mpu2, 3);
    delay(1000);

    // printValues(mpu3, 4);
    // printValues(mpu4, 5);


    // roll1 = atan2(AcY_kalman , AcZ_kalman) * 4068 / 71;
    // pitch1 = atan2((- AcX_kalman) , sqrt(AcY_kalman * AcY_kalman + AcZ_kalman * AcZ_kalman)) * 4068 / 71;
    
    // TCA9548A(3);
    // roll2 = atan2(AcY_kalman , AcZ_kalman) * 4068 / 71;
    // pitch2 = atan2((- AcX_kalman) , sqrt(AcY_kalman * AcY_kalman + AcZ_kalman * AcZ_kalman)) * 4068 / 71;

    // Serial.print(roll1);
    // Serial.print(",");
    // Serial.println(pitch1);
    // Serial.print(roll2);
    // Serial.print(",");
    // Serial.println(pitch2);
  // }
}