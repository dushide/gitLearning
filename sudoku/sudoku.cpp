#include<iostream>
#include<algorithm>
#include <ctime>
#include<stdlib.h>
#include<string>
#include<string.h>


using namespace std;
 
int Initial_Condition [ 10 ] [ 10 ] ; 
 
bool get_Initial_Condition( int i , int j  ) //���ư˻ʺ���û�лʺ� 
{
    if( i > 9 || j > 9 ) 
        return true;
 
    for( int w = 1 ; w <= 9 ; ++w ) 
    {
        bool d= true;               //�ܷ�������� 
        for( int n = 1 ; n < j ; ++n ) 
            if( Initial_Condition[i][n] == w )  //ͬһ�г��ֹ�û��w 
            {
                d = false ;
                break ;
            }
        if ( d ) 
            for( int m = 1 ; m < i ; ++m ) 
                if( Initial_Condition[m][j] == w )  //ͬһ�г��ֹ�û��w 
                {
                    d = false ;
                    break; 
                }
        if( d ) 
        {
            int up1 = ( i/3 ) * 3 + 3 ; 
            int up2 = ( j/3 ) *3 + 3;   
 
           if( i % 3 == 0 )   
                up1 = i ; 
            if( j % 3 == 0 ) 
                up2 = j ;
            for( int p = up1-2 ; p <= up1 ; ++p  )  //�����3��3��С�������Ƿ������ͬһ������ 
            {
                if( d == false )   
                    break ;
                for( int q = up2-2 ; q <= up2 ; ++q ) 
                    if( Initial_Condition[p][q] == w ) 
                    {
                        d = false ;
                        break ;
                    }
            }
        }
        if( d ) 
        {
            Initial_Condition[i][j] = w ; 
            if( j<  9 ) 
            {
                if( get_Initial_Condition( i  , j +1 ) )  //��һ�е���һλ�� 
                    return true ;  
            }
            else
            {
                if( i < 9 )  
                {
                    if( get_Initial_Condition( i + 1 , 1 ) )   
                        return true ;
                }
                else
                    return true ;  //������ڸ�����Χ���� 
 
            }
            Initial_Condition[i][j] = 0 ;  //�Ҳ�����ԭ 
        }
    }
    return false ;  
}
 
void start() 
{
    
    for( int i = 1  ; i <= 9 ; ++i )
        for( int j = 1 ; j <= 9 ; ++j )
            Initial_Condition[i][j] = 0 ;
    int a[10];
    int c;
	for(c=0;c<=9;c++)
		a[c]=c; 
 	a[1]=0;
 	Initial_Condition[1][1] = 1;//ѧ��Ϊ09 ����Ϊ1 
 	int b;
 	for(c=2;c<=9;c++)
 	{
 		b=rand() % 9 + 1;
 		if(a[b]!=0)
 		{
 			Initial_Condition[1][c] =a[b];
 			a[b]=0;
		 }
		 else c--;
	 }
 	
    get_Initial_Condition( 2 , 1 ) ;  
}
 
int main(int argc,char* args[])
{
	
	int M;
	
	freopen("sudoku.txt", "w", stdout);
	
	string str(args[2]);
	int N = std::atoi(str.c_str());
	

	for(M=0;M<N;M++)
	{
		
		start( );
	    for( int i = 1 ; i <= 9 ; ++ i ) 
	    {
	        for( int j = 1 ; j <= 9 ; ++j ) 
	            cout<< Initial_Condition [i][j] <<" " ;
	        cout<<endl;
	        
	    }
	    cout<<endl;
	}
    system("pause");
    
}
