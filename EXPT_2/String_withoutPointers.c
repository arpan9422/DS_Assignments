#include<stdio.h>
#include<string.h>

//function to find substring
int substring(char str[], char substr[])
{
    int i,j;
      for(i=0; str[i]!='\0';i++ )
      {
        j=0;
        while(str[i+j]=substr[j])
        {
            j++;
            if(substr[j]=='\0')
            {
                return i;
            }
        }
      }
      return -1;//substring not found 
}

//function to check if string is a palindrome
int isPalindrome(char str[])
{
    int i,j;
    for(i=0,j=strlen(str)-1;i<j;i++,j--)
    {
        if(str[i]!=str[j])
        {
            return 0; //not palindrome
        }
    }
    return 1; //palindrome
}

//function to compare two strings
int compareStrings(char str1[], char str2[])
{
    return strcmp(str1, str2);
}

//function to copy one string to another
void copyString(char source[],char destination[])
{
    strcpy(destination, source);
}

//function to reverse a string
void reverseString(char str[])
{
    int i,j;
    char temp;
    for(i=0;j=strlen(str)-1;i<j,i++,j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}
 
int main()
 {
   char str[100], substr[100];
   int choice;
   printf("Enter a string-");
   scanf("%s",str);
   printf("Choose an operation-\n");
   printf("1.Substring\n");
   printf("2.Palindrome\n");
   printf("3.Compare\n");
   printf("4.Copy\n");
   printf("5.Reverse\n");
   
   printf("Enter your choice-");
   scanf("%d",&choice);
   char copy[100];
   char str2[100];

   switch(choice)
   {
    case 1:
    printf("Enter substring to search-");
    scanf("%s",substr);
    int index = substring(str,substr);
    if(index!=-1)
    {
        printf("substring found at index:%d\n",index);
    }
    else
    {
        printf("Substring not found\n");
    }
    break;

    case 2:
    if(isPalindrome(str))
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }
    break;

    case 3:
    
    printf("Enter another string-");
    scanf("%s", str2);
    int result=compareStrings(str,str2);
    if(result<0)
    {
        printf("The first string is smaller.\n");
    }
    else if(result>0)
    {
        printf("The second string is smaller.\n");
    }
    else
    {
        printf("Both strings are equal.\n");
    }
    break;

    case 4:
    
    copyString(str,copy);
    printf("Copied string-%s\n",copy);
    break;

    case 5:
    reverseString(str);
    printf("Reversed string-%s\n",str);
    break;

    default:
    printf("Invalid choice.Please choose a valid operation.\n");
   }
   return 0;
 }
