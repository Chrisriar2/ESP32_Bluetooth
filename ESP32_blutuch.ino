#include <BluetoothSerial.h>
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);

  // Iniciar servidor Bluetooth
  SerialBT.begin("MiServidor");

  // Configurar PIN fijo de emparejamiento (4 dígitos)
  esp_bt_pin_type_t pin_type = ESP_BT_PIN_TYPE_FIXED;
  esp_bt_pin_code_t pin_code;
  memcpy(pin_code, "1234", 4);
  esp_bt_gap_set_pin(pin_type, 4, pin_code);

  Serial.println("Servidor Bluetooth iniciado con PIN 1234. Esperando conexión...");
}

void loop() {
  if (SerialBT.hasClient()) {
    if (SerialBT.available()) {
      String dato = SerialBT.readStringUntil('\n');
      Serial.print("Cliente dice: ");
      Serial.println(dato);
      SerialBT.print("Recibido con éxito\n");
    }
  }
}
