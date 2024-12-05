#!/usr/bin/env python3
import pytest
import subprocess


testdata = [
    (["./checker"], [""], ""),
    (["./checker", "+1", "asdf2"], [""], "Error\n"),
    (["./checker", "1", "1"], [""], "Error\n"),
    (["./checker", "2", "2"], [""], "Error\n"),
    (["./checker", "2", "2"], [""], "Error\n"),
    (["./checker", "2", "2", "2"], [""], "Error\n"),
    (["./checker", "1", "2", "2"], [""], "Error\n"),
    (["./checker", "2", "1", "2"], [""], "Error\n"),
    (["./checker", "2", "2", "1"], [""], "Error\n"),
    (["./checker", "1", "2", "3", "4", "1"], [""], "Error\n"),
    (["./checker", "1 2 asdf"], [""], "Error\n"),
    (["./checker", "asdf"], [""], "Error\n"),
    (["./checker", "12349871239487 1"], [""], "Error\n"),
    (["./checker", "–2147483649 1"], [""], "Error\n"),
    (["./checker", "2147483648 1"], [""], "Error\n"),
    (["./checker", "+2147483648 1"], [""], "Error\n"),
    (["./checker", "2 +2147483648 1"], [""], "Error\n"),
    (["./checker", "2", "+2147483648", "1"], [""], "Error\n"),
    (["./checker", "1 2"], [""], "OK\n"),  # tests if everything is free on happy path
    (["./checker", "2", "1"], [""], "KO\n"),
    (["./checker", "2 1"], [""], "KO\n"),
    (["./checker", "1", "2"], [""], "OK\n"),
    (["./checker", "1", "2"], ["sa "], "Error\n"),
    (["./checker", "1", "2"], ["sa"], "KO\n"),
    (["./checker", "2", "1"], ["sa"], "OK\n"),
    (["./checker", "2", "1"], ["ra"], "OK\n"),
    (["./checker", "1", "2"], ["ra"], "KO\n"),
    (["./checker", "1", "2"], ["ra"], "KO\n"),
    (["./checker", "1", "2"], ["sa", "ra "], "Error\n"),
    (["./checker", "1", "2"], ["sa", "ra"], "OK\n"),
    (["./checker", "4", "3", "1", "2"], ["sa", "ra", "ra"], "OK\n"),
    (["./checker", "4", "3", "5", "1", "2"], ["sa", "ra", "ra", "ra"], "OK\n"),
    (["./checker", "4", "3", "5", "1", "2"], ["sa", "rra", "rra"], "OK\n"),
    (["./checker", "1", "2"], ["pb", "pa"], "OK\n"),
    (["./checker", "1", "2"], ["pbasdf", "pa"], "Error\n"),
    (["./checker", "1", "2"], ["rrb"], "OK\n"),
    (["./checker", "3", "1", "2"], ["rr"], "OK\n"),
    (["./checker", "2", "3", "1"], ["rrr"], "OK\n"),
    (["./checker", "2", "3", "1"], ["rrx"], "Error\n"),
    (
        ["./checker", "2 4 5 8 6 7"],
        [
            "pb",
            "pb",
            "pb",
            "pb",
            "rb",
            "pb",
            "pb",
            "rrb",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
        ],
        "OK\n",
    ),
    (
        ["./checker", "2" "4" "5" "8" "6" "7"],
        [
            "pb",
            "pb",
            "pb",
            "pb",
            "rb",
            "pb",
            "pb",
            "rrb",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
        ],
        "OK\n",
    ),
    (
        ["./checker", "2" "4" "5" "8" "6" "7"],
        [
            "pb",
            "pb",
            "pb",
            "pb",
            "rb",
            "pb",
            "pb",
            "rrb",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
        ],
        "OK\n",
    ),
    (
        ["./checker", "18 16 7 6 10 9 12 2 0 19 11 1 13 17 8 4 5 15 3 14"],
        [
            "pb",
            "pb",
            "rb",
            "pb",
            "rb",
            "pb",
            "rrb",
            "pb",
            "rb",
            "pb",
            "rrb",
            "pb",
            "rra",
            "pb",
            "rrb",
            "rrb",
            "pb",
            "rb",
            "pb",
            "rb",
            "pb",
            "ra",
            "rrb",
            "pb",
            "rrr",
            "rra",
            "pb",
            "rra",
            "rra",
            "pb",
            "rra",
            "rb",
            "pb",
            "rrr",
            "rrb",
            "rrb",
            "pb",
            "ra",
            "rrb",
            "rrb",
            "pb",
            "rrb",
            "pb",
            "rrb",
            "rrb",
            "pb",
            "rb",
            "rb",
            "pb",
            "rrb",
            "rrb",
            "rrb",
            "rrb",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
            "pa",
        ],
        "OK\n",
    ),
]


@pytest.mark.parametrize("input_data,operations,want", testdata)
def test_checker(input_data, operations, want):
    ops_string = "\n".join(operations)
    if len(ops_string):
        ops_string += "\n"

    process = subprocess.Popen(
        input_data,
        stdout=subprocess.PIPE,
        stdin=subprocess.PIPE,
        stderr=subprocess.STDOUT,  # Captures both stdout and stderr
        text=True,  # Ensure output is in text mode (Python 3.7+)
    )
    try:
        got, _ = process.communicate(ops_string, timeout=1)
    except subprocess.TimeoutExpired:
        process.kill()
        got, _ = process.communicate()

    assert got == want


@pytest.mark.parametrize("input_data,operations,want", testdata)
def test_checker_valgrind(input_data, operations, want):
    input_data = ["valgrind", "--leak-check=full"] + input_data
    ops_string = "\n".join(operations) + "\n"

    process = subprocess.Popen(
        input_data,
        stdout=subprocess.PIPE,
        stdin=subprocess.PIPE,
        stderr=subprocess.STDOUT,  # Captures both stdout and stderr
        text=True,  # Ensure output is in text mode (Python 3.7+)
    )
    try:
        got, _ = process.communicate(ops_string, timeout=1)
    except subprocess.TimeoutExpired:
        process.kill()
        got, _ = process.communicate()

    assert "All heap blocks were freed -- no leaks are possible" in got
    assert "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" in got
    assert want in got
