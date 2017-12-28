
#include <iostream>
#include <windows.h>
 
int minimum (int m[], int k, char **str);
void textout(char filename[],char **str,int strl,int *minwords,int strlmw);
int checkmin(int i,int *minwords,int strlmw);
int fileout(char filename[],char *str);
void setcolor(short color);
 
int main () {
  FILE * pFile;
  long lSize;
  char * buffer;
  size_t result;
  char filename[255];
 
  setcolor(4);
  std::cout << "Enter file to open (file.dat):" << std::endl;
  setcolor(7);
  std::cin >> filename;
  pFile = fopen ( filename , "r" ); 
  if (pFile==NULL) {
      std::cout << "Read error. Can't open file!" << std::endl;
      system("pause");
      return 0;
  }
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  if (lSize > 1000){
      std::cout << "Read error. Length > 1000." << std::endl;
        fclose(pFile);
    }
  rewind(pFile);
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
 

  result = fread (buffer,1,lSize,pFile);
  buffer[result] = 0;
    int j=0,c=0;

    while (buffer[c] != '\0')
    {
        if (buffer[c] != '\n')
        {
            j++;
        } else
            j=0;
        if (j > 70){
            std::cout << "Length of string > 70!" << std::endl;
            system("pause");
            return 0;
        }
        c++;
    }
  setcolor(5);
  printf("%s\n",buffer);
  setcolor(7);
  char * pch;
  int i=0,counterspace=0,w=0;
  char **shortarr;
  int *wordlen = new int [strlen(buffer)];
  while (true)
  {
      if (buffer[w] == ' ' || buffer[w] == '\n')
      {
counterspace++; 
      }
      if (buffer[w] == '\0')
      {
          shortarr = new char*[counterspace];
          pch = strtok(buffer," ");
          while (pch != NULL)
          {shortarr[i] = pch;
    wordlen[i] = (int)strlen(pch);
              pch = strtok(NULL, " ");
              i++;
          }       
          minimum(wordlen,i,shortarr); 
          break;
      }
      w++;
  }
  // terminate
  fclose (pFile);
   system("pause");
  return 0;
}
int minimum (int m[], int k,char **str)
{
 int index=0;
 int min=m[0];
 int countmin=0;
 int j=0;
 char filenameout[255];
 for (int i=0; i<k; i++)
 {
     if (m[i]<min)
     {
         min=m[i];
     }
 }
 for (int i=0; i<k; i++){
     if (m[i] == min)
     {
countmin++; 
     }
 }
 int *minwords = new int[countmin];
 for (int i=0;i<k;i++)
 {
     if (m[i] == min)
     {
minwords[j] = i; 
        j++;
     }
 }
 setcolor(4);
 std::cout << "Enter filename to save: " << std::endl;
 setcolor(7);
 std::cin >> filenameout;
 textout(filenameout,str,k,minwords,countmin);
 delete [] minwords;
 return 0;
}
void textout(char filename[],char **str,int strl,int *minwords,int strlmw)
{
    system("cls");
    for (int i=0;i<strl;i++)
    {
if (checkmin(i,minwords,strlmw)) 
        {
            setcolor(2);
            std::cout << str[i] << " ";
            fileout(filename,str[i]);
        } else {
            setcolor(7);
            std::cout << str[i] << " ";
        }
    }
    std::cout << std::endl;
}
 
int checkmin(int i,int *minwords,int strlmw)
{

    int counter = 0;
    for (int j=0;j<strlmw;j++)
    {
        if (i==minwords[j])
            counter++;
    }
    if (counter > 0) 
    {
        DWORD dwR;
        HANDLE hStdIn;
        _INPUT_RECORD IR;
        AllocConsole();
        hStdIn = GetStdHandle(STD_INPUT_HANDLE);
        while(TRUE) {
            ReadConsoleInput(hStdIn, &IR, 1, &dwR);
            if((IR.EventType == KEY_EVENT)&&(IR.Event.KeyEvent.bKeyDown)) 
                {
if(IR.Event.KeyEvent.wVirtualScanCode!=1) 
return 1;
            }//if
        }//
    } else {
        return 0;
    }
}
int fileout(char filename[],char *str)
{
    FILE * pFileOut;
    pFileOut = fopen ( filename , "a" );
    fprintf(pFileOut,"%s\n",str);
    fclose (pFileOut);
    return 0;
}
void setcolor(short color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
