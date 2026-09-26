#!/bin/bash

script_dir="$(dirname "$0")"
data_path="$script_dir/../data"

passed_pos=0
failed_pos=0
passed_neg=0
failed_neg=0

test_n=1
while [ -f "$data_path/pos_$(printf "%02d" $test_n)_in.txt" ]; do
    test_num=$(printf "%02d" $test_n)
    in_file="$data_path/pos_${test_num}_in.txt"
    out_file="$data_path/pos_${test_num}_out.txt"

    if "$script_dir/pos_case.sh" "$in_file" "$out_file"; then
        passed_pos=$((passed_pos + 1))
    else
        failed_pos=$((failed_pos + 1))
    fi

    test_n=$((test_n + 1))
done

test_n=1
while [ -f "$data_path/neg_$(printf "%02d" $test_n)_in.txt" ]; do
    test_num=$(printf "%02d" $test_n)
    in_file="$data_path/neg_${test_num}_in.txt"

    if "$script_dir/neg_case.sh" "$in_file"; then
        passed_neg=$((passed_neg + 1))
    else
        failed_neg=$((failed_neg + 1))
    fi

    test_n=$((test_n + 1))
done

total_pos=$((passed_pos + failed_pos))
total_neg=$((passed_neg + failed_neg))
echo "Positive tests: $passed_pos/$total_pos PASSED"
echo "Negative tests: $passed_neg/$total_neg PASSED"

exit $((failed_pos + failed_neg))
