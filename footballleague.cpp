#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct footballteam    //CREATING A STRUCTURE
{
	char name[20];
	int played;
	int won;
	int lost;
	int draw;
	int score;
	struct footballteam *next;
};
typedef struct footballteam team;    //PROVIDING ALIAS NAME
team*head=NULL;
team*newteam;
void addteam(team **head)           //ADDING FOOTBALL LEAGUE DATA
{
	team*newteam=NULL;
	char name[20];
	int played;
	int won;
	int lost;
	int draw;
	int score;
	printf("\nenter teams data:-");
	printf("____");
	printf("\nname:");
	scanf("%s",&name);
	printf("\nNumber of games played: ");  
    scanf("%d",&played);
    printf("\nNumber of games won:");
	scanf("%d",&won);
	printf("\nNumber of games lost: "); 
	scanf("%d",&lost);
	printf("number of games draw:");
	scanf("%d",&draw);
	newteam=(team*)malloc(sizeof(team));
	strcpy(newteam->name,name);
	newteam->played=played;
	newteam->won=won;
	newteam->lost=lost;
    newteam->draw=draw;
    newteam->score=(won*3)+draw;
    
    if(newteam->played!=newteam->won+newteam->lost+newteam->draw){
    	printf("invalid data");
    	free(newteam);
    }
    else
	{
		newteam->next=*head;
	    *head=newteam;
	}
    	

}
void printValuesinText()        //converting the headings to txt file         
{
    FILE *fp;
    fp = fopen("football.txt", "w");
    if (fp == NULL)
    {
        printf("ERROR CREATING THE FILE CHECK AGAIN");
        return;
    }
    fputs("NAME\t",fp);
    fputs("PLAYED\t",fp);
    fputs("WON\t",fp);
    fputs("LOST\t",fp);
    fputs("DRAW\t",fp);
    fputs("SCORE\n",fp);
    fclose(fp);
    
}
void filehandle(team*newteam)                //providing values in heading
{
	FILE*ptr;
	ptr=fopen("football.txt","a");
	if(ptr==NULL)
	{
		printf("the file does not exist");
	}
	while(newteam!=NULL)
	{
		fprintf(ptr,"%s\t",newteam->name);
		fprintf(ptr,"%d\t",newteam->played);
		fprintf(ptr,"%d\t",newteam->won);
		fprintf(ptr,"%d\t",newteam->lost);
		fprintf(ptr,"%d\t",newteam->draw);
		fprintf(ptr,"%d\n",newteam->score);
		newteam=newteam->next;
	}
		
		fclose(ptr);
	
}
void teamlist(team *head)                         //traversing the list
{
	team*trav=head;
	if(head!=NULL)
	{
		printf("\nname\tplayed\twon\tlose\tdraw\tpoints");
		while(trav!=NULL)
		{

			printf("\n%s\t%d\t%d\t%d\t%d\t%d\n",trav->name,trav->played,trav->won, trav->lost,trav->draw,trav->score);
			trav=trav->next;
		}
	}	
	else
	{
		printf("invalid data print data properly");
	}
}
int main()
{
	int ch;
	printValuesinText();
	team *temp=head;
	while(temp!=NULL)
	{
		filehandle(temp);
		temp=temp->next;
	}
	while(1)
	{
		printf("\t______\t");
		printf("\n\t\tenter 1 to add team");
		printf("\n\t\tenter 2 to print data");
		printf("\n\t\tenter 3 to exit list");
		printf("\n\t______\t");
		printf("\n\tenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:addteam(&head);
			break;
			case 2:teamlist(head);
			break;
			case 3:filehandle(head);
			       break;
			default:printf("\nWRONG CHOICE\n");
		}
	}
	return 0;
}
