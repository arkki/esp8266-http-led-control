#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const int RED = 15;
const int GREEN = 12;
const int BLUE = 13;


MDNSResponder mdns;

// Replace with your network credentials
const char *ssid = "BlazingBilby";
const char *password = "BilbyHillock";

ESP8266WebServer server(80);

String webPage = "";


void setup(void) {
    webPage += "<h1>ESP8266 Web Server</h1>";
    webPage += "<p>GREEN<a href=\"/green/on\"><button>ON</button></a>&nbsp;<a href=\"/green/off\"><button>OFF</button></a></p>";
    webPage += "<p>RED<a href=\"/red/on\"><button>ON</button></a>&nbsp;<a href=\"/red/off\"><button>OFF</button></a></p>";
    webPage += "<p>BLUE<a href=\"/blue/on\"><button>ON</button></a>&nbsp;<a href=\"/blue/off\"><button>OFF</button></a></p>";

    // preparing GPIOs
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

    delay(1000);
    Serial.begin(9600);
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    if (mdns.begin("esp8266", WiFi.localIP())) {
        Serial.println("MDNS responder started");
    }

    server.on("/", []() {
        server.send(200, "text/html", webPage);
    });
    server.on("/green/on", []() {
        server.send(200, "text/html", webPage);
        analogWrite(GREEN, 1023);
        delay(1000);
    });
    server.on("/green/off", []() {
        server.send(200, "text/html", webPage);
        analogWrite(GREEN, 0);
        delay(1000);
    });

    server.on("/red/on", []() {
        server.send(200, "text/html", webPage);
        analogWrite(RED, 1023);
        delay(1000);
    });
    server.on("/red/off", []() {
        server.send(200, "text/html", webPage);
        analogWrite(RED, 0);
        delay(1000);
    });

    server.on("/blue/on", []() {
        server.send(200, "text/html", webPage);
        analogWrite(BLUE, 1023);
        delay(1000);
    });
    server.on("/blue/off", []() {
        server.send(200, "text/html", webPage);
        analogWrite(BLUE, 0);
        delay(1000);
    });

    server.begin();
    Serial.println("HTTP server started");
}

void loop(void) {
    server.handleClient();
}