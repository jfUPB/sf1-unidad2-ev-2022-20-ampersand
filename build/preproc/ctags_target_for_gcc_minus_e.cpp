# 1 "/home/pop-os/sf1-unidad2-ev-2022-20-ampersand/Arturito.ino"
String btnState(uint8_t btnState){
  if(btnState == 0x1){
    return "OFF";
  }
  else return "ON";
}

void task()
{
  enum class TaskStates
  {
    INIT,
    WAIT_COMMANDS
  };
  static TaskStates taskState = TaskStates::INIT;
  constexpr uint8_t led1 = 14;
  constexpr uint8_t led2 = 27;
  constexpr uint8_t led3 = 26;
  constexpr uint8_t led4 = 25;
  constexpr uint8_t button1Pin = 12;
  constexpr uint8_t button2Pin = 13;
  constexpr uint8_t button3Pin = 18;

  switch (taskState)
  {
  case TaskStates::INIT:
  {
    Serial.begin(115200);
    pinMode(led1, 0x03);
    pinMode(led2, 0x03);
    pinMode(led3, 0x03);
    pinMode(led4, 0x03);
    digitalWrite(led1, 0x0);
    digitalWrite(led2, 0x0);
    digitalWrite(led3, 0x0);
    digitalWrite(led4, 0x0);
    pinMode(button1Pin, 0x05);
    pinMode(button2Pin, 0x05);
    pinMode(button3Pin, 0x05);
    taskState = TaskStates::WAIT_COMMANDS;
    break;
  }
  case TaskStates::WAIT_COMMANDS:
  {
    if (Serial.available() > 0)
    {
      String command = Serial.readStringUntil('\n');
      if (command == "led1ON")
      {
        digitalWrite(led1, 0x1);
      }
      else if (command == "led1OFF")
      {
        digitalWrite(led1, 0x0);
      }
      else if (command == "led2ON")
      {
        digitalWrite(led2, 0x1);
      }
      else if (command == "led2OFF")
      {
        digitalWrite(led2, 0x0);
      }
      else if (command == "led3ON")
      {
        digitalWrite(led3, 0x1);
      }
      else if (command == "led3OFF")
      {
        digitalWrite(led3, 0x0);
      }
      else if (command == "led4ON")
      {
        digitalWrite(led4, 0x1);
      }
      else if (command == "led4OFF")
      {
        digitalWrite(led4, 0x0);
      }
      else if (command == "readBUTTONS")
      {
        if(digitalRead(button1Pin) == 0x1 && digitalRead(button2Pin) == 0x1 && digitalRead(button3Pin) == 0x1)
        {
            Serial.print("0,0,0\n");
        }
        else if(digitalRead(button1Pin) == 0x0 && digitalRead(button2Pin) == 0x1 && digitalRead(button3Pin) == 0x1)
        {
            Serial.print("1,0,0\n");
        }
        else if(digitalRead(button1Pin) == 0x1 && digitalRead(button2Pin) == 0x0 && digitalRead(button3Pin) == 0x1)
        {
            Serial.print("0,1,0\n");
        }
        else if(digitalRead(button1Pin) == 0x1 && digitalRead(button2Pin) == 0x1 && digitalRead(button3Pin) == 0x0)
        {
            Serial.print("0,0,1\n");
        }
        else if(digitalRead(button1Pin) == 0x1 && digitalRead(button2Pin) == 0x0 && digitalRead(button3Pin) == 0x0)
        {
            Serial.print("0,1,1\n");
        }
        else if(digitalRead(button1Pin) == 0x0 && digitalRead(button2Pin) == 0x1 && digitalRead(button3Pin) == 0x0)
        {
            Serial.print("1,0,1\n");
        }
        else if(digitalRead(button1Pin) == 0x0 && digitalRead(button2Pin) == 0x0 && digitalRead(button3Pin) == 0x1)
        {
            Serial.print("1,1,0\n");
        }
        else if(digitalRead(button1Pin) == 0x0 && digitalRead(button2Pin) == 0x0 && digitalRead(button3Pin) == 0x0)
        {
            Serial.print("1,1,1\n");
        }
      }
    }
    break;
  }
  default:
  {
    break;
  }
  }
}

void setup()
{
  task();
}

void loop()
{
  task();
}
