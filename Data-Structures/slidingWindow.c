#include <stdio.h>

#define BUFFER_SIZE 10
#define WINDOW_SIZE 3

int sensor_buffer[BUFFER_SIZE];
int samples_received = 0;

/**
 * Slides a 3-element window across the 10-element buffer.
 */
void processSlidingWindow() {
    printf("Current Buffer: [ ");
    for(int i = 0; i < BUFFER_SIZE; i++) {
        printf("%d ", sensor_buffer[i]);
    }
    printf("]\n");

    // Slide the window of size 3 across the buffer of size 10
    // We stop at BUFFER_SIZE - WINDOW_SIZE so we don't read past the array end
    for (int i = 0; i <= BUFFER_SIZE - WINDOW_SIZE; i++) {
        int sum = 0;
        
        // Calculate the sum for the current 3-sample window
        for (int j = 0; j < WINDOW_SIZE; j++) {
            sum += sensor_buffer[i + j];
        }
        
        double moving_average = (double)sum / WINDOW_SIZE;
        
        printf("  Window [%d, %d, %d] -> Moving Average: %.2f\n", 
               sensor_buffer[i], sensor_buffer[i+1], sensor_buffer[i+2], moving_average);
    }
    printf("---\n");
}

/**
 * Shifts the 10-element buffer left and adds the newest sensor reading.
 */
void addSensorData(int new_value) {
    // Shift old data left
    for (int i = 0; i < BUFFER_SIZE - 1; i++) {
        sensor_buffer[i] = sensor_buffer[i + 1];
    }
    
    // Add new data to the end
    sensor_buffer[BUFFER_SIZE - 1] = new_value;
    
    // Track if the buffer is full
    if (samples_received < BUFFER_SIZE) {
        samples_received++;
    }
    
    // Process the inner windows only when the main buffer is full
    if (samples_received == BUFFER_SIZE) {
        processSlidingWindow();
    }
}

int main() {
    // Simulated continuous data stream
    int incoming_sensor_stream[] = {12, 14, 15, 25, 14, 13, 12, 11, 2, 12, 13, 14, 15};
    int stream_length = sizeof(incoming_sensor_stream) / sizeof(incoming_sensor_stream[0]);

    for (int i = 0; i < stream_length; i++) {
        printf("Received sample: %d\n", incoming_sensor_stream[i]);
        addSensorData(incoming_sensor_stream[i]);
    }

    return 0;
}