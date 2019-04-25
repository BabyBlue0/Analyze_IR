#include<stdio.h>
#include<wiringPi.h>
#include<stdlib.h>
#include<time.h>

#define READ_PIN	2
#define DELAY_TIME	5

int main()
{
	if( wiringPiSetupGpio() == -1 )
	{
		printf("Error wiringPi setup\n");
		exit( 1 );
	}

	pinMode( READ_PIN, INPUT );
	delay( 10 );
	//printf("please, send irData!\n");

	int onTime, offTime;

	struct timespec ts0, ts1, ts2;
	while( digitalRead( READ_PIN ) ); // wait onTime
	clock_gettime( CLOCK_REALTIME, &ts0 );
	//printf("Catch the signal!!\n");
	
	int now = 0;
	while( (ts2.tv_sec-ts0.tv_sec) < 5 )
	{
		if( digitalRead( READ_PIN ) != now )
		{
			clock_gettime( CLOCK_REALTIME, &ts1 );
			printf("%8ld", (ts1.tv_nsec-ts0.tv_nsec)/1000 );
			if( now ) putchar('\n'); // 1:off
			ts0 = ts1;
			now ^= 1;
		}

		clock_gettime( CLOCK_REALTIME, &ts2 );
	}
	
	putchar('\n');
	//printf("\nEnd Program!!\n");
}	
