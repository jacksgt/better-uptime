#include <stdio.h>
#include <string.h>

FILE *fp;

int main() {    
  char line [128];
  char * token;
  int seconds;

  int days, hours, minutes;

  fp = fopen ("/proc/uptime", "r");
    
  if(fp == NULL) {
    fprintf(stderr, "Could not open \"/proc/uptime\"\n");
    return 1;
  }
}

