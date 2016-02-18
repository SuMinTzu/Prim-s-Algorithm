#include<stdio.h>
#include<stdlib.h>
#include <string.h>

main(void){
FILE *file1;
     int d[50][50];
     int a[10];
   int i,j,ch,data,first,zz=0,xx,k,yy,y1=0,y2=0;
   int title=0,titlecc=0;
   int tatal=0,p=0;
char c;
for(i=0;i<10;i++)
{
    a[i]=100;                 
}
//open file
file1=fopen("graph3.txt","r");
while((c=getc(file1))!=EOF){
   if(c=='\n'){
        if(titlecc==1){
        first++; }
        data=0;
        ch=0;
        titlecc=1;
        continue;
        }
        if(c=='\t'){
        data++;
        ch=0;
        continue;
        }   
        if(ch==0){
        if(titlecc==1)
        {       
        d[first][data]=c-'0'; 
        }
        else{
        title=c-'0';
        }
        ch=1;
        }else{
        d[first][data]=(c-'0')+d[first][data]*10;
        }
}
fclose(file1);
printf("title=%d\n",title);
for(i=0;i<title;i++){
for(j=0;j<title;j++){
printf("d[%d][%d]=%d\t",i+1,j+1,d[i][j]);
}
printf("\n");
}
printf("=========================\n");
//main

for(k=1;k<9;k++){
    for(i=0;i<title;i++){
        for(j=0;j<title;j++){
                             
            if(d[i][j]==k){
            
            a[zz]=i+1;
            a[zz+1]=j+1;                 
            y1=0;
            y2=0; 
                            
            for(yy=0;yy<8;yy++){
                 if((i+1)==a[yy]){y1=y1+1;}
                 if((j+1)==a[yy]){y2=y2+1;}
                 printf("a[%d]=%d\n",yy,a[yy]);                                      
            }                    
            printf("\n");
            if(y1==2 && y2==2 && a[7]==4){printf("be a ...loop \n\n");}
            else
            {                
                //printf("aa=%d\n\n",aa); 
                          
                zz=zz+2;          
                tatal=tatal+k;
                
                printf("\nd[%d][%d]=%d\n",i+1,j+1,d[i][j]);
                d[j][i]=100;
                d[i][j]=100;               
                printf("tatal=%d\n\n",tatal);
                p=p+1;
                i=title;
                j=title;
                if(p==(title-1)){
                    k=15;
                    printf("END\n.................\n");
                }
            }
            }
                                            
                      
        }
    }
    
}

system("pause");
}
