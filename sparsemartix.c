#include<stdio.h>
void totuple(int mat[][10],int m,int n,int t[][3])
{
        int nz=0,k=1,i,j;
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        if(mat[i][j]!=0)
                        {
                                t[k][0]=i;
                                t[k][1]=j;
                                t[k][2]=mat[i][j];
                                nz++;
                                k++;
                        }
                }
        }
        t[0][0]=m;
        t[0][1]=n;
        t[0][2]=nz;
}
void transposetuple(int t1[][3],int tr[][3])
{
        int n=t1[0][2];
        tr[0][0]=t1[0][1];
        tr[0][1]=t1[0][0];
        tr[0][2]=n;
        int col=t1[0][1];
        int q=1,i,j;
        for(i=0;i<col;i++)
        {
                for(j=1;j<=n;j++)
                {
                        if(t1[j][1]==i)
                        {
                                tr[q][0]=t1[j][1];
                                tr[q][1]=t1[j][0];
                                tr[q][2]=t1[j][2];
                                q=q+1;
                        }
                }
        }
}
void display(int t2[][3])
{
        int i,j;
        int n=t2[0][2];
        for(i=0;i<=n;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("%d ",t2[i][j]);
                }
                printf("\n");
        }
}
void sumoft(int tu1[][3],int tu2[][3],int s[][3])
{
        if(tu1[0][0]!=tu2[0][0])
        {
                printf("ADDITION NOT POSSIBLE!!");
        }
        int i,j,m=1,n=1,k=1,nz=0;
        s[0][0]=tu1[0][0];s[0][1]=tu1[0][1];
        for(i=0;i<=tu1[0][0];i++)
        {
                for(j=0;j<tu1[0][1];j++)
                {
                        if(tu1[m][0]==i&&tu1[m][1]==j && tu2[n][0]==i && tu2[n][1]==j)
                        {
                                s[k][0]=i;
                                s[k][1]=j;
                                s[k][2]=tu1[m][2]+tu2[n][2];
                                k++;n++;m++;
                                nz++;
                        }
                        else if(tu1[m][0]==i&&tu1[m][1]==j)
                        {
                                s[k][0]=i;
                                s[k][1]=j;
                                s[k][2]=tu1[m][2];
                                k++;m++;nz++;
                        }
                        else if(tu2[n][0]==i && tu2[n][1]==j)
                        {
                                s[k][0]=i;
                                s[k][1]=j;
                                s[k][2]=tu2[n][2];
                                k++;n++;nz++;
                        }
                }
        }
        s[0][2]=nz;
}
void main()
{
        int i,j;
        int m1[10][10],m2[10][10],m,n,p,q,trtup1[10][3],trtup2[10][3],sum[20][3];
        printf("Enter the row and column of first and second matrix: ");
        scanf("%d %d %d %d",&m,&n,&p,&q);
        printf("Enter the  first matrix: ");
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf("%d",&m1[i][j]);
                }
        }
        printf("Enter the second matrix: ");
        for(i=0;i<p;i++)
        {
                for(j=0;j<q;j++)
                {
                        scanf("%d",&m2[i][j]);
                }
        }
        int tp1[4][3],tp2[5][3];
        totuple(m1,m,n,tp1);
        totuple(m2,p,q,tp2);
        printf("Tuple form of first matrix is\n");
        display(tp1);
        printf("Tuple form of second matrix is\n");
        display(tp2);
        printf("Tuple form of transpose of first matrix is\n");
        transposetuple(tp1,trtup1);
        display(trtup1);
        printf("Tuple form of transpose of second matrix is\n");
        transposetuple(tp2,trtup2);
        display(trtup2);
        sumoft(tp1,tp2,sum);
        printf("Sum of the two matrices in tuple form:\n");
        display(sum);

}
