
#include <SPI.h>
#include <Ethernet.h>

byte mac[]={
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(198, 168, 1, 103);
EthernetServer server(80);

void setup() {
  Ethernet.begin(mac, ip);
  server.begin();

}

void loop() {
  EthernetClient client=server.available();
  {
    client.print("Hello World");
    client.println();
    }
    client.println();
    delay(100);
    client.stop();
    
    

}
