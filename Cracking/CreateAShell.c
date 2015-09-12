/*****************************************************************/
//
//"Creat a shell"
//

/*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <unistd.h>


#define MAXHISTORY 999
#define PATH_NO 10
#define CMDLENGTH 100

/************************Global Variables List*************************/
int argc;
char * paras[4];    // command paras
char * mypaths[PATH_NO];   //environmental variable MYPATH
char * History[MAXHISTORY];//Cmd History, we only store MAXHISTORY here
int history_cnt=0;//how many cmd in the history list including the last one.
/**********************************************************************/ 



/*****************************Function List****************************/
char * exec_Ah(char *cmd);//The function to deal with the cmd with a '!'
void cmdline_to_argv( char  *command );//Translation the cmdline into a group of arguments
void analyze_thepath( char *MYPATH);//Parsing the PATH and prepare to search whether the command exists
int valid_cmd(char *cmd );//check whether the command exists
int exec_cmd(char *cmd);//Exec the command using a child process
void handler( int sig );//hold on the parent process while the child process is on the way
int changedir( char *dir );//Change the directory
void deletes( );//delete arguments
void terminate();//Deal with the exit and quit command.
/**********************************************************************/ 

int main()
{
	char *MYPATH = getenv("MYPATH"); // read envrionmental variable MYPATH
	char *HOME = getenv("HOME");
    int len=strlen(HOME);

    if( MYPATH == NULL )
	{
		//fprintf( stderr, "MYPATH not found, we are using defalt PATH\n");
		MYPATH="/bin:";
        //return 1;
	}
	char c = '\0';
	char cmd[100];
	char *command = ( char * ) malloc ( 128*sizeof( char ) );
	printf("Welcome to myshell\n");
	printf("($MYPATH is %s)\n", MYPATH);
	printf("---| ");
	analyze_thepath(MYPATH);
	while ( 1 )
	{
		c = getchar(); // catch input from keyboard
		if ( c != '\n')
		{
            if(c=='~')//Here we just replace ~ with home address
           {
            strncat(command, HOME, len);
            //puts(command);
           }
            else
			strncat(command, &c , 1);
		}
		else  // when an Enter is from the keyboard
		{
			if ( strlen( command ) > 1) //There is some command
			{
			c = '\0';
			strncat(command, &c, 1);
            History[history_cnt]=(char *) malloc (100*sizeof(char));
            strcpy(History[history_cnt],command);
            //printf("%s",History[history_cnt]);
            //printf("--\n");
            history_cnt++;
			cmdline_to_argv( command );  // convert command line to argv[]
			strcpy( cmd, paras[0] );  // get the command
			if( strcmp( cmd, "exit") ==0 || strcmp(cmd,"quit")==0) // Exit myshell
			terminate();
			if( strcmp( cmd, "cd") ==0)  // command cd to change directory
			{
				changedir( paras[1] );
			}
			else if ( valid_cmd( cmd )== 0 ) // the command is valid
			{
				int i;
				int block = 1;
				for( i=0; paras[i] != NULL && strcmp(paras[i], "&") !=0; ) // che position of '&'
				{ i++; }
				if( i == argc && argc>0 ) // '&' is in the end of a command line
				{
					block = 0;
					paras[argc] = NULL;
					free( paras[argc] );
					argc = argc - 1;
				}
				else if ( i < argc ) // Wrong usage of '&'
				{
					printf("Usage of &: at the end of a command line\n");
					return 1;
				}
				pid_t pid;
				pid = fork();
				if ( pid < 0 )  // check fault
				{
					printf("Fork() failed. \n");
				}
				else if( pid == 0 ) // child process to execute the command
				{
					exec_cmd(cmd);
				}
				else   // parent process
				{
					int status;
					if( block == 1)  //blocking to wait for the children
					{	
						wait( &status );
					}
					else        // Noblocking 
					{
						printf("[process running in background with pid %d]\n", pid );
						{
							sleep(0.5);
							signal( SIGCHLD, handler);
							block = 1;				
						}
					}
				}
			}
			}
			printf( "---| ");
			deletes();
			argc = 0;
			bzero( command, 100 );
			bzero( cmd, 100 );
		}
	}
	return 0;
}

/**********************************End of Main Function***************************************************/

char * exec_Ah(char *cmd)//Parse cmd with a '!'
{
    //printf("We are in exec_Ah!\n");
    char str[100];
    strcpy(str,cmd);
    int i;
    int length=0;
    int found=0;
    for(i=0;str[i]!='\0';i++) 
         str[i]=str[i+1];
    str[i]=str[i+1];//The Plaint Symbol "!" Deleted

    length=strlen(cmd)-1;
    for(i=0;i<history_cnt;i++)//Search one by one
        {
        //printf("%d",i);
        if(!strncmp(str,History[i],length))
            {
            //printf("FOUND%d!",i);
            found=1;
            strcpy(str,History[i]);//Found the 1st, exec this one!
            //puts(str);
            printf("EXECUTING COMMAND:%s\n",str);
            strcpy(cmd,str);
            //exec_cmd(History[i]);
            break;
            }
        }
   if(!found)   
    {
        printf("Error:no command with '%s' prefix in history!\n",str);
        return " ";
    }
    else
    {
        return cmd;
    }

}
//WHY command is char const??????
void cmdline_to_argv( char  *command )  //Translation the cmdline to the groupof arguments
{
	int i = 0;
	char temp[CMDLENGTH];
	bzero( temp, CMDLENGTH );
    if(command[0]=='!')
    {
    //printf("This is to search!\n");
    command=exec_Ah(command);
    }
//if(strcmp(command,'\n'))
//{
	while( *command != '\0')
	{
		if ( *command == ' ') {
			if( paras[i] == NULL )
			paras[i] = ( char *) malloc( strlen(temp) * sizeof(char) + 1 );
			strcpy( paras[i], temp );
			bzero(temp, CMDLENGTH);
			i++;
		}
		else{
			strncat(temp, command, 1);
		}
	command++;
	}
	paras[i] = (char * ) malloc( strlen( temp )* sizeof( char) + 1);
	strcpy( paras[i], temp);
	argc = i;
//}
//else
//    printf("Error Occured.\n");
}

