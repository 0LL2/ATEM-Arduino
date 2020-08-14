#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 
  0x90, 0xA2, 0xDA, 0x00, 0xE8, 0xE9 };    // <= SETUP
IPAddress ip(192, 168, 10, 99);       // <= SETUP

#include <ATEM.h>

ATEM AtemSwitcher(IPAddress(192, 168, 10, 241), 56417);  // <= SETUP (the IP address of the ATEM switcher)

void setup() { 

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
    
  Ethernet.begin(mac,ip);
  Serial.begin(9600);  

  AtemSwitcher.serialOutput(true);
  AtemSwitcher.connect();
}
int pushButton = 0;

void loop() {
  AtemSwitcher.runLoop();

  digitalWrite(10, !AtemSwitcher.getProgramTally(1));
  digitalWrite(11, !AtemSwitcher.getProgramTally(2));
  digitalWrite(12, !AtemSwitcher.getProgramTally(3));
  digitalWrite(13, !AtemSwitcher.getProgramTally(4));

  if (!digitalRead(2))  {
    if (pushButton !=2)  {
      pushButton=2;
      Serial.println("Preview 1");
      AtemSwitcher.changePreviewInput(1);
    }
  } else if (pushButton==2) {
    pushButton = 0; 
  }

  if (!digitalRead(3))  {
    if (pushButton !=3)  {
      pushButton=3;
      Serial.println("Preview 2");
      AtemSwitcher.changePreviewInput(2);
    }
  } else if (pushButton==3) {
    pushButton = 0; 
  }
  if (!digitalRead(4))  {
    if (pushButton !=4)  {
      pushButton=4;
      Serial.println("Preview 3");
      AtemSwitcher.changePreviewInput(3);
    }
  } else if (pushButton==4) {
    pushButton = 0; 
  }
  if (!digitalRead(5))  {
    if (pushButton !=5)  {
      pushButton=5;
      Serial.println("Preview 4");
      AtemSwitcher.changePreviewInput(4);
    }
  } else if (pushButton==5) {
    pushButton = 0; 
  }
  //--------------------------------------------------------------------------------//
  if (!digitalRead(6))  {
    if (pushButton !=6)  {
      pushButton=6;
      Serial.println("Auto");
      AtemSwitcher.doAuto();
    }
  } else if (pushButton==6) {
    pushButton = 0; 
  }

  if (!digitalRead(7))  {
    if (pushButton !=7)  {
      pushButton=7;
      Serial.println("Fade to black");
      AtemSwitcher.fadeToBlackActivate();
    }
  } else if (pushButton==7) {
    pushButton = 0; 
  }
  if (!digitalRead(8))  {
    if (pushButton !=8)  {
      pushButton=8;
      Serial.println("Black");
      AtemSwitcher.changePreviewInput(0);
    }
  } else if (pushButton==8) {
    pushButton = 0; 
  }
  if (!digitalRead(9))  {
    if (pushButton !=9)  {
      pushButton=9;
      Serial.println("Cut");
      AtemSwitcher.doCut();
    }
  } else if (pushButton==9) {
    pushButton = 0; 
  }
  
}
  
