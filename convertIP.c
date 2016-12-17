#include <stdio.h>
#include <stdlib.h>

/*
inout: ipstr
output: ip array
*/
int checkipstr( const char* ipstr, char ip[4][4] )
{
  if( ipstr == NULL )
  {
    return -1;
  }
  int i = 0;
  int j = 0;
  for( ; *ipstr != '\0'; ipstr++ )
  {//skip the space in every round
    if( *ipstr == ' ' )
    {
      continue;
    }
    //store the data, if it is not '\0','.',and space
    while( *ipstr != '.' && *ipstr != ' ' && *ipstr != '\0')
    {
      ip[i][j] = *ipstr;
      j++;
      ipstr++;
    }
    //if current ipstr is '.', that means this round is over,we can go to next round
    if( *ipstr == '.')
    {
      ip[i][j] = '\0';
      i++;
      j=0;
      //ipstr++;
      continue;
    }
    //if current ipstr is a space, we need to check the next data [A] that not a space.
    //if the data [A] is a number, return error msg -2, else if it is '.' or end charcter we can go to next round
    else if( *ipstr == ' ' )
    {
      while( *ipstr == ' ' )
        ipstr++;
      if( *ipstr != '.' && *ipstr != '\0' )
        return -2;
      else
      {
        ip[i][j] = '\0';
        i++;
        j=0;
      }
    }
  }

  return 0;
}

void show()
{
  printf("method is : [exename] [ip string]\r\n");
}

int main ( int argc, char* argv[] )
{
  show();
  if( argc == 1 )
  {
    return -1;
  }

  char ip[4][4] = {'0'};
  if( checkipstr(argv[1], ip) != 0 )
  {
    printf("The ip string is not valid,pls check it. The best format is like 172.168.5.1 \r\n");
    return -2;
  }
  else
  {
    printf("IP is %s:%s:%s:%s\r\n",ip[0],ip[1],ip[2],ip[3]);
    //Calculation
    printf("Covert IP from string to unsigned int is : %u \r\n",( ( atoi( ip[0] ) << 24 ) + ( atoi( ip[1] ) << 16 ) + ( atoi( ip[2] ) << 8 ) + ( atoi( ip[3] ))));
  }
  return 0;
}
