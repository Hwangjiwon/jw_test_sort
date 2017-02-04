#include <stdio.h>

extern char *value[3];

void init_option(int *arr, int size, char* opt){
    int i;
 
    if(strncmp(opt,"same",4)==0){
        for(i=0;i<size;i++)
          arr[i] = size;
    }
    else if(strncmp(opt,"asc",3)==0){
        for(i=0;i<size;i++)
            arr[i] = i;
    }
    else if(strncmp(opt,"desc",4)==0){
        for(i=0;i<size;i++)
            arr[i] = size-i-1;
    }
    else if(strncmp(opt,"rand",4)==0){
        for(i=0;i<size;i++)
            arr[i] = rand()%size;
    }
    else{
        printf("init_option error\n");
        return;
    }
}
void sort_option(int *arr, int size, char* sort){

    if(strncmp(sort,"ins",3)==0)
        insert_sort(arr,size);
    else if(strncmp(sort,"bub",3)==0)
        bubble_sort(arr,size);
    else if(strncmp(sort,"sel",3)==0)
        select_sort(arr,size);
    else if(strncmp(sort,"heap",4)==0)
        heap_sort(arr,size);
    else if(strncmp(sort,"quick",5)==0)
        quick_sort(arr,size);
	else if(strncmp(sort, "merge",5)==0)
	    merge_sort(arr, 0, size-1);
    else{
         printf("sort_option error\n");
         return;
    }
}

int input_check(int argc, char** argv)
{
	int i,j,k;

	if(argc == 1)
	{	
	    printf("ì‚¬ìš©ë²• ì˜ˆì‹œ: ./test_sort -a bub -o asc -s 1004\n");
		return -1;
	}
	else if (argc % 2 == 0 || 0 == strncmp(argv[argc-1],"-",1)) //argc°¡ È¦¼ö ÀÌ°Å³ª argv[¸¶Áö¸·]ÀÌ ¿É¼ÇÀÏ¶§ error
	{
		printf("ERROR: INPUT THE VALUE\n");
		return -1;
	}
	else
	{
		for (i = 1; i < argc; i++) {
			k = i%2; //k==1 È¦¼ö   k==0 Â¦¼ö
			j = (i+1)%2;
			if (k == 1 && 0 == strncmp(argv[i], "-", 1)) //argv[È¦]ÀÌ ¿É¼ÇÀÎ°¡
			{
				if (j == 0 && 0 != strncmp(argv[i+1], "-", 1)) //argv[Â¦]ÀÌ °ªÀÎ°¡
				{
					if(0==strcmp(argv[i],"-a"))
						value[0] = argv[i+1];
					if(0==strcmp(argv[i],"-o"))
						value[1] = argv[i+1];
					if(0==strcmp(argv[i],"-s"))
						value[2] = argv[i+1];
				}
				else printf("input error\n");
			}
		}
		if (value[0] == NULL) {
			printf("ì‚¬ìš©ë²• ì˜ˆì‹œ: ./test_sort -a bub -o asc -s 1004\n");
			return -1;
		}
		else {
			if (value[1] == NULL) {
				value[1] = "random";
			}
			if (value[2] == NULL) {
				value[2] = "32768";
			}
	    }
	}
	return 0;
}


