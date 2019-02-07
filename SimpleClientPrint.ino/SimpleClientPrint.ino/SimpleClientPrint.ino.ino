
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 103);
EthernetServer server(80);
int zz=0;
int x = 15;
int myArray[] = {10, 2, 3, 40, 5, 60};

void setup() {
  Ethernet.begin(mac, ip); //starting the connection to local network
  server.begin();          //starting the server
}

void loop() {
  EthernetClient client = server.available();
  {
    client.println("<!DOCTYPE html>");            //writing the html page
    client.println("<html>");
    client.println("<head>");
    client.println("<title>'Test of client print'</title>" );
    client.println("/<head>");
    client.println("<body>");
    //***********************************************************************************************
    client.println("<p>Hello World</p>");         //simple print back to the browser web page
    client.println("<p>Simple server test is working OK using client.print</p>");
    client.println("<p>Printing the value from the variable x</p>");
    client.println(x);
    client.println("<p>Printing the 4th value from the array</p>");
    client.println(myArray[3]);

    
    //**********************************************************************************************
    client.println("<script>");    
    //script code would go here
    client.println("</script");                   //closing the html tags

    client.println("</body>");
    client.println("</html>");
  }
  delay(100);
  client.stop();                                  //closing the client
}
