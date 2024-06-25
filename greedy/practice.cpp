#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

#define SECTIONS 5
#define ONE_HOUR 1
#define START_HOUR 6
#define END_HOUR 22

// Watering intervals in seconds (simplified for demonstration)
#define FLOWERS_WATERING_INTERVAL 8
#define VEGETABLES_FRUITS_WATERING_INTERVAL 12
#define HERBS_WATERING_INTERVAL 24
#define GREENHOUSE_WATERING_INTERVAL 1 // Variable, depends on humidity (simplified)

// Soil moisture levels (0: dry, 1: wet)
int moisture_levels[SECTIONS] = {0, 0, 0, 0, 0};

// Semaphore for water supply
sem_t water_supply;

// Mutex for console output
pthread_mutex_t console_mutex;

void *water_section(void *arg)
{
    int section = (int)arg;
    int watering_interval;
    time_t start_time, current_time;

    // Determine watering interval based on section
    switch (section)
    {
    case 0:
        watering_interval = FLOWERS_WATERING_INTERVAL;
        break;
    case 1:
    case 2:
        watering_interval = VEGETABLES_FRUITS_WATERING_INTERVAL;
        break;
    case 3:
        watering_interval = HERBS_WATERING_INTERVAL;
        break;
    case 4:
        // Simplify greenhouse watering interval based on random humidity
        srand(time(NULL));
        watering_interval = (rand() % 2 + 1) * GREENHOUSE_WATERING_INTERVAL;
        break;
    default:
        return NULL;
    }

    time(&start_time);
    while (1)
    {
        time(&current_time);

        // Check soil moisture level
        if (moisture_levels[section] == 1)
        {
            sleep(ONE_HOUR);
            continue;
        }

        // Wait for water supply
        sem_wait(&water_supply);

        // Water the section
        pthread_mutex_lock(&console_mutex);
        printf("Watering section %d\n", section);
        pthread_mutex_unlock(&console_mutex);

        sleep(watering_interval);

        // Release water supply
        sem_post(&water_supply);

        // Update moisture level to wet
        moisture_levels[section] = 1;

        // Simulate time gap
        sleep(ONE_HOUR);

        // Reset moisture level to dry after certain period (for demonstration)
        if (difftime(current_time, start_time) >= END_HOUR - START_HOUR)
        {
            moisture_levels[section] = 0;
            time(&start_time);
        }
    }
}

int main(int argc, char *argv[])
{
    pthread_t threads[SECTIONS];
    int section_ids[SECTIONS];

    // Initialize semaphore and mutex
    sem_init(&water_supply, 0, 1);
    pthread_mutex_init(&console_mutex, NULL);

    // Create threads for each section
    for (int i = 0; i < SECTIONS; i++)
    {
        section_ids[i] = i;
        pthread_create(&threads[i], NULL, water_section, &section_ids[i]);
    }

    // Let the watering process run for a specified period (e.g., 60 seconds)
    sleep(60);

    // Cancel threads and clean up
    for (int i = 0; i < SECTIONS; i++)
    {
        pthread_cancel(threads[i]);
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphore and mutex
    sem_destroy(&water_supply);
    pthread_mutex_destroy(&console_mutex);

    return 0;
}