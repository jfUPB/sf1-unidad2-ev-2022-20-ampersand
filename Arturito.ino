String btnState(uint8_t btnState){
  if(btnState == HIGH){
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
  constexpr uint8_t button3Pin = 32;

  switch (taskState)
  {
  case TaskStates::INIT:
  {
    Serial.begin(115200);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    pinMode(button1Pin, INPUT_PULLUP);
    pinMode(button2Pin, INPUT_PULLUP);
    pinMode(button3Pin, INPUT_PULLUP);
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
        digitalWrite(led1, HIGH);
      }
      else if (command == "led1OFF")
      {
        digitalWrite(led1, LOW);
      }
      else if (command == "led2ON")
      {
        digitalWrite(led2, HIGH);
      }
      else if (command == "led2OFF")
      {
        digitalWrite(led2, LOW);
      }
      else if (command == "led3ON")
      {
        digitalWrite(led3, HIGH);
      }
      else if (command == "led3OFF")
      {
        digitalWrite(led3, LOW);
      }
      else if (command == "readBUTTONS")
      {
        if(digitalRead(button1Pin) == HIGH && digitalRead(button1Pin) == HIGH && digitalRead(button1Pin) == HIGH)
        {
            Serial.print("0,0,0\n");
        }
        else if(digitalRead(button1Pin) == LOW && digitalRead(button1Pin) == HIGH && digitalRead(button1Pin) == HIGH)
        {
            Serial.print("1,0,0\n");
        }
        else if(digitalRead(button1Pin) == HIGH && digitalRead(button1Pin) == LOW && digitalRead(button1Pin) == HIGH)
        {
            Serial.print("0,1,0\n");
        }
        else if(digitalRead(button1Pin) == HIGH && digitalRead(button1Pin) == HIGH && digitalRead(button1Pin) == LOW)
        {
            Serial.print("0,0,1\n");
        }
        else if(digitalRead(button1Pin) == HIGH && digitalRead(button1Pin) == LOW && digitalRead(button1Pin) == LOW)
        {
            Serial.print("0,1,1\n");
        }
        else if(digitalRead(button1Pin) == LOW && digitalRead(button1Pin) == HIGH && digitalRead(button1Pin) == LOW)
        {
            Serial.print("1,0,1\n");
        }
        else if(digitalRead(button1Pin) == LOW && digitalRead(button1Pin) == LOW && digitalRead(button1Pin) == HIGH)
        {
            Serial.print("1,1,0\n");
        }
        else if(digitalRead(button1Pin) == LOW && digitalRead(button1Pin) == LOW && digitalRead(button1Pin) == LOW)
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