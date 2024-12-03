#!/usr/bin/env python3
import pytest
import subprocess


testdata = [
    (["./checker", "1", "2"], [""], "OK\n"),
    (["./checker", "2", "1"], [""], "KO\n"),
    (["./checker", "2", "1"], ["sa\n"], "OK\n"),
]


@pytest.mark.parametrize("input_data,operations,want", testdata)
def test_checker(input_data, operations, want):

    ops_string = "\n".join(operations) + "\n"

    process = subprocess.Popen(
        input_data,
        stdout=subprocess.PIPE,
        stdin=subprocess.PIPE,
        stderr=subprocess.STDOUT,  # Captures both stdout and stderr
        text=True,  # Ensure output is in text mode (Python 3.7+)
    )
    try:
        out, errs = process.communicate(ops_string, timeout=1)
    except subprocess.TimeoutExpired:
        process.kill()
        out, errs = process.communicate()

    assert out == want


testdata = [
    (["./checker"], "Error\n"),
    (["./checker", "+1", "asdf2"], "Error\n"),
    (["./checker", "1", "1"], "Error\n"),
    (["./checker", "2", "2"], "Error\n"),
    (["./checker", "2", "2"], "Error\n"),
    (["./checker", "2", "2", "2"], "Error\n"),
    (["./checker", "1", "2", "2"], "Error\n"),
    (["./checker", "2", "1", "2"], "Error\n"),
    (["./checker", "2", "2", "1"], "Error\n"),
    (["./checker", "1", "2", "3", "4", "1"], "Error\n"),
    (["./checker", "1 2 asdf"], "Error\n"),
    (["./checker", "asdf"], "Error\n"),
    (["./checker", "12349871239487 1"], "Error\n"),
    (["./checker", "–2147483649 1"], "Error\n"),
    (["./checker", "2147483648 1"], "Error\n"),
    (["./checker", "+2147483648 1"], "Error\n"),
    (["./checker", "2 +2147483648 1"], "Error\n"),
    (["./checker", "2", "+2147483648", "1"], "Error\n"),
    (["./checker", "1 2"], ""),  # tests if everything is free on happy path
]


@pytest.mark.parametrize("input,want", testdata)
def test_checker_valgrind(input, want):
    input = ["valgrind", "--leak-check=full"] + input

    process = subprocess.Popen(
        input,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,  # Captures both stdout and stderr
        text=True,  # Ensure output is in text mode (Python 3.7+)
    )
    process.wait()

    assert process.stdout is not None
    got = process.stdout.readlines()

    assert any(
        ["All heap blocks were freed -- no leaks are possible" in line for line in got]
    )
    assert any(
        [
            "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" in line
            for line in got
        ]
    )
