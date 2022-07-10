#ifndef __MLIB_H___
#define __MLIB_H__


#include <signal.h>
#include <unistd.h>


void unix_error(char *msg);


void Sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
    if (sigprocmask(how, set, oldset) < 0)
	unix_error("Sigprocmask error");
    return;
}

void Sigemptyset(sigset_t *set)
{
    if (sigemptyset(set) < 0)
	unix_error("Sigemptyset error");
    return;
}

void Sigfillset(sigset_t *set)
{ 
    if (sigfillset(set) < 0)
	unix_error("Sigfillset error");
    return;
}

void Sigaddset(sigset_t *set, int signum)
{
    if (sigaddset(set, signum) < 0)
	unix_error("Sigaddset error");
    return;
}

void Sigdelset(sigset_t *set, int signum)
{
    if (sigdelset(set, signum) < 0)
	unix_error("Sigdelset error");
    return;
}

int Sigismember(const sigset_t *set, int signum)
{
    int rc;
    if ((rc = sigismember(set, signum)) < 0)
	unix_error("Sigismember error");
    return rc;
}

int Sigsuspend(const sigset_t *set)
{
    int rc = sigsuspend(set); /* always returns -1 */
    if (errno != EINTR)
        unix_error("Sigsuspend error");
    return rc;
}


static void sio_reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* sio_ltoa - Convert long to base b string (from K&R) */
static void sio_ltoa(long v, char s[], int b) 
{
    int c, i = 0;
    int neg = v < 0;

    if (neg)
	v = -v;

    do {  
        s[i++] = ((c = (v % b)) < 10)  ?  c + '0' : c - 10 + 'a';
    } while ((v /= b) > 0);

    if (neg)
	s[i++] = '-';

    s[i] = '\0';
    sio_reverse(s);
}

/* sio_strlen - Return length of string (from K&R) */
static size_t sio_strlen(char s[])
{
    int i = 0;

    while (s[i] != '\0')
        ++i;
    return i;
}


ssize_t sio_puts(char s[]) /* Put string */
{
    return write(STDOUT_FILENO, s, sio_strlen(s)); //line:csapp:siostrlen
}

ssize_t sio_putl(long v) /* Put long */
{
    char s[128];
    
    sio_ltoa(v, s, 10); /* Based on K&R itoa() */  //line:csapp:sioltoa
    return sio_puts(s);
}

void sio_error(char s[]) /* Put error message and exit */
{
    sio_puts(s);
    _exit(1);                                      //line:csapp:sioexit
}

ssize_t Sio_putl(long v)
{
    ssize_t n;
  
    if ((n = sio_putl(v)) < 0)
	sio_error("Sio_putl error");
    return n;
}

ssize_t Sio_puts(char s[])
{
    ssize_t n;
  
    if ((n = sio_puts(s)) < 0)
	sio_error("Sio_puts error");
    return n;
}

void Sio_error(char s[])
{
    sio_error(s);
}

pid_t Fork(){
  pid_t pid;

  if ((pid = fork()) < 0){
    unix_error("fork error");
    exit(1);
  }
  return pid;
}


void Kill(pid_t pid, int signum) 
{
    int rc;

    if ((rc = kill(pid, signum)) < 0)
	unix_error("Kill error");
}

#endif //__MLIB_H__