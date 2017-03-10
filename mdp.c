#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float arr[5][5]={0};
float temp_board[4][4];
int func( const void *a, const void *b)
{
	return ( *(int*)a- *(int*)b );
}
void print_board()
{
	int i, j;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
			printf("%.2f ",arr[i][j]);
		printf("\n");
	}
	printf("\n");
}
int checkEndCondition(float delta)
{
	int i, j, flag=0;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			if(fabs(arr[i][j]-temp_board[i][j])>delta)
				flag=1;

	return flag;
}
void copyTempIntoArr()
{
	int i, j;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			arr[i][j]=temp_board[i][j];
}
void copyArrIntoTemp()
{
	int i, j;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			temp_board[i][j]=arr[i][j];
}
float maxOfAllDirections(float a, float b, float c, float d)
{
	float comp[4];
	comp[0]=a;
	comp[1]=b;
	comp[2]=c;
	comp[3]=d;
	qsort(comp,4,sizeof(float),func);
	return comp[0];
}
int main()
{
	int i, j, k, n;
	int team_number;
	float delta, cost,goingEastValue,goingWestValue,goingNorthValue,goingSouthValue;
	scanf("%d", &team_number);
	delta=(1/20)*team_number;
	cost=(-1/20)*team_number;

	arr[1][3]=team_number;
	arr[3][2]=-team_number;

	//arr[0][0]=0;arr[0][1]=0;arr[0][2]=0;arr[0][3]=0;arr[0][4]=0;arr[0][5]=0;arr[1][0]=0;arr[2][0]=0;arr[3][0]=0;arr[4][0]=0;arr[5][0]=0;arr[5][1]=0;arr[5][2]=0;arr[5][3]=0;arr[5][4]=0;arr[5][5]=0;arr[1][5]=0;arr[2][5]=0;arr[3][5]=0;arr[4][5]=0;arr[5][5]=0;

	print_board();
	do
	{
		copyArrIntoTemp();
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
			{
				if((i==1 && j==1) || (i==1 && j==2) || (i==1 && j==3) || (i==1 && j==4) || (i==3 && j==2) || (i==3 && j==3))
					continue;
				goingEastValue=cost+arr[i][j+1]*0.8 + arr[i+1][j]*0.1 + arr[i-1][j]*0.1;
				goingWestValue=cost+arr[i][j-1]*0.8 + arr[i+1][j]*0.1 + arr[i-1][j]*0.1;
				goingNorthValue=cost+arr[i-1][j]*0.8 + arr[i][j-1]*0.1 + arr[i][j+1]*0.1;
				goingSouthValue=cost+arr[i+1][j]*0.8 + arr[i][j-1]*0.1 + arr[i][j+1]*0.1;
				temp_board[i][j]=maxOfAllDirections(goingEastValue,goingWestValue,goingNorthValue,goingSouthValue);
			}
		copyTempIntoArr();
		print_board();

	}while(checkEndCondition(delta));
	return 0;
}



