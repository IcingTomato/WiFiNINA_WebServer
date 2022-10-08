/*
  WiFi Web Server

 A simple web server that shows the value of the analog input pins.

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the WiFi.begin() call accordingly.

 Circuit:
 * Analog inputs attached to pins A0 through A5 (optional)

 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe

 */

#include <SPI.h>
#include <WiFiNINA.h>
#include <utility/wifi_drv.h>
const int redPin = 25;
const int greenPin = 26;
const int bluePin = 27;


#define SECRET_SSID "@PHICOMM_2E5950"
#define SECRET_PASS "myfamily"
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                 // your network key index number (needed only for WEP)

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void printWifiStatus();

void setup() 
{
    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    WiFiDrv::pinMode(25, OUTPUT); //define green pin
    WiFiDrv::pinMode(26, OUTPUT); //define red pin
    WiFiDrv::pinMode(27, OUTPUT); //define blue pin
    // while (!Serial) 
    // {
    //     ; // wait for serial port to connect. Needed for native USB port only
    // }
    WiFiDrv::analogWrite(redPin, 20);
    delay(1000);
    // check for the WiFi module:
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        WiFiDrv::analogWrite(redPin, 20);
        // don't continue
        while (true);
    }

    String fv = WiFi.firmwareVersion();
    if (fv < WIFI_FIRMWARE_LATEST_VERSION) 
    {
        Serial.println("Please upgrade the firmware");
    }

    // attempt to connect to WiFi network:
    while (status != WL_CONNECTED) 
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, pass);
        WiFiDrv::analogWrite(redPin, 20);
        WiFiDrv::analogWrite(greenPin, 20);

        // wait 1 seconds for connection:
        delay(1000);
    }
    server.begin();
    // you're connected now, so print out the status:
    printWifiStatus();
}


