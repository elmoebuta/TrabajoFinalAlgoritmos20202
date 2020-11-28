#include<iostream>
#include<cstdlib>
#include<vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;
const int n = 17;
bool validacion(int &x1,int  &y1,int  &x2,int  &y2,int  &x3,int  &y3,int  &x4,int  &y4,int  &x5,int  &y5,int  &x6,int &y6,int matrizp[n][n])
{
	bool salida=true;
	for(int i=0;i<n;i++)
	{
		int contador=0;
		for(int j=0;j<n;j++)
	{
		if(matrizp[i][j]==3)
		{
			contador=contador+1;
		}
		if((contador==17)||(contador==5)||(contador==7))
		
		{
			
			salida=false;
		
		}
	}
	}
	return salida;
	
}
void creartablero(char matriz[n][n],int matrizp[n][n])
{
	
	
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
				if(	matrizp[i][j]==3)
				{
					matriz[i][j]='-';
				}
				else
				{
					matriz[i][j]='*';
				}
				
			}
			
	
	}
}
void creartablerop(char matriz[n][n], int matrizp[n][n])
{
	
	
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
				if (matriz[i][j]=='*')
				{
					matrizp[i][j]=1;
				}
				else if(matriz[i][j]=='-')
				{
					matrizp[i][j]=3;
				}
				else
				{
					matrizp[i][j]=0;
				}
				
			}
			
	
	}
}
void iatres(int &tx,int &ty,int &tdx,int &tdy,char tres,int tablerop[n][n],char tablero[n][n])
{

			if(tablerop[tx+1][ty]==1)
			{
				//creartablerop(tablero,tablerop);
				tx=tx+2;
				tablerop[tx][ty]=2;
				
				tablero[tx][ty]='2';
				
				//creartablerop(tablero,tablerop);
			}
			
			else if (tablerop[tx][ty+1]==1)
			{
				
				
				ty=ty+2;
				tablerop[tx][ty]=2;
				tablero[tx][ty]='2';
				//creartablerop(tablero,tablerop);
				
			}
				else if (tablerop[tx][ty-1]==1)
			{
				//creartablerop(tablero,tablerop);
				ty=ty-2;
				tablerop[tx][ty]=2;
				
				tablero[tx][ty]='2';
				//creartablerop(tablero,tablerop);
			}
			else if (tablerop[tx-1][ty]==1)
			{
				//creartablerop(tablero,tablerop);
				tx=tx-2;
				tablerop[tx][ty]=2;
				
				tablero[tx][ty]='2';
				//creartablerop(tablero,tablerop);
			}
		
			else if(tablerop[tx+1][ty]==2)
			{
				//creartablerop(tablero,tablerop);
				tx=tx+2;
				tablerop[tx][ty]=0;
				
				tablero[tx][ty]='2';
			//	creartablerop(tablero,tablerop);
				
			}
			else if (tablerop[tx][ty+1]==2)
			{
				//creartablerop(tablero,tablerop);
				ty=ty+2;
				tablerop[tx][ty]=0;
				
				tablero[tx][ty]='2';
				//creartablerop(tablero,tablerop);
			}
			else if (tablerop[tx-1][ty]==2)
			{
				//creartablerop(tablero,tablerop);
				tx=tx-2;
				tablerop[tx][ty]=0;
				
				tablero[tx][ty]='2';
				//creartablerop(tablero,tablerop);
			}
			else if (tablerop[tx][ty-1]==2)
			{
				//creartablerop(tablero,tablerop);
				ty=ty-2;
				tablerop[tx][ty]=0;
				
				tablero[tx][ty]='2';
				//creartablerop(tablero,tablerop);
			}
			creartablerop(tablero,tablerop);

}
void ganador(char tablero[n][n],bool &flag)
{
	if ((tablero[0][0]=='1')||(tablero[0][1]=='1')||(tablero[0][2]=='1')||(tablero[0][3]=='1')||(tablero[0][4]=='1')||(tablero[0][5]=='1')||(tablero[0][6]=='1')||(tablero[0][7]=='1')||(tablero[0][8]=='1')
	||(tablero[0][9]=='1')||(tablero[0][10]=='1')||(tablero[0][11]=='1')||(tablero[0][12]=='1')||(tablero[0][13]=='1')||(tablero[0][14]=='1')||(tablero[0][15]=='1')||(tablero[0][16]=='1'))
	{
		flag=false;
		system("CLS");
		cout<<"gana uno"<<endl;
	}
	else if((tablero[16][0]=='2')||(tablero[16][1]=='2')||(tablero[16][2]=='2')||(tablero[16][3]=='2')||(tablero[16][4]=='2')||(tablero[16][5]=='2')||(tablero[16][6]=='2')||(tablero[16][7]=='2')||(tablero[16][8]=='2')
	||(tablero[16][9]=='2')||(tablero[16][10]=='2')||(tablero[16][11]=='2')||(tablero[16][12]=='2')||(tablero[16][13]=='2')||(tablero[16][14]=='2')||(tablero[15][16]=='2')||(tablero[16][16]=='2'))
	{
		flag=false;
		system("CLS");
		cout<<"gana dos"<<endl;
	}
}
void pintartablero(char matriz[n][n])
{
	
	
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
				
				cout<<matriz[i][j];
			}
			cout<<endl;
	
	}
}
void pintartablerop(int matrizp[n][n])
{
	
	
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
				
				cout<<matrizp[i][j];
			}
			cout<<endl;
	
	}
}
int bloque(char matriz[n][n], int matrizp[n][n],int &contador,bool &procede)
{
	int matrizaux[n][n];
	bool flag=true;
	contador=contador+1;
	if (contador<11)
	{
		int auxx=-1;
	int auxy=-1;
	int auxx2=-1;
	int auxy2=-1;
		for(int i=0;i<n;i++)
	   {
			for(int j=0;j<n;j++)
			{
				
				if (matriz[i][j]=='1')
				{
					auxx=i;
					auxy=j;
					
				}
				
				if (matriz[i][j]=='2')
				{
					auxx2=i;
					auxy2=j;
					
				}
			}
     	}
		
			
		bool flag1=true;
    	if (contador==1)
    	{
    		if((auxy==auxy2))	
		{
			int azar=rand()%2;
			if(azar==1)
			{
				matrizp[auxx-1][auxy]=3;
				matrizp[auxx-1][auxy+1]=3;
				matrizp[auxx-1][auxy+2]=3;
				matriz[auxx-1][auxy]='-';
				matriz[auxx-1][auxy+1]='-';
				matriz[auxx-1][auxy+2]='-';
				
			}
			else
			{
				matrizp[auxx-1][auxy]=3;
				matrizp[auxx-1][auxy-1]=3;
				matrizp[auxx-1][auxy-2]=3;
				matriz[auxx-1][auxy]='-';
				matriz[auxx-1][auxy-1]='-';
				matriz[auxx-1][auxy-2]='-';
			}
		
	
    	}
    	else if((auxy<auxy2)&&(auxy==0))
    	{
    		matrizp[auxx-1][auxy]=3;
			matrizp[auxx-1][auxy+1]=3;
			matrizp[auxx-1][auxy+2]=3;
			matriz[auxx-1][auxy]='-';
			matriz[auxx-1][auxy+1]='-';
			matriz[auxx-1][auxy+2]='-';
		}
    		   		
    	else if((auxy<auxy2)&&(auxy!=0))
    	{
    			matrizp[auxx-1][auxy]=3;
			matrizp[auxx-1][auxy-1]=3;
			matrizp[auxx-1][auxy-2]=3;
			matriz[auxx-1][auxy]='-';
			matriz[auxx-1][auxy-1]='-';
			matriz[auxx-1][auxy-2]='-';
		}	
		else if((auxy>auxy2)&&(auxy==0))
    	{
    				matrizp[auxx-1][auxy]=3;
			matrizp[auxx-1][auxy-1]=3;
			matrizp[auxx-1][auxy-2]=3;
			matriz[auxx-1][auxy]='-';
			matriz[auxx-1][auxy-1]='-';
			matriz[auxx-1][auxy-2]='-';
		}
    		   		
    	else if((auxy>auxy2)&&(auxy!=0))
    	{
    		matrizp[auxx-1][auxy]=3;
			matrizp[auxx-1][auxy+1]=3;
			matrizp[auxx-1][auxy+2]=3;
			matriz[auxx-1][auxy]='-';
			matriz[auxx-1][auxy+1]='-';
			matriz[auxx-1][auxy+2]='-';
		}	
    		flag1=false;
		}
		for(int i=0;i<n;i++)
	    {
			for(int j=0;j<n;j++)
			{
				
				matrizaux[i][j]=matrizp[i][j];
			}
			
	
    	}
    	
    	while(flag1)
    	{
    		
    		if(contador>1)
		    {
			if(matrizaux[auxx-1][auxy]!=3)
			    {
				if((matrizaux[auxx-1][auxy+1]!=3)&&(matrizaux[auxx-1][auxy-1]!=3)&&(auxy!=0)&&(auxy!=16))
				{
					if(auxy>=auxy2)
					{
						int ewe=auxx-1;
		                 	int ewey1=auxy+1;
		                 	int ewey2=auxy+2;
		                 		matrizaux[auxx-1][auxy]=3;
		                	matrizaux[auxx-1][auxy+1]=3;
		                 	matrizaux[auxx-1][auxy+2]=3;
						flag=validacion(ewe,auxy,ewe,ewey1,ewe,ewey2,ewe,auxy,ewe,ewey1,ewe,ewey2,matrizaux);
						if(flag)
						{
							//////////////////
								matrizp[auxx-1][auxy]=3;
		                	matrizp[auxx-1][auxy+1]=3;
		                 	matrizp[auxx-1][auxy+2]=3;
		                	matriz[auxx-1][auxy]='-';
			                matriz[auxx-1][auxy+1]='-';
		                 	matriz[auxx-1][auxy+2]='-';
		                 	
						}
						
		                 	
		                 	
		                 	flag1=false;
					}
					else
					{
						int ewe=auxx-1;
		                 	int ewey1=auxy-1;
		                 	int ewey2=auxy-2;
		                 	matrizaux[auxx-1][auxy]=3;
		                	matrizaux[auxx-1][auxy-1]=3;
		                 	matrizaux[auxx-1][auxy-2]=3;
		                 	flag=validacion(ewe,auxy,ewe,ewey1,ewe,ewey2,ewe,auxy,ewe,ewey1,ewe,ewey2,matrizaux);
		                 	if(flag)
						{
						matrizp[auxx-1][auxy]=3;
		                	matrizp[auxx-1][auxy-1]=3;
		                 	matrizp[auxx-1][auxy-2]=3;
		                	matriz[auxx-1][auxy]='-';
			                matriz[auxx-1][auxy-1]='-';
		                 	matriz[auxx-1][auxy-2]='-';
		                 }
		                 	flag1=false;
					}
				}
				else if((matrizaux[auxx-1][auxy+1]!=3)&&(auxy==0))
				{
						int ewe=auxx-1;
		                 	int ewey1=auxy+1;
		                 	int ewey2=auxy+2;
		                 	matrizaux[auxx-1][auxy]=3;
		                	matrizaux[auxx-1][auxy+1]=3;
		                 	matrizaux[auxx-1][auxy+2]=3;
		                 	flag=validacion(ewe,auxy,ewe,ewey1,ewe,ewey2,ewe,auxy,ewe,ewey1,ewe,ewey2,matrizaux);
		                 	if(flag)
		                 	{
		                 		matrizp[auxx-1][auxy]=3;
		                	matrizp[auxx-1][auxy+1]=3;
		                 	matrizp[auxx-1][auxy+2]=3;
		                	matriz[auxx-1][auxy]='-';
			                matriz[auxx-1][auxy+1]='-';
		                 	matriz[auxx-1][auxy+2]='-';
							 }
						
		                 
		                 	flag1=false;
				}
				else if((matrizaux[auxx-1][auxy-1]!=3)&&(auxy==16))
				{
						int ewe=auxx-1;
		                 	int ewey1=auxy-1;
		                 	int ewey2=auxy-2;
		                 	matrizaux[auxx-1][auxy]=3;
		                	matrizaux[auxx-1][auxy-1]=3;
		                 	matrizaux[auxx-1][auxy-2]=3;
		                 	flag=validacion(ewe,auxy,ewe,ewey1,ewe,ewey2,ewe,auxy,ewe,ewey1,ewe,ewey2,matrizaux);
		                 	if(flag)
		                 	{
		                 		matrizp[auxx-1][auxy]=3;
		                	matrizp[auxx-1][auxy-1]=3;
		                 	matrizp[auxx-1][auxy-2]=3;
		                	matriz[auxx-1][auxy]='-';
			                matriz[auxx-1][auxy-1]='-';
		                 	matriz[auxx-1][auxy-2]='-';
							 }
					
		                 
		                 	flag1=false;
				}
				else if((matrizaux[auxx-1][auxy+1]==3)&&(matrizaux[auxx-1][auxy-1]==3)&&(auxy!=0)&&(auxy!=16)&&(matrizaux[auxx-2][auxy+1]!=3)&&(matrizaux[auxx-2][auxy-1]!=3))
				{
					int ewe=auxx-3;
		                 	int ewey1=auxy-1;
		                 	int ewey2=auxy+1;
		                 	matrizaux[auxx-2][auxy]=3;
		                	matrizaux[auxx-3][auxy-1]=3;
		                 	matrizaux[auxx-3][auxy+1]=3;
		                 	flag=validacion(ewe,auxy,ewe,ewey1,ewe,ewey2,ewe,auxy,ewe,ewey1,ewe,ewey2,matrizaux);
		                 	if(flag)
		                 	{
		                 		matrizp[auxx-2][auxy]=3;
		                	matrizp[auxx-3][auxy-1]=3;
		                 	matrizp[auxx-3][auxy+1]=3;
		                	matriz[auxx-3][auxy]='-';
			                matriz[auxx-3][auxy-1]='-';
		                 	matriz[auxx-3][auxy+1]='-';
							 }
					
		                 	
		                 	flag1=false;
		                 	
				}
				
				
			    }
			    else if((matrizaux[auxx-1][auxy]==3))
			    
			    {
			    	if ((matrizaux[auxx][auxy+1]!=3)&&(matrizaux[auxx+2][auxy+1]!=3))
			    	{
			    			int ewe=auxy-1;
		                 	int ewex1=auxx+1;
		                 	int ewex2=auxx+2;
		                 	matrizaux[auxx][auxy-1]=3;
		                	matrizaux[auxx+1][auxy-1]=3;
		                 	matrizaux[auxx+2][auxy-1]=3;
		                 	flag=validacion(auxx,ewe,ewex1,ewe,ewex2,ewe,auxx,ewe,ewex1,ewe,ewex2,ewe,matrizaux);
		                 	if(flag)
		                 	{
							 
			    			matrizp[auxx][auxy-1]=3;
		                	matrizp[auxx+1][auxy-1]=3;
		                 	matrizp[auxx+2][auxy-1]=3;
		                	matriz[auxx][auxy-1]='-';
			                matriz[auxx+1][auxy-1]='-';
		                 	matriz[auxx+2][auxy-1]='-';
		                 	}
		                 
		                 	flag1=false;
					}
					else if ((matrizaux[auxx][auxy+1]!=3)&&(matrizaux[auxx+2][auxy+1]==3)&&(matrizaux[auxx-2][auxy+1]!=3))
					{
						int ewe=auxy-1;
		                 	int ewex1=auxx-1;
		                 	int ewex2=auxx-2;
		                 	matrizaux[auxx][auxy-1]=3;
		                	matrizaux[auxx-1][auxy-1]=3;
		                 	matrizaux[auxx-2][auxy-1]=3;
		                 	flag=validacion(auxx,ewe,ewex1,ewe,ewex2,ewe,auxx,ewe,ewex1,ewe,ewex2,ewe,matrizaux);
		                 	if(flag)
		                 	{
							 
			    			matrizp[auxx][auxy-1]=3;
		                	matrizp[auxx-1][auxy-1]=3;
		                 	matrizp[auxx-2][auxy-1]=3;
		                	matriz[auxx][auxy-1]='-';
			                matriz[auxx-1][auxy-1]='-';
		                 	matriz[auxx-2][auxy-1]='-';
		                    }
		                 	flag1=false;
					}
					else if((matrizaux[auxx][auxy-1]!=3)&&(matrizaux[auxx+2][auxy-1]!=3))
					{
						int ewe=auxy-1;
		                 	int ewex1=auxx+1;
		                 	int ewex2=auxx+2;
		                 	matrizaux[auxx][auxy+1]=3;
		                	matrizaux[auxx+1][auxy+1]=3;
		                 	matrizaux[auxx+2][auxy+1]=3;
		                 	flag=validacion(auxx,ewe,ewex1,ewe,ewex2,ewe,auxx,ewe,ewex1,ewe,ewex2,ewe,matrizaux);
		                 	if(flag)
		                 	{
							 
						matrizp[auxx][auxy-1]=3;
		                	matrizp[auxx+1][auxy+1]=3;
		                 	matrizp[auxx+2][auxy+1]=3;
		                	matriz[auxx][auxy+1]='-';
			                matriz[auxx+1][auxy+1]='-';
		                 	matriz[auxx+2][auxy+1]='-';
		                 	}
		                 	
		                 	flag1=false;
					}
					else if((matrizaux[auxx][auxy-1]!=3)&&(matrizaux[auxx+2][auxy-1]==3)&&(matrizaux[auxx-2][auxy-1]!=3))
					{
						 int ewe=auxy+1;
		                 	int ewex1=auxx-1;
		                 	int ewex2=auxx-2;
		                 	matrizaux[auxx][auxy+1]=3;
		                	matrizaux[auxx-1][auxy+1]=3;
		                 	matrizaux[auxx-2][auxy+1]=3;
		                 	flag=validacion(auxx,ewe,ewex1,ewe,ewex2,ewe,auxx,ewe,ewex1,ewe,ewex2,ewe,matrizaux);
		                 	if(flag)
		                 	{
		                 			matrizp[auxx][auxy+1]=3;
		                	matrizp[auxx-1][auxy+1]=3;
		                 	matrizp[auxx-2][auxy+1]=3;
		                	matriz[auxx][auxy+1]='-';
			                matriz[auxx-1][auxy+1]='-';
		                 	matriz[auxx-2][auxy+1]='-';
							 }
					
		                   
		                 	flag1=false;
					}
				}
				else
				{
					flag1=false;
				}
		    }
		}
	if (flag==false)
	{
		cout<<flag<<endl;
		procede=false;
	}
	}
	else
	{
		
	}
    	cout<<contador<<endl;
	return contador;
	
}





