#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	
	int num1,num2,temp1,i,random1,random2,l,k,b,j,f,num3,choice,runs,waitcust;
	float rand_iat1[5000],rand_st1[5000],l1,l2,iat1[5000],st1[5000],iat,st,mean1,mean2,total1,totavg,totavg1,servertime,arate,srate,totser,ser1[5000],totime,ro;
	float arrival[5000],begin[5000],end[5000],service[5000],wait[5000],idle[5000],total,avg[5000],avg1[5000];
	total=0;
	total1=0;
	totime=0;
	int total2=0;
	waitcust=0;
	printf("--------------------------------------------------------------------------------\n");
	printf("----------------------QUEUING SYSTEM SIMULATION---------------------------------\n");
	printf("--------------------------------------------------------------------------------\n");
	
	
	printf("Enter the mean value for the inter arrival time(exp distribution) \n");
	scanf("%f",&mean1);
	
	printf("Enter the mean value for the service time(exp distribution) \n");
	scanf("%f",&mean2);
	
	
	if(mean1>mean2)
	{printf("error");
	goto abcd;
	}
	
	
	l1=1/mean1;
	l2=1/mean2;
	

	
	
	int count;
	//donot forget to trunc or round off the values before random no assignment
	
	
        printf("Do you want to to run the code based on\n 1.Trial runs\n 2.Total time duration\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
		
		
		case 1: {
		
		
        
        
		printf("enter the number of trials in the experiment \n");//length of experiment based on number of trials
		scanf("%d",&num3);
		printf("enter the no.of runs in each trial\n");
		scanf("%d",&runs);
		for(l=0;l<num3;l++) {
		
		
		i=0;
        count=1;
        
        for(j=0;j<runs;j++) {
        	
        	
		rand_iat1[i]=(float)rand() / (float)RAND_MAX ;
		iat1[i]=(-l1)*log(rand_iat1[i]);
		rand_st1[i]=(float)rand() / (float)RAND_MAX ;
		st1[i]=(-l2)*log(rand_st1[i]);
		
		iat= iat1[i];
		st=st1[i];
		
		
           if(count==1)
                {
                    arrival[0]=0;
                    service[i]=st;
                    begin[i]=0;
                    end[i]=begin[i]+service[i];
                    idle[i]=0;

                    wait[i]=begin[i]-arrival[i];

                    
                    i++;
                    count++;

                }
                else if(count>1)
                {

                    arrival[i]=arrival[i-1]+iat;
                    service[i]=st;
                    if(arrival[i]>end[i-1])
                    {begin[i]=arrival[i];

                    }
					else{
                        begin[i]=end[i-1];
                    }

                    end[i]=begin[i]+service[i];
                    servertime=end[i];
                    idle[i]=begin[i]-end[i-1];
                    

                    wait[i]=begin[i]-arrival[i];
                    if(wait[i]!=0)
                    { ++waitcust;
					}
                    

                    count++;
                    i++;

                }
                //printf("\n%d\n",waitcust);

        }
        totime=totime+end[runs-1];
        
        printf("-------------------------------------------------------------\n");
        printf("arrivaltime  ser_time   begin   wait_time   end   idle_time \n");
        printf("-------------------------------------------------------------\n");
        for(b=0;b<runs;b++)
        {
        	printf("%f   %f   %f   %f   %f   %f \n ",arrival[b],service[b],begin[b],wait[b],end[b],idle[b]);
		}
        
        
        
        
        
        
        
        
             total=0;
            for( k=0;k<runs;k++)
            { total =total+wait[k];

            }
            avg[l] =total/runs;
            

            total1=0;
            for( k=0;k<runs;k++)
            { total1 =total1+idle[k];

            }
            avg1[l] = total1/runs;
            
            total2=0;
            for( k=0;k<runs;k++)
            { total2 =total2+service[k];

            }
            ser1[l]=total2;
            
            

  }
  
        
        totavg=0;
        totavg1=0;
        totser=0;
        for(f=0;f<num3;f++) {
            totavg=totavg+avg[f];
        }
        
            for(f=0;f<num3;f++){
            totavg1=totavg1+avg1[f];
        }
        for(f=0;f<num3;f++){
            totser=totser+ser1[f];
        }
        //printf("%f %f",totser,totime);
            
            printf("\nAverage wait time for the experiment is: %f",totavg/num3);
            printf("\n\n");
            printf("Average idle time for the experiment is: %f",totavg1/num3);
            printf("\n\n");
            printf("The probability of wait is: %f",(float)waitcust/(num3*runs));
            printf("\n\n");
            printf("The probability of idle server is: %f",totavg1/servertime);
            
            
            
            
            printf("\n\nDo you want to the compare with the steady state parameters?0:1 \n");
            scanf("%d",&choice);
            if(choice==1)
            {
            	arate= (num3*runs)/totime;
            	srate= (num3*runs)/totser;
            	//printf("%f%f",arate,srate);
            	ro=arate/srate;
            	printf("\nExpected wait time in the system W=%f",1/(srate-arate));
            	printf("\nTime average number of customers in system L=%f",arate/(srate-arate) );
            	printf("\nExpected wait time in the queue Wq=%f",ro/(srate*(1-ro)));
            	printf("\nTime average number of customers in queue Lq=%f",(ro*ro)/(1-ro) );
            	
            	
			}
			else break;
            
        
    break;
	}
	
	case 2: {
		
		float endtime;
		printf("Enter the time you want the experiment to run for?\n");
		scanf("%f",&endtime);
	    
         int v=0;
         
        
	     i=0;
        count=1;	
        

  while( v!=1)
  {
  	
        
        rand_iat1[i]=(float)rand() / (float)RAND_MAX ;
		iat1[i]=(-l1)*log(rand_iat1[i]);
		rand_st1[i]=(float)rand() / (float)RAND_MAX ;
		st1[i]=(-l2)*log(rand_st1[i]);
		
		iat= iat1[i];
		st=st1[i];
        

            
            
           if(count==1)
                {
                    arrival[0]=0;
                    if(arrival[i]>endtime)
                    { v=1;
					goto abc;
					
				    }
                    service[i]=st;
                    begin[i]=0;
                    end[i]=begin[i]+service[i];
                    idle[i]=0;

                    wait[i]=begin[i]-arrival[i];

                    
                    i++;
                    count++;
                    

                }
                
                else if(count>1)
                {   

                    arrival[i]=arrival[i-1]+iat;
                    if(arrival[i]>endtime)
                    { v=1;
					goto abc;
					
				}
                    service[i]=st;
                    if(arrival[i]>end[i-1])
                    {begin[i]=arrival[i];

                    }
					else{
                        begin[i]=end[i-1];
                    }

                    end[i]=begin[i]+service[i];
                    servertime=end[i-1];
                    idle[i]=begin[i]-end[i-1];

                    wait[i]=begin[i]-arrival[i];
                    if(wait[i]!=0)
                    { ++waitcust;
					}

                    

                    count++;
                    i++;
                    

                }
                
                
                

        }
        abc:
        	
        printf("-------------------------------------------------------------\n");
        printf("arrivaltime  ser_time   begin   wait_time   end   idle_time \n");
        printf("-------------------------------------------------------------\n");
        for(b=0;b<count-1;b++)
        {
        	printf("%f   %f   %f   %f   %f   %f \n ",arrival[b],service[b],begin[b],wait[b],end[b],idle[b]);
		}
		
		
		
		
		
            for( k=0;k<(count-1);k++)
            { total =total+wait[k];

            }
            
            

            
            for( k=0;k<(count-1);k++)
            { total1 =total1+idle[k];

            }
            
  
  
      printf("\nThe average wait  time for the experiment is %f",total/(count-1));
      printf("\n\n");
     printf("The average idle time for the experiment is %f",total1/(count-1));
          printf("\n\n");
            printf("The probability of wait is: %f",(float)waitcust/(count-1));
            printf("\n\n");
            printf("The probability of idle server is: %f",total1/servertime);
  
		
		
		
		
		
		break;
		
	}
	
	
	
    }
    abcd:
    	
    	return 0;
	
	
	
}
