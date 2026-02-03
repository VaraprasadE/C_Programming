#include <stdio.h>

// 1. Define the type
typedef void (*TimerCallback_t)(int);

// 2. Global variable to store the application's callback
// 'static' keeps it private to this driver file
static TimerCallback_t g_app_callback = NULL;

// 3. Registration Function (Called by App)
// Just saves the pointer. Does NOT execute it yet.
void register_timer_cb(TimerCallback_t cb) {
    g_app_callback = cb;
    printf("[Driver] Callback registered successfully.\n");
}

// 4. The ISR (Called by Hardware when timer expires)
void Timer_ISR_Handler(void) {
    // Always check if a callback exists before calling!
    if (g_app_callback != NULL) {
        // We pass '1' as a dummy event ID
        g_app_callback(1);
    }
}

// --- Application Code ---

void my_app_handler(int event_id) {
    printf("[App] Received Timer Event: %d\n", event_id);
}

int main() {
    register_timer_cb(my_app_handler);
    
    // Simulate hardware interrupt firing later
    printf("[Hardware] Timer Expired! Firing ISR...\n");
    Timer_ISR_Handler();
    
    return 0;
}