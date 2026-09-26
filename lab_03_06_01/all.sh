#!/bin/bash

fail=0

./clean.sh
./build_debug.sh && ./func_tests/scripts/func_tests.sh || fail=1

./clean.sh
./build_release.sh && ./func_tests/scripts/func_tests.sh || fail=1

./clean.sh
./build_debug_asan.sh && ./func_tests/scripts/func_tests.sh || fail=1

./clean.sh
./build_debug_msan.sh && ./func_tests/scripts/func_tests.sh || fail=1

./clean.sh
./build_debug_ubsan.sh && ./func_tests/scripts/func_tests.sh || fail=1

exit $fail
