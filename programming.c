#include<stdio.h>
struct Contact{
    char name[50];
        char phone[50];
        char email[50];
};
void addcontacts()
{
    FILE *file;
    file=fopen("contactlist.txt","a");
    
    if(file==NULL)
    {
        printf("File doesn't exist.\n");
    }
    else
    {
        fflush(stdin);
        struct Contact contact;
        printf("\nFile is opened...\n");
        
        printf("\nEnter Name: ");
        fgets(contact.name,sizeof contact.name,stdin);

        printf("Enter Phone: ");
        fgets(contact.phone,sizeof contact.phone,stdin);

        printf("Enter Email: ");
        fgets(contact.email,sizeof contact.email,stdin);

        fprintf(file,"%s%s%s\n\n",contact.name,contact.phone,contact.email);

         fclose(file);
         printf("Contact Added Successfully...\n");
    }
}
void displaycontacts()
{
    FILE *file;
    file=fopen("contactlist.txt","r");
    
    
    if(file==NULL)
    {
        printf("File doesn't exist.\n");
    }
    else
    {
        struct Contact contact;
        printf("\nContacts...\n\n");
        
    
        while(fscanf(file," %[^\n] %[^\n] %[^\n]",contact.name,contact.phone,contact.email)!=EOF)
         {
            printf("Name: %s\nPhone: %s\nEmail: %s\n\n",contact.name,contact.phone,contact.email);
         }
         fclose(file);
         
    }
}
int main()
{
    int choise;
    do
{
    printf("\n Contact Mangement System\n");
    printf("1.Add Contact\n");
    printf("2.Display Contact\n");
    printf("3.Exit\n");
    printf("Enter Your Choise: ");
    scanf("%d",&choise);

    switch(choise)
    {
        case 1:
        addcontacts();
        break;
        case 2:
        displaycontacts();
        break;
        case 3:
        printf("Exiting...");
        break;
        default :
        printf("Invalid Choise.Please try again...!");

    }
}
    while(choise!=3);
    
}


