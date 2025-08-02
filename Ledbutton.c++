#define DEBOUNCE_DELAY 50
#define LONG_PRESS_TIME 1000


#define BUTTON1_PIN 2
#define BUTTON2_PIN 3
#define BUTTON3_PIN 4

#define LED1_PIN 8
#define LED2_PIN 9
#define LED3_PIN 10


struct Button {
    int pin;
    int last_state;
    int current_state;
    unsigned long last_debounce_time;
    unsigned long press_start_time;
    bool pressed;
    void (*short_press_action)();
    void (*long_press_action)();
};


void toggle_led1();
void toggle_led2();
void toggle_led3();
void blink_led1();
void blink_led2();
void blink_led3();
void all_leds_on();
void all_leds_off();
void handle_button(Button* btn);


Button buttons[] = {
    {BUTTON1_PIN, HIGH, HIGH, 0, 0, false, toggle_led1, blink_led1},
    {BUTTON2_PIN, HIGH, HIGH, 0, 0, false, toggle_led2, blink_led2},
    {BUTTON3_PIN, HIGH, HIGH, 0, 0, false, toggle_led3, all_leds_on}
};

const int num_buttons = sizeof(buttons) / sizeof(buttons[0]);



void toggle_led1() {
    int current_state = digitalRead(LED1_PIN);
    digitalWrite(LED1_PIN, !current_state);
    Serial.println("LED1 toggled");
}

void toggle_led2() {
    int current_state = digitalRead(LED2_PIN);
    digitalWrite(LED2_PIN, !current_state);
    Serial.println("LED2 toggled");
}

void toggle_led3() {
    int current_state = digitalRead(LED3_PIN);
    digitalWrite(LED3_PIN, !current_state);
    Serial.println("LED3 toggled");
}

void blink_led1() {
    Serial.println("Blinking LED1");
    for (int i = 0; i < 5; i++) {
        digitalWrite(LED1_PIN, HIGH);
        delay(100);
        digitalWrite(LED1_PIN, LOW);
        delay(100);
    }
}

void blink_led2() {
    Serial.println("Blinking LED2");
    for (int i = 0; i < 3; i++) {
        digitalWrite(LED2_PIN, HIGH);
        delay(200);
        digitalWrite(LED2_PIN, LOW);
        delay(200);
    }
}

void blink_led3() {
    Serial.println("Blinking LED3");
    for (int i = 0; i < 7; i++) {
        digitalWrite(LED3_PIN, HIGH);
        delay(50);
        digitalWrite(LED3_PIN, LOW);
        delay(50);
    }
}

void all_leds_on() {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
    Serial.println("All LEDs ON");
}

void all_leds_off() {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    Serial.println("All LEDs OFF");
}

void handle_button(Button* btn) {
    
    int reading = digitalRead(btn->pin);
    
   
    if (reading != btn->last_state) {
        btn->last_debounce_time = millis();
    }
    
    
    if ((millis() - btn->last_debounce_time) > DEBOUNCE_DELAY) {
       
        if (reading != btn->current_state) {
            btn->current_state = reading;
            
            
            if (btn->current_state == LOW) {
                btn->pressed = true;
                btn->press_start_time = millis();
                Serial.print("Button ");
                Serial.print(btn->pin);
                Serial.println(" pressed");
            }
            
            else if (btn->pressed) {
                btn->pressed = false;
                unsigned long press_duration = millis() - btn->press_start_time;
                
                
                if (press_duration < LONG_PRESS_TIME) {
                    Serial.print("Button ");
                    Serial.print(btn->pin);
                    Serial.println(" short press - calling short press action");
                    if (btn->short_press_action != nullptr) {
                        btn->short_press_action();
                    }
                } else {
                    Serial.print("Button ");
                    Serial.print(btn->pin);
                    Serial.println(" long press - calling long press action");
                    if (btn->long_press_action != nullptr) {
                        btn->long_press_action();
                    }
                }
            }
        }
    }
    
    btn->last_state = reading;
}

void setup() {
    Serial.begin(115200);
    Serial.println("Smart Button Handler Initialized");
    
   
    for (int i = 0; i < num_buttons; i++) {
        pinMode(buttons[i].pin, INPUT_PULLUP);
        buttons[i].last_state = HIGH;
        buttons[i].current_state = HIGH;
    }
    
    
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    pinMode(LED3_PIN, OUTPUT);
    
    
    all_leds_off();
}

void loop() {
    for (int i = 0; i < num_buttons; i++) {
        handle_button(&buttons[i]);
    }
    
    
    delay(10);
}
