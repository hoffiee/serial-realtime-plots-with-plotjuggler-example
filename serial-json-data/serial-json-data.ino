#define SIZE(x) sizeof(x)/sizeof(x[0])

static void send(int n, float* buffer) {
    // write json object with an array: {"y":[1,2,3,4]}
    Serial.print("{\"y\":[");
    for (int i = 0; i < n; i++) {
        Serial.print(buffer[i]);
        if (i < 3) {
            Serial.print(",");
        }
    }
    Serial.print("]}\n");
}

void setup() {
    Serial.begin(9600);

    // wait a bit before writing
    delay(1000);
}

void loop() {
    float buffer[4] = {0};
    float offset[SIZE(buffer)] = {0.0f, 2.0f, 4.0f, 6.0f};
    float freq[SIZE(buffer)] = {0.25f, 1.0f, 2.0f, 4.0f};
    float shift[SIZE(buffer)] = {0.0f, 1.0f, 2.0f, 3.0f};

    float t = millis()/1000.0f;

    for (int i = 0; i < SIZE(buffer); i++) {
        buffer[i] = 1.0f*sin(2.0f*PI*freq[i]*t + shift[i]) + offset[i];
    }

    send(SIZE(buffer), buffer);

    delay(10);
}