int main()
{
	char tablero[n][n];
	int tablerop[n][n];
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
				tablero[i][j]='*';
				tablerop[i][j]=1;
				
			}
			
	
	}
	
	srand(time(NULL));
	
	char uno, dos, tres, cuatro;
	uno='1'; dos='2';
	int ux=16;
	int uy=8;
	int udx=0;
	int udy=0;
	int azar;

	int tx=0;
	int ty=8;
	int tdx=0;
	int tdy=0;
	int contador=0;
	tablero[ux][uy]=uno;
	tablero[tx][ty]=dos;
	bool flag=true;
	char mov;
	pintartablero(tablero);
	pintartablerop(tablerop);
	bool procede=true;
	while(flag==true)
	{
		cin>>mov;
	
		if (mov=='w')
		{
			if(tablerop[ux-udx-1][uy+udy]==3)
			{
				cout<<"jaja no :v"<<endl;
			}
			else
			{
				system("CLS");
			
			
			udx=udx+2;
			creartablero(tablero,tablerop);
			tablero[ux-udx][uy+udy]=uno;
			
			creartablerop(tablero,tablerop);
			//pintartablerop(tablerop);
			azar=rand()%3;
			if ((azar==0)||(azar==1))
			{
				iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
			}
			else
			{
				if (contador>10)
				{
				iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
		    	}
		    	else
		    	{tablerop[tx][ty]=2;
				
				tablero[tx][ty]='2';
				bloque(tablero,tablerop,contador,procede);
					if (procede==false)
				{
					tablerop[tx][ty]=1;
				
				tablero[tx][ty]='*';
					iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
					procede=true;
				}
				}
			}
			pintartablero(tablero);
			pintartablerop(tablerop);
			ganador(tablero,flag);
			//pintartablerop(tablerop);
			}
			
			
		}
		else if(mov =='s')
		{
			if(tablerop[ux-udx+1][uy+udy]==3)
			{
				cout<<"jaja no :v"<<endl;
			}
			else
			{
			
			system("CLS");
			
			udx=udx-2;
			creartablero(tablero,tablerop);
			tablero[ux-udx][uy+udy]=uno;

			
			creartablerop(tablero,tablerop);
			//pintartablerop(tablerop);
			azar=rand()%3;
			if ((azar==0)||(azar==1))
			{
				iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
			}
			else
			{
				if (contador>10)
				{
				iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
		    	}
		    	else
		    	{tablerop[tx][ty]=2;
				
				tablero[tx][ty]='2';
				bloque(tablero,tablerop,contador,procede);
					if (procede==false)
				{
					tablerop[tx][ty]=1;
				
				tablero[tx][ty]='*';
					iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
					procede=true;
				}
				}
				
			}
			
			pintartablero(tablero);
			
			ganador(tablero,flag);
			//pintartablerop(tablerop);
			}
		}
		else if(mov =='a')
		{
			if(tablerop[ux-udx][uy+udy-1]==3)
			{
				cout<<"jaja no :v"<<endl;
			}
			else
			{
			system("CLS");
			
			udy=udy-2;
			creartablero(tablero,tablerop);
			tablero[ux-udx][uy+udy]=uno;
			
			creartablerop(tablero,tablerop);
			//pintartablerop(tablerop);
			azar=rand()%3;
			if ((azar==0)||(azar==1))
			{
				iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
			}
			else
			{
				if (contador>10)
				{
				iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
		    	}
		    	else
		    	{tablerop[tx][ty]=2;
				
				tablero[tx][ty]='2';
				bloque(tablero,tablerop,contador,procede);
					if (procede==false)
				{
					tablerop[tx][ty]=1;
				
				tablero[tx][ty]='*';
					iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
					procede=true;
				}
				}
			}
			pintartablero(tablero);
			ganador(tablero,flag);
			//pintartablerop(tablerop);
		}
		}
		else if(mov =='d')
		{
			if(tablerop[ux-udx][uy+udy+1]==3)
			{
				cout<<"jaja no :v"<<endl;
			}
			else
			{
			system("CLS");
			
			udy=udy+2;
		    creartablero(tablero,tablerop);
			tablero[ux-udx][uy+udy]=uno;
			
			creartablerop(tablero,tablerop);
			//pintartablerop(tablerop);
			azar=rand()%3;
			if ((azar==0)||(azar==1))
			{
				iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
			}
			else
			{
					if (contador>10)
				{
				iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
		    	}
		    	else
		    	{tablerop[tx][ty]=2;
				
				tablero[tx][ty]='2';
				bloque(tablero,tablerop,contador,procede);
				if (procede==false)
				{
					tablerop[tx][ty]=1;
				
				tablero[tx][ty]='*';
					iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
					procede=true;
				}
				}
			}
			pintartablero(tablero);
			ganador(tablero,flag);
			//pintartablerop(tablerop);
		}
		}
		else if (mov=='b')
		{
			int c1,c2,c3,c4,c5,c6;
			cout<<"x1,y1 :"<<endl;
			cin>>c1;
			cin>>c2;
			cout<<"x2,y2 :"<<endl;
			cin>>c5;
			cin>>c6;
			c3=(c1+c5)/2;
			c4=(c2+c6)/2;
			tablerop[c1][c2]=3;
			tablerop[c3][c4]=3;
			tablerop[c5][c6]=3;
			tablero[c1][c2]='-';
			tablero[c3][c4]='-';
			tablero[c5][c6]='-';
			
			system("CLS");
			creartablerop(tablero,tablerop);
			
			
				azar=rand()%3;
			if ((azar==0)||(azar==1))
			{
				iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
			}
			else
			{
					if (contador>10)
				{
				iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
		    	}
		    	else
		    	{tablerop[tx][ty]=2;
				
				tablero[tx][ty]='2';
				bloque(tablero,tablerop,contador,procede);
				if (procede==false)
				{
					tablerop[tx][ty]=1;
				
				tablero[tx][ty]='*';
					iatres(tx,ty,tdx,tdy,tres,tablerop,tablero);
					procede=true;
				}
				}
			}
			pintartablero(tablero);
			ganador(tablero,flag);
		}
		else
		{
			
		}
	}
	
	
	
}
