#!/bin/bash

inp_file="$1"
script_dir="$(dirname "$0")"
app_path="$script_dir/../../app.exe"

"$app_path" <"$inp_file" >temp_out.txt
exit_code=$?

rm -f temp_out.txt

if [ $exit_code -eq 0 ]; then
    exit 1
else
    exit 0
fi
