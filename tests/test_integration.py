import pytest
import subprocess


def test_error_input():
    process = subprocess.Popen(
        ["./push_swap"],
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,  # Captures both stdout and stderr
        text=True,  # Ensure output is in text mode (Python 3.7+)
    )
    process.wait()

    output = process.stdout.readline()
    assert output == "Error\n"


testdata = [
    (["./push_swap", "1", "2"], ""),
    (["./push_swap", "2", "1"], "sa\n"),
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