void loop() {
    // listen for incoming clients
    WiFiClient client = server.available();
    if (client) {
        Serial.println("new client");
        // an HTTP request ends with a blank line
        boolean currentLineIsBlank = true;
        while (client.connected()) {
        WiFiDrv::analogWrite(greenPin, 0);
        WiFiDrv::analogWrite(bluePin, 20);
        if (client.available()) 
        {
            char c = client.read();
            Serial.write(c);
            // if you've gotten to the end of the line (received a newline
            // character) and the line is blank, the HTTP request has ended,
            // so you can send a reply
            if (c == '\n' && currentLineIsBlank) 
            {
                // send a standard HTTP response header
                client.println("HTTP/1.1 200 OK");
                client.println("Content-Type: text/html");
                client.println("Connection: close");  // the connection will be closed after completion of the response
                // client.println("Refresh: 5");  // refresh the page automatically every 5 sec
                client.println();
                client.println("<!DOCTYPE HTML>");
                client.println("<html>");
                client.println("<meta charset=\"utf-8\">");
                client.println("<head>");
                client.println("<div class=\"post_content\">");
                client.println("<h1 class=\"title\"><a href=\"http://icing.fun/\">Index of IcingTomato/</a></h1>");
                client.println("</head>");
                client.println("<body>");
                client.println("<div class=\"me\">");
                client.println("<h4>About</h4>");
                client.println("<blockquote>");
                client.println("<p>");
                client.println("人生苦短，及时行乐。<br />Enjoy it while it lasts, because it never does.<br />夜は短し、遊びよ少年。<br />");
                client.println("</blockquote>");
                client.println("<h4>In Brief</h4>");
                client.println("<p>The one <s> can use magic </s> who studies Electronic information, Information Security, Computer Science, Japanese, Law, <strong>BUT he is still a Business English majored student</strong>.</p>");
                client.println("<blockquote>");
                client.println("<p>莫见乎隐，莫显乎微，故君子慎其独也。<br />There is nothing more visible than what is secret, and nothing more manifest than what is minute. Therefore the superior man is watchful over himself, when he is alone.<br />隠かくれたるより見あらわるるは莫なく、微かすかなるより顕あきらかなるは莫なし。故ゆえに君くん子しは其その独ひとりを慎つつしむなり。<br /></p>");
                client.println("</blockquote>");
                client.println("<h4>Properties</h4>");
                client.println("<ul>");
                client.println("<li>Linux User (Debian/Ubuntu/RHel/CentOS/Fedora...)</li>");
                client.println("<li>Networking/Electronic Engineering</li>");
                client.println("<li>Embedded Enthusiast (FPGA/MPU/MCU/DSP/SoC...)</li>");
                client.println("<li>Display Collector</li>");
                client.println("<li>Radio Amateur</li>");
                client.println("<li>C/C++/Python/Assembly/HTML/CSS/JavaScript/Ruby/MySQL...</li>");
                client.println("<li>Cantonese/English/日本語/Français/Deutsch/Русская</li>");
                client.println("<li><s> Bugs Creater </s></li>");
                client.println("<li><s> Хорошо ハラショー </s></li>");
                client.println("</ul>");
                client.println("<h4>About this Blog</h4>");
                client.println("<p>This pages made by <a href=\"https://pages.github.com/\">GitHub Pages</a> and <a href=\"http://jekyll.com.cn/\">Jekyll</a>. </p>");
                client.println("<p>Now the website is deployed on <a href=\"https://www.aliyun.com/\">Alibaba Cloud</a>.</p>");
                client.println("<h4>Career</h4>");
                client.println("<ul>");
                client.println("<li>2021-2022 <a href=\"https://www.seeed.cc/\">Seeed Studio</a>/<a href=\"https://www.chaihuo.org/\">Chaihuo Maker</a> Products Application Engineer</li>");
                client.println("<li>2022- <a href=\"https://m5stack.com/\">M5Stack</a> Linux/Raspberry Pi Embedded Software Engineer &amp; ESP32 Machine Learning Engineer</li>");
                client.println("</ul>");
                client.println("<h4>Some Pages...</h4>");
                client.println("<p>Here is some pages I designed. In pursuit of absolute simplicity.</p>");
                client.println("<ul>");
                client.println("<li><a href=\"https://icingtomato.gitee.io/chp/index.html\">Rainbow Fart Generater</a></li>");
                client.println("<li><a href=\"http://icingtomato.gitee.io/simple-tool-pages/flip-clock/\">Flip Clock</a></li>");
                client.println("</ul>");
                client.println("<hr class=\"line\">");
                client.println("<br>");
                client.println("<div class=\"donate\">");
                client.println("<p>人生苦短，及时行乐。</p><p>Enjoy it while it lasts, because it never does.</p><p>夜は短し、遊びよ少年。</p>");
                client.println("</div>");
                client.println("<br>");
                client.println("<hr class=\"line\">");
                client.println("<div class=\"footer\">");
                client.println("<p>Created by <a href=\"https://github.com/IcingTomato\" target=\"_blank\">IcingTomato</a>; Code licensed under <a href=\"https://github.com/IcingTomato/index/blob/master/LICENSE\" target=\"_blank\">MIT License</a>; <a href=\"https://beian.miit.gov.cn/\">粤ICP备2021015701号</a></p>");
                client.println("</div>");
                client.println("</body>");
                client.println("</html>");
                break;
            }
            if (c == '\n') 
            {
            // you're starting a new line
                currentLineIsBlank = true;
            } 
            else if (c != '\r') 
            {
            // you've gotten a character on the current line
                currentLineIsBlank = false;
            }
        }
        }
        // give the web browser time to receive the data
        delay(1);

        // close the connection:
        client.stop();
        WiFiDrv::analogWrite(bluePin, 0);
        WiFiDrv::analogWrite(greenPin, 20);
        Serial.println("client disconnected");
    }
}


void printWifiStatus() {
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print your board's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
    WiFiDrv::analogWrite(redPin, 0);
    WiFiDrv::analogWrite(greenPin, 20);
}