//Este es el código que va en el servidor, en la tarjeta que tiene el botón boot y rst
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("MiServidor"); // Nombre del servicio Bluetooth
  Serial.println("Servidor Bluetooth iniciado. Esperando conexión...");
}

void loop() {
  if (SerialBT.available()) {
    String datoRecibido = SerialBT.readStringUntil('\n');
    Serial.print("Dato recibido del cliente: ");
    Serial.println(datoRecibido);

    // Responde al cliente (opcional)
    SerialBT.print("Mensaje recibido correctamente!\n");
  }
}