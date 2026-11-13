// on-time in milliseconds after the wake trigger
const int on_time = 5000;

// collumn pins left to right
int c1 = 1;
int c2 = 2;
int c3 = 3;
int c4 = 4;
int c5 = 5;
int c6 = 6;
int first_c;
int last_c;

// row pins top to bottom
int h; // 17 at default orientation
int m = 16;
int s; // 15 at default orientation

// value display variables
const int refresh_rate = (30 * 3); // desired refresh rate in Hz multiplied by the amount of rows
unsigned long last_refresh;
int refresh_row; // equal to h at default orientation
int row_value;
int bit = 1; // variable used to check if a bit (column) should be 1 or 0 (on or off)

// brighness control variables
const int photoresistor_pin = 0;
int ambient_light;
int brightness;

// rotary encoder variables
int sw = 18;
int encoder_A = 13;
int encoder_B = 14;

// time variables
int hours;
int minutes;
int seconds;
unsigned long last_ms;

int increment;

void setup() {
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
}

void loop() {
  if (wake()) {

// set matrix orientation
    if (orientation()) {
      increment = 1;
      h = 17;
      s = 15;
      first_c = c1;
      last_c = c6;
    }
    else {
      increment = -1;
      h = 15;
      s = 17;
      first_c = c6;
      last_c = c1;
    }
    refresh_row = h; // starting refresh row

// display time
    last_ms = millis();
    while ((millis() - last_ms) < on_time) {
      animation();
      display();
    }
  }
}

bool wake() {
// detect specific watch movement to wake the matrix
}

bool orientation() {
// detect accelerometer orientation and 
}

void animation(){
// matrix wake-up and flip animation
}

void display() {

// record RTC time into time variables


// set refresh row
  if (refresh_row == s) refresh_row = h;
  else refresh_row += increment;

  if (refresh_row == h) row_value = hours;
  else if (refresh_row == m) row_value = minutes;
  else if (refresh_row == s) row_value = seconds;

// display row value in binary
  for (int c = first_c; c != last_c + increment; c += increment) {
    if (row_value & bit) {
      digitalWrite(c, HIGH);
    }
    bit *= 2;
  }

// erase the row
  for (int c = first_c; c != last_c + increment; c += increment) {
    digitalWrite(c, LOW);
  }
  digitalWrite(refresh_row, LOW);

// reset the bit checked
  bit = 1;
}