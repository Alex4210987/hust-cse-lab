 #include <stdio.h>
 struct someday{
 	int year;
 	int month;
 	int day;
 };
 int main(void)
 {
    struct someday theday;
    int num=0;
    scanf("%d%d%d",&theday.year,&theday.month,&theday.day);
    int run=0,error=0;
    if(theday.year%4==0){
    	if(theday.year%100==0){
    		if(theday.year%400==0) run=1;
    		else run=0;
		}	
    	else run=1;
	} 
	switch(theday.month){
		case 1:{
			if(theday.day>31) error=1;
			num+=0 ;
			break;
		}
		case 2:{
			if(run) {
				if(theday.day>29) error=1;
			}
			else{
				if(theday.day>28) error=1;
			}
			num+=31 ;
			break;
		}
		case 3:{
			if(theday.day>31) error=1;
			if(run) num+=29;
			else num+=28;
			break;
		}
		case 4:{
			if(theday.day>30) error=1;
			num+=31 ;
			break;
		}
		case 5:{
			if(theday.day>31) error=1;
			num+=30 ;
			break;
		}
		case 6:{
			if(theday.day>30) error=1;
			num+=31 ;
			break;
		}
		case 7:{
			if(theday.day>31) error=1;
			num+=30 ;
			break;
		}
		case 8:{
			if(theday.day>31) error=1;
			num+=31 ;
			break;
		}
		case 9:{
			if(theday.day>30) error=1;
			num+=31 ;
			break;
		}
		case 10:{
			if(theday.day>31) error=1;
			num+=30 ;
			break;
		}
		case 11:{
			if(theday.day>30) error=1;
			num+=31 ;
			break;
		}
		case 12:{
			if(theday.day>31) error=1;
			num+=365-31;
			break;
		}
		default: error=1;
	} 
	num+=theday.day+error;
	if(error) printf("error");
	else printf("%d",num);
	return 0;
 }
