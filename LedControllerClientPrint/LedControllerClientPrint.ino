
#include <SPI.h>
#include <Ethernet.h>

int led = 8;
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 1, 103);
EthernetServer server(80);
String readString;

void setup() {

  Ethernet.begin(mac, ip); //starting the connection to local network
 Serial.begin(9600);          //starting the serial coms
  pinMode(led, OUTPUT);
  server.begin();
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.print(c);

        if (readString.length() < 100) {
          readString += c;
        }
        if (c == '\n') {
          Serial.println(readString);
          client.println("<HTTP/1.1 200 OK>");
          client.println("<Connection-Type: text/html>");
          client.println("<Connection:close>");
          client.println();
          //***********************************************************************************************
          client.println("<!DOCTYPE html>");            //writing the html page
          client.println("<html>");
          client.println("<head>");
          client.println("<title>'led html controller'</title>" );
          client.println("/<head>");
          client.println("<body>");
          client.println("<body>");
          client.println("<a href=\"/?button1on\"\"><button>LED ON</button></a>");
          client.println("<a href=\"/?button2off\"\"><button>LED OFF</button></a>");
          client.println("<body style=background-color:grey>");

          //***********************************************************************************************
          delay(100);
          client.stop();                                  //closing the client

            if (readString.indexOf("?button1on")>0){
            digitalWrite(led, HIGH);
          }

      if (readString.indexOf("?button2off")>0){
            digitalWrite(led, LOW);
          }
          readString = "";
        }    
      }
    }
  }
          client.println("</body>");
          client.println("</html>");
}


   //       
