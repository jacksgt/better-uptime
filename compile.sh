#!/bin/bash

# Compile script for better-uptime
OUTPUT_NAME="better-uptime";

gcc uptime.c -o "$OUTPUT_NAME";

chmod +x "$OUTPUT_NAME";
