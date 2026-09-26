#!/bin/bash

inp_file="$1"
exp_file="$2"
script_dir="$(dirname "$0")"
app_path="$script_dir/../../app.exe"

"$app_path" <"$inp_file" >temp_out.txt
exit_code=$?

if [ $exit_code -ne 0 ]; then
    rm -f temp_out.txt
    exit 1
fi

"$script_dir/comparator.sh" temp_out.txt "$exp_file"
res=$?

rm -f temp_out.txt
exit $res
