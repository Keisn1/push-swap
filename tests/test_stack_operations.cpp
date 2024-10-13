#include <gtest/gtest.h>
#include <unistd.h>
#include <vector>
#include "libft.h"
#include "operations.h"
#include "push_swap.h"

struct StackOperationInput {
	std::string op;
	t_state state;
	t_state want_state;
};


class StackOperationTest : public testing::TestWithParam<StackOperationInput> {};

void print_stack(t_stack *a) {
	while (a) {
		ft_putnbr_fd(*(int*)a->content, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		a = a->next;
	}
}

void assert_equal_stack(t_stack *got, t_stack *want) {
    while (got != NULL && want != NULL) {
		ASSERT_EQ(*(int*)got->content, *(int*)want->content);
		got = got->next;
		want = want->next;
	}
	ASSERT_EQ(got, want);
}


void assert_equal_state(t_state got, t_state want) {
	assert_equal_stack(got.a, want.a);
	assert_equal_stack(got.b, want.b);
}

void	ft_lstclear_wo_del(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	head = *lst;
	if (!head)
		return ;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*lst = NULL;
}

void clear_stacks(t_state got, t_state want) {
	ft_lstclear_wo_del(&got.a);
	ft_lstclear_wo_del(&got.b);
	ft_lstclear_wo_del(&want.a);
	ft_lstclear_wo_del(&want.b);
}

TEST_P(StackOperationTest, first_test) {
    StackOperationInput param = GetParam();

	t_state got_state;
    if (param.op == "sa")
		got_state = swap_a(param.state);

	assert_equal_state(got_state, param.want_state);

	clear_stacks(got_state,param.want_state);
}

t_stack *create_stack(std::vector<int> nbrs) {
	if (nbrs.size() == 0)
		return NULL;

	t_stack *stack = ft_lstnew(&nbrs[0]);
	for (size_t i = 1; i < nbrs.size(); ++i) {
		ft_lstadd_back(&stack, ft_lstnew(&nbrs[i]));
	}
	return stack;
}

StackOperationInput create_stack_operation_input(std::string op,
                                                 std::vector<int> a,
												 std::vector<int> b,
												 std::vector<int> want_a,
												 std::vector<int> want_b) {
	t_state state = {.a = create_stack(a), .b = create_stack(b)};
	t_state want_state = {.a = create_stack(want_a), .b = create_stack(want_b)};
	StackOperationInput input{op, state, want_state};
	return input;

}

INSTANTIATE_TEST_SUITE_P(
    StackOperationTests,
    StackOperationTest,
    ::testing::Values(
        create_stack_operation_input("sa",{1, 2}, {}, {2, 1}, {})
        )
    );