void analyze_thepath( char *MYPATH) // analyze_thepath() analyze MYPATH for further sesearch
{
    if(!strcmp(MYPATH,"/bin:."))
    {
        printf("FUCK!");
	    char *temp = (char *) malloc ( 100*sizeof( char ) );
	    bzero( temp, 100 );
        puts(MYPATH);
	    temp = strtok( MYPATH, ":");
	    int i = 0;
	    while ( temp != NULL )
	    {
		    if( mypaths[i] == NULL )
		    mypaths[i] = ( char * ) malloc( 100* sizeof( char ) );
		    strcpy( mypaths[i], temp );
		    temp = strtok( NULL, ":" );
	    }
    }
    else
    {
        mypaths[0]="/bin";
        mypaths[1]=".";
    }
}



int valid_cmd(char *cmd ) // if the cnd exist in the PATHs
{
	int i;
    int j;//to show history in the loop
	char * temppath = ( char * ) malloc ( 100*sizeof(char));
	bzero( temppath, 100);
	struct stat filebuf;
	for( i=0 ; mypaths[i] != NULL ; i++ )
	{
		strcpy( temppath, mypaths[i]);
		strncat( temppath, "/", 1);
		strncat( temppath, cmd , strlen(cmd) );
		int rc;
		rc = stat( temppath , &filebuf );
		if( rc==0 )
		{
			strcpy( cmd, temppath );
			return 0;
		}
        else if(!strcmp(cmd,"history"))///SHOW HISTORY!
        {
            //printf("This is history!\n");
            for(j=0;j<history_cnt;j++)
            printf("%03d  %s\n",j+1,History[j]);
            return 0;
        }
            else if(cmd[0]=='!')// THIS iS to exec with !
                 {
                    exec_Ah(cmd);
                    return 0;
                 }
        
	}
	printf("ERROR: command \'%s\' not found.\n", cmd );
	return 1;
}


int exec_cmd(char *cmd) //command core 
{
	int rc;
	char *pathname = ( char *) malloc ( 100 * sizeof( char ));
	int fdout;
	int fdin;

	if( argc > 1 && (strcmp( paras[argc-1], "==>") == 0|| strcmp( paras[argc -1], "-->") == 0 || strcmp( paras[argc-1],"<==" ) == 0 )) // input or output redirection
	{
		strcpy( pathname, "./");
		strcat( pathname, paras[ argc ]);
		if(strcmp( paras[argc-1], "<==") == 0 ) // <==
		{
			fdin = open( pathname, O_RDONLY|O_CREAT,0660);
           //puts(pathname);
			dup2( fdin, 0 );
			close( fdin);
		}
		else
		{
			if(strcmp( paras[argc-1], "==>") == 0 ) //==>
			{
				fdout = open( pathname, O_WRONLY|O_CREAT, S_IRUSR| S_IRGRP| S_IWGRP| S_IWUSR);
			}
			else  
			{
            if((access(pathname,F_OK))==-1)
            printf("ERROR:no such file to append to (%s)\n",paras[argc]); 
            fdout = open( pathname, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR| S_IRGRP| S_IWGRP| S_IWUSR);
			}
			dup2( fdout, 1);
			close( fdout );
		}
		paras[argc] = NULL; //	
		free( paras[argc]);
		argc--;
		paras[argc] = NULL;
		free( paras[argc] );
		argc--;
		rc = execve( cmd , paras, mypaths );
		free( pathname );
	}
	else   //ordinary command
	{
		rc = execve( cmd, paras, mypaths );
	}
	if( rc< 0 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void handler( int sig )
{
	wait( NULL);
}


int changedir( char *dir ) // use in cd
{
	char *name = ( char *) malloc ( 100 * sizeof( char ) );
	int rc;
	if ( *dir == '/') // 
	{
		rc = chdir( dir );
	}
	else //if ( *dir == '~')  // home directory
	//{
	//	chdir( getenv("HOME") );
	//}
	//else // current directory
	{
		strcpy( name, "./");
		strcat(name, dir );
		rc = chdir(name );
	}
	free ( name );
	if ( rc ==0 )
		return 0;
	else
		return 1;
}


void deletes( )
{
	int i;
	for( i=0; paras[i] != NULL ; i++)
	{
		bzero(paras[i], strlen( paras[i] ) );
		paras[i] = NULL;
		free( paras[i]);
	}
}

void terminate()  
{
	printf("bye");
	fflush(stdout);
	kill( getpid(), SIGINT );
}


/////////////////////////END///////////////////////////////////////////
