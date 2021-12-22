#ifndef TIMER_H
#define TIMER_H

#define FALSE 0
#define TRUE 1

typedef int t_bool;


t_bool Timer_Start(unsigned int timeoutValue);
t_bool Timer_Stop();
unsigned int Timer_ElapsedTime();
unsigned int Timer_RemainingTime();
void Timer_Timeout();
void Timer_Reset();
t_bool Timer_IsTimeoutOccured();
void Timer_HandleTimeout();


#endif
