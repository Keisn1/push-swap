#!/usr/bin/env python3
import pytest
import subprocess

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
]


@pytest.mark.parametrize("input_data,want", testdata)
def test_correct_input(input_data, want):
    process = subprocess.Popen(
        input_data,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,  # Captures both stdout and stderr
        text=True,  # Ensure output is in text mode (Python 3.7+)
    )
    process.wait()

    got = process.stdout.readline()
    assert got == want
