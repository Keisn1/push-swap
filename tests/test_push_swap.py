import pytest
import subprocess

testdata = [
    (["./push_swap", "1", "2"], ""),
    (["./push_swap", "2", "1"], "sa\n"),
    (["./push_swap", "2 1"], "sa\n"),
    (["./push_swap", "2", "3", "1"], "rra\n"),
    (["./push_swap", "2 3 1"], "rra\n"),
    (["./push_swap", "3 1 2"], "ra\n"),
    (["./push_swap"], ""),
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
    (["./push_swap", "asdf"], "Error\n"),
    (["./push_swap", "12349871239487 1"], "Error\n"),
    (["./push_swap", "–2147483649 1"], "Error\n"),
    (["./push_swap", "2147483648 1"], "Error\n"),
    (["./push_swap", "+2147483648 1"], "Error\n"),
    (["./push_swap", "2 +2147483648 1"], "Error\n"),
    (["./push_swap", "+2147483647 1"], "sa\n"),
    (["./push_swap", "2", "+2147483648", "1"], "Error\n"),
    (["./push_swap", "2", "+2147483647", "1"], "rra\n"),
    (["./push_swap", "1 2 3 4 5 6 7 8 9 10"], ""),
    (["./push_swap", "2 +"], "Error\n"),
    (["./push_swap", "2", "+"], "Error\n"),
    (["./push_swap", "2", "+3"], ""),
    (["./push_swap", "2", "+ 3"], "Error\n"),
    (["./push_swap", "2 + 3"], "Error\n"),
    (["./push_swap", "2 - 3"], "Error\n"),
    (["./push_swap", "2  3"], ""),
    (["./push_swap", " 2  -3"], "sa\n"),
]


@pytest.mark.parametrize("input,want", testdata)
def test_push_swap(input, want):
    process = subprocess.Popen(
        input,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,  # Captures both stdout and stderr
        text=True,  # Ensure output is in text mode (Python 3.7+)
    )
    process.wait()

    got = process.stdout.readline()
    assert got == want


@pytest.mark.parametrize("input,want", testdata)
def test_push_swap_valgrind(input, want):
    input = ["valgrind", "--leak-check=full"] + input

    process = subprocess.Popen(
        input,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,  # Captures both stdout and stderr
        text=True,  # Ensure output is in text mode (Python 3.7+)
    )
    process.wait()

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
