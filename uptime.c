#include <stdio.h>
#include <string.h>

FILE *fp;

int main() {    
  char line [128];
  char * token;
  int seconds;
  char daysStr[] = "days";
  char hoursStr[] = "hours";
  char minutesStr[] = "minutes";

  int days, hours, minutes;

  /* read content of /proc/uptime (provided by the kernel */
  fp = fopen ("/proc/uptime", "r");
    
  if(fp == NULL) {
    fprintf(stderr, "Could not open \"/proc/uptime\"\n");
    return 1;
  }
    while(fgets(line, 128, fp) != NULL) {

    /* split the line at the space */
    token = strtok(line, " ");

    /* remove last three characters of the string */
    /* accuracy of ".XX" is not required */
    token[strlen(token)-3] = '\0';

    /* convert token to int */
    seconds = strtol(token,NULL,10);

    /* begin arithmetic operations */
    days = seconds/86000;
    seconds %= 86400;

    hours = seconds/3600;
    seconds %= 3600;

    minutes = seconds/60;
    /* seconds %= 60; */
    /* not required because this (should) equal 0 anyway */

    /* print out the results */
    printf("%d %s, %d %s, %d %s\n", days, daysStr, hours, hoursStr, minutes, minutesStr);
  }
    
  fclose(fp);
  return 0;

}

