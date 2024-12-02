import pytest
import subprocess

testdata = [
    (["./push_swap", "1", "2"], ""),
    (["./push_swap", "2", "1"], "sa\n"),
    (["./push_swap", "2 1"], "sa\n"),
    (["./push_swap", "2", "3", "1"], "rra\n"),
    (["./push_swap", "2 3 1"], "rra\n"),
    (["./push_swap", "3 1 2"], "ra\n"),
    (["./push_swap"], "Error\n"),
    (["./push_swap", "1 2 asdf"], "Error\n"),
    (["./push_swap", "-1 2"], ""),
    (["./push_swap", "+1 2"], ""),
    (["./push_swap", "+1", "asdf2"], "Error\n"),
    (["./push_swap", "1", "1"], "Error\n"),
    (["./push_swap", "2", "2"], "Error\n"),
    (["./push_swap", "2", "2"], "Error\n"),
    (["./push_swap", "2", "2", "2"], "Error\n"),
    (["./push_swap", "1", "2", "2"], "Error\n"),
    (["./push_swap", "2", "1", "2"], "Error\n"),
    (["./push_swap", "2", "2", "1"], "Error\n"),
    (["./push_swap", "1", "2", "3", "4", "1"], "Error\n"),
]


@pytest.mark.parametrize("input,want", testdata)
def test_correct_input(input, want):
    process = subprocess.Popen(
        input,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,  # Captures both stdout and stderr
        text=True,  # Ensure output is in text mode (Python 3.7+)
    )
    process.wait()

    got = process.stdout.readline()
    assert got == want
