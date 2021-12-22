#include <stdio.h>
#include "Timer.h"

/*
* 
* 1-> Timeout değeri vererek timer'ı başlatabilmeliyim.
* 2-> Timer'ı istediğim an durdurabilmeliyim.
* 3-> Timer'ı istediğim an resetleyebilmeliyim.
* 4-> Timer'dan o ana kadar geçmiş olan süreyi birim bazında alabilmeliyim.
* 5-> Timer'dan verdiğimiz timeout değerine göre kalan süreyi alabilmeliyim.
*/


int main()
{
	Timer_Start(100);
	t_bool isTimerResetBefore = FALSE;
	int i = 0;
	while (1)
	{
		if (i > 100)
		{
			printf("Timer durduruldu.\n");
			Timer_Stop();
			break;
		}
		else
		{
			/* else not needed */
		}

		if (i % 5 == 0)
		{
			printf("Suana kadar gecen sure-> %d/%d\n", Timer_ElapsedTime(), 100);
		}
		else
		{
			/* else not needed */
		}

		if (i % 10 == 0)
		{
			printf("Kalan sure-> %d/%d\n", Timer_RemainingTime(), 100);
		}
		else
		{
			/* else not needed */
		}

		if (i == 50 && isTimerResetBefore == FALSE)
		{
			i = 0;
			printf("Timer resetlendi...\n");
			Timer_Reset();
			isTimerResetBefore = TRUE;
		}
		else
		{
			/* else not needed */
		}

		Timer_HandleTimeout();
		i++;
	}

	if (Timer_IsTimeoutOccured() == TRUE)
	{
		printf("Timeout oldu!\n");
	}
	else
	{
		printf("İstegimiz verdigimiz sure icinde gerceklesti...\n");
	}
}