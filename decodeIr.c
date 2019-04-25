#include<stdio.h>

int main()
{
	int cnt = 0;
	unsigned char byte = 0;
	unsigned char offset = 1;
	int onTime, offTime;

	while( 1 )
	{
		cnt = scanf("%d%d", &onTime, &offTime );
		if( cnt < 2 || offTime == 0 )
		{
			break;
		}
		

		if( offTime > 10000 ) //信号の区切り
		{

		}
		else if( onTime > 2000 ) // リーダー
		{
			if( offset != 1 )
			{
				printf("%02X", byte );
			}
			offset = 1;
			byte = 0;
			putchar('\n');
		}
		else
		{
			if( offTime > 1000 ) // 1
			{
				byte |= offset; 
			}	
			offset <<= 1;
			if( !offset ) // オーバーフロー
			{
				printf("%02X", byte );
				offset = 1;
				byte = 0;
			}
		}

	}

	putchar('\n');
	return 0;
}
