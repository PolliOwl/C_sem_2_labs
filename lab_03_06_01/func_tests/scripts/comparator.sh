#!/bin/bash

file1="$1"
file2="$2"

nums1=$(grep -Eo '[+-]?[0-9]+([.][0-9]*)?' "$file1")
nums2=$(grep -Eo '[+-]?[0-9]+([.][0-9]*)?' "$file2")

if [ "$nums1" = "$nums2" ]; then
    exit 0
else
    exit 1
fi
