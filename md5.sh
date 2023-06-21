#!/bin/bash

read -p "Enter the text to generate MD5 hash: " input_text

md5_hash=$(echo -n "$input_text" | md5sum | awk '{print $1}')

echo "MD5 hash of '$input_text': $md5_hash"