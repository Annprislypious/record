#include<iostream>
using namespace std;
class matrix
{
	public:
		int a[50][50],i,j,k;
		int r,c;
		void read_size()
		{
			cout<<"Enter row size and column size:";
			cin>>r>>c;
		}
		void read()
		{
			cout<<"Enter values:";
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					cin>>a[i][j];
				}
			}
		}
		void display()
		{

			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					cout<<a[i][j]<<"     ";
				}
				cout<<"\n";

			}
		}
		matrix operator +(matrix);
		matrix operator *(matrix);
};
matrix matrix::operator +(matrix ob)
{
	matrix temp;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			temp.a[i][j]=0;
			temp.a[i][j]=a[i][j]+ob.a[i][j];

		}
		temp.r=r;
		temp.c=c;
	}
	return (temp);
}
matrix  matrix::operator *(matrix m)
{
	matrix temp2;
          temp2.r=r;
          temp2.c=m.c;
	for(i=0;i<temp2.r;i++)
	{

		for(j=0;j<temp2.c;j++)
		{
			temp2.a[i][j]=0;
			for (int k=0;k<c;k++)
			{

				temp2.a[i][j]=temp2.a[i][j]+(a[i][k]*m.a[k][j]);
			}
		}
	}
	return temp2;
}

main()
{
	matrix m1,m2,m3,m4;
	m1.read_size();
	m2.read_size();
	m1.read();
	m2.read();
	cout<<"First matrix is:\n";
	m1.display();
	cout<<"Second matrix is:\n";
	m2.display();
	if((m1.r==m2.r)&&(m1.c==m2.c))
	{
		m3=m1+m2;
		cout<<"SUM IS:\n";
		m3.display();
	}
	else

	{
		cout<<"Addition not possible\n";
	} 

	if(m1.r==m2.c)
	{
		m4=m1*m2;
		cout<<"PRODUCT OF TWO MATRIX IS:\n";
		m4.display();

	}
	else
	{
		cout<<"Multiplication Not possible\n";

	}
}



