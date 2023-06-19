#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <unordered_map>

struct Timer{
    bool isRunnning;
    float startTime;
    float duration;

}

class TimeManager{
    unordered_map<const char*, Timer> timers;       // ID: active timers

    public:
    void createTimer(const char* ID, float duration);
    void deleteTimer(const char* ID);
    void changeDuration(const char* ID, float duration);
    void startTimer(const char* ID);
    bool isFinished(const char* ID);
};

#endif