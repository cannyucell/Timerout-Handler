#include "Timer.h"

static t_bool gIsTimerEnabled = FALSE;
static t_bool gIsTimeoutOccured = FALSE;
static unsigned int gTimeoutValue = 0;
static unsigned int gCurrentTimeoutValue = 0;

t_bool Timer_Start(unsigned int timeoutValue)
{
	if (gIsTimerEnabled == FALSE)
	{
		gTimeoutValue = timeoutValue;
		gCurrentTimeoutValue = 0;
		gIsTimerEnabled = TRUE;
		printf("Timer_Start-> Timer baslatildi...\n");
		return TRUE;
	}
	else
	{
		printf("Timer_Start-> Timer daha önceden baslatildigi icin tekrar baslatmadik!\n");
		return FALSE;
	}
}

t_bool Timer_Stop()
{
	if (gIsTimerEnabled == TRUE)
	{
		gTimeoutValue = 0;
		gCurrentTimeoutValue = 0;
		gIsTimerEnabled = FALSE;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	
}

unsigned int Timer_ElapsedTime()
{
	// O ana kadar sayılmış değeri bize dönderecek.
	return  gCurrentTimeoutValue;
}

unsigned int Timer_RemainingTime()
{
	return (gTimeoutValue - gCurrentTimeoutValue);
}

void Timer_Reset()
{
	// O ana kadar sayılmış değer sıfırlanacaktır.
	gCurrentTimeoutValue = 0;
}

t_bool Timer_IsTimeoutOccured()
{
	return gIsTimeoutOccured;

}

void Timer_HandleTimeout()
{
	// Timer aktifleştirildi mi?
	if (gIsTimerEnabled == TRUE)
	{
		// Eğer timer aktifleştirildiyse sayacı her seferinde 1 arttır.
		gCurrentTimeoutValue++;

		// Şuana kadar sayılmış sayaç değeri kullanıcıdan aldığımız değere eşit veya o değerden büyükse zaman aşımına uğraşmış demektir.
		if (gCurrentTimeoutValue >= gTimeoutValue)
		{
			gIsTimeoutOccured = TRUE;
		}
		else
		{
			/* else not needed */
		}
	}
	else
	{
		/* else not needed */
	}

}