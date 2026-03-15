#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

// A simple container to hold an array of doubles and its length.
// This is intentionally lightweight and can wrap existing arrays.
typedef struct {
    double *items;
    size_t length;
} doubleArray;

/// Counts how many "peaks" exist in a signal.
///
/// A point is considered a peak if it is strictly higher than both neighbors by
/// at least 5.0 (high peak) or strictly lower than both neighbors by at least 5.0
/// (low peak).
///
/// @param values Pointer to a doubleArray representing the signal.
/// @return The number of peaks in the signal.
int countPeaks(const doubleArray *values) {
    if (values == NULL || values->items == NULL) {
        return 0;
    }

    // Need at least 3 points to have a middle sample with two neighbors.
    if (values->length < 3) {
        return 0;
    }

    int count = 0;

    // Scan across the array, skipping the first and last items.
    for (size_t i = 1; i + 1 < values->length; i++) {
        double prev = values->items[i - 1];
        double curr = values->items[i];
        double next = values->items[i + 1];

        // HIGH-PEAK: curr is at least 5 units above both neighbors.
        if ((curr - prev > 5.0) && (curr - next > 5.0)) {
            count++;
        }
        // LOW-PEAK: curr is at least 5 units below both neighbors.
        else if ((prev - curr > 5.0) && (next - curr > 5.0)) {
            count++;
        }
    }

    return count;
}

int main(void) {
    double samples[] = { 0.0, 10.0, 2.0, 12.0, 6.0, -5.0, 0.0, -10.0, -4.0 };
    doubleArray values = { .items = samples, .length = sizeof(samples) / sizeof(samples[0]) };

    int peaks = countPeaks(&values);
    printf("peak count = %d\n", peaks);

    return 0;
}
